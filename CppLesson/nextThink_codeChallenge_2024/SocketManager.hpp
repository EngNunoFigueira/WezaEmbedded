#ifndef SOCKETMANAGER
#define SOCKETMANAGER

#ifdef _WIN32
#include <Ws2tcpip.h>
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
//typedef int SOCKET;
//const int INVALID_SOCKET = 0;
//const int SOCKET_ERROR = -1;
#endif
#include <atomic>
#include <cstring>
#include <exception>
#include <functional>
#include <iostream>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/x509.h>
#include <openssl/pkcs12.h>
#include <string>
#include <unordered_map>
#include "SocketTcpIp.hpp"

namespace sktTcpIp {

/**
 * The maximum size of the communication buffer is 4096 bytes.
 */
//const int BUFF_SIZE = 4096;

/**
 * These are the error checking functions used to manager the TCP/IP Server and
 * Client communication.
 
struct socket_error_exception : public std::exception {
  const char *what() const throw() { return "Can't start socket!"; }
};
struct invalid_socket_exception : public std::exception {
  const char *what() const throw() { return "Can't create a socket!"; }
};
struct data_size_exception : public std::exception {
  const char *what() const throw() {
    return "Data size is above the maximum allowed by the buffer";
  }
};
 */
class SocketManager {

public:
  SOCKET startServer(const std::string &channelName, int port,
                   std::function<void(const std::string &data)> callback) {

    if (sockInit() != 0) {
      throw sktTcpIp::socket_error_exception();
    }

    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET || listening == SOCKET_ERROR) {
      throw sktTcpIp::socket_error_exception();
    }
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
#ifdef _WIN32
    hint.sin_addr.S_un.S_addr = INADDR_ANY;
#else
    hint.sin_addr.s_addr = INADDR_ANY;
#endif
    bind(listening, (sockaddr *)&hint, sizeof(hint));
    listen(listening, SOMAXCONN);
    sockaddr_in client;
#ifdef _WIN32
    int clientSize = sizeof(client);
#else
    unsigned int clientSize = sizeof(client);
#endif
    SOCKET clientSocket = accept(listening, (sockaddr *)&client, &clientSize);
    server_sockets[channelName] = clientSocket;
    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
    if (getnameinfo((sockaddr *)&client, sizeof(client), host, NI_MAXHOST,
                    service, NI_MAXSERV, 0) == 0) {
      std::cout << host << " connected on port " << service << std::endl;
    } else {
      inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
      std::cout << host << " connected on port " << ntohs(client.sin_port)
                << std::endl;
    }
    /*
    std::string data{"Nuno From Server side"};
    while (true) {
      //secSocketReceive(ssl,  buff, callback);
      //SSL_write(ssl, data.c_str(), data.size() + 1);
      socketReceive(clientSocket, buff, callback);
      send(clientSocket, data.c_str(), data.size() + 1, 0);
      std::cout << "Waitng another connection from client" << std::endl;
    }
    sockClose(clientSocket);
    sockQuit();
    */

    return clientSocket;
  }

  void socketSend(const std::string &channelName, const std::string &data) {
    if (data.size() > BUFF_SIZE) {
      throw sktTcpIp::data_size_exception();
    }
    if (client_sockets.find(channelName) != client_sockets.end()) {
      SOCKET sock = client_sockets.at(channelName);
      int sendResult = send(sock, data.c_str(), data.size() + 1, 0);
      if (sendResult == SOCKET_ERROR) {
        throw sktTcpIp::socket_error_exception();
      }
    }
  }

  SOCKET socketConnect(const std::string &channelName, const std::string &ip,
                     std::uint16_t port) {
    if (sockInit() != 0) {
      throw sktTcpIp::socket_error_exception();
      std::cout<<"The gate is close"<<std::endl;
      return -1;
    }
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET || sock == SOCKET_ERROR) {
      std::cout<<"Call  sockQuit()"<<std::endl;
      sockQuit();
      throw sktTcpIp::socket_error_exception();
    }
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);
    int connResult = connect(sock, (sockaddr *)&hint, sizeof(hint));
    if (connResult == SOCKET_ERROR) {
      std::cout<<"Call  SOCKET_ERROR"<<std::endl;
      sockClose(sock);
      sockQuit();
      throw sktTcpIp::socket_error_exception();
    }
    client_sockets[channelName] = sock;
    std::cout<<"Socket is clean "<< sock<<std::endl;
    return sock;
  }

  void closeConnection(const std::string &channelName) {
    if (client_sockets.find(channelName) != client_sockets.end()) {
      SOCKET s = client_sockets.at(channelName);
      sockClose(s);
      sockQuit();
    }
  }

  void socketReceive(SOCKET clientSocket, char buff[],
                     std::function<void(const std::string &data)> callback) {
    int bytesReceived = recv(clientSocket, buff, BUFF_SIZE, 0);
    if (bytesReceived == SOCKET_ERROR) {
      throw sktTcpIp::socket_error_exception();
    }
    if (bytesReceived > BUFF_SIZE) {
      throw sktTcpIp::data_size_exception();
    }
    if (bytesReceived > 0) {
      callback(std::string(buff, 0, bytesReceived));
    } else {
      return;
    }
  }

  void socketReceive(const std::string &channelName,
                     std::function<void(const std::string &data)> callback) {
    if (client_sockets.find(channelName) != client_sockets.end()) {
      SOCKET sock = client_sockets.at(channelName);
      int bytesReceived = recv(sock, buff, BUFF_SIZE, 0);
      if (bytesReceived == SOCKET_ERROR) {
        throw sktTcpIp::socket_error_exception();
      }
      if (bytesReceived > BUFF_SIZE) {
        throw sktTcpIp::data_size_exception();
      }
      if (bytesReceived > 0) {
        callback(std::string(buff, 0, bytesReceived));
      } else {
        return;
      }
    }
  }

private:
  char buff[BUFF_SIZE];
  char host[NI_MAXHOST];
  char service[NI_MAXSERV];
  std::unordered_map<std::string, SOCKET> client_sockets;
  std::unordered_map<std::string, SOCKET> server_sockets;

  int sockInit(void) {
#ifdef _WIN32
    WSADATA wsa_data;
    return WSAStartup(MAKEWORD(1, 1), &wsa_data);
#else
    return 0;
#endif
  }

  int sockQuit(void) {
#ifdef _WIN32
    return WSACleanup();
#else
    return 0;
#endif
  }
  int sockClose(SOCKET sock) {

    int status = 0;

#ifdef _WIN32
    status = shutdown(sock, SD_BOTH);
    if (status == 0) {
      status = closesocket(sock);
    }
#else
    status = shutdown(sock, SHUT_RDWR);
    if (status == 0) {
      status = close(sock);
    }
#endif

    return status;
  }
};
} // namespace SOCKETMANAGER
#endif
