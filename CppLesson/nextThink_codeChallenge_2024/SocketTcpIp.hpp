#ifndef SOCKETTCPIP
#define SOCKETTCPIP

#ifdef _WIN32
#include <Ws2tcpip.h>
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
typedef int SOCKET;
const int INVALID_SOCKET = 0;
const int SOCKET_ERROR = -1;
#endif
#include "SocketTcpIp.hpp"
#include <atomic>
#include <cstring>
#include <exception>
#include <functional>
#include <iostream>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/pkcs12.h>
#include <openssl/ssl.h>
#include <openssl/x509.h>
#include <string>
#include <unordered_map>

namespace sktTcpIp {

/**
 * The maximum size of the communication buffer is 4096 bytes.
 */
const int BUFF_SIZE = 4096;

/**
 * These are the error checking functions used to manager the TCP/IP Server and
 * Client communication.
 */
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

class SocketTcpIp {

public:
  void startServer(const std::string &channelName, int port,
                   std::function<void(const std::string &data)> callback) {
    /**
     * Basic socket configuration for the server side using TCP/IP
     * communication. The connection will be encrypted.
     */
    if (sockInit() != 0) {
      throw sktTcpIp::socket_error_exception();
    }

    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET || listening == SOCKET_ERROR) {
      throw sktTcpIp::socket_error_exception();
    }
    std::cout << "LINE 71" << std::endl;
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

    /**
     * These are the server side Secure Socket Layer configuration for TCP/IP
     * encrypted connection.
     */

    SSL_CTX *m_ctx = SSL_CTX_new(SSLv23_server_method());
    if (!getCertificatAndPrivateKey(cert, pkey)) {
      throw sktTcpIp::socket_error_exception();
    }
    std::cout << "LINE 250" << std::endl;
    SSL_CTX_use_certificate(m_ctx, cert);
    SSL_CTX_use_PrivateKey(m_ctx, pkey);
    SSL *ssl = SSL_new(m_ctx);
    std::cout << "LINE 251" << std::endl;

    int retry{0}, sslAcceptResult{0};
    SSL_set_fd(ssl, clientSocket);
    do {
      sslAcceptResult = SSL_accept(ssl);
      if (sslAcceptResult < 0) {
        std::cout << "Error accepting SSL connection on server side"
                  << std::endl;
        std::cout << "SSL ERROR SPECIFICATION "
                  << SSL_get_error(ssl, sslAcceptResult) << std::endl;
        switch (SSL_get_error(ssl, sslAcceptResult)) {
        case SSL_ERROR_SSL:
          std::cout << "SSL ERROR SSL" << std::endl;
          break;
        case SSL_ERROR_SYSCALL:
          std::cout << "SSL ERROR SYSCALL" << std::endl;
          break;
        case SSL_ERROR_WANT_ASYNC_JOB:
          std::cout << "SSL ERROR WANT ASYNC_LOOKUP" << std::endl;
          break;
        case SSL_ERROR_WANT_ASYNC:
          std::cout << "SSL ERROR WANT X509_LOOKUP" << std::endl;
          break;
        case SSL_ERROR_WANT_X509_LOOKUP:
          std::cout << "SSL ERROR WANT X509_LOOKUP" << std::endl;
          break;
        case SSL_ERROR_WANT_WRITE:
          std::cout << "SSL ERROR WANT WRITE" << std::endl;
          break;
        case SSL_ERROR_WANT_READ:
          std::cout << "SSL ERROR WANT READ" << std::endl;
          break;
        case SSL_ERROR_ZERO_RETURN:
          std::cout << "SSL ERROR SSL_ERROR_ZERO_RETURN" << std::endl;
          break;
        case SSL_ERROR_NONE:
          break;

        default:
          break;
        }
        retry++;
      }
    } while (retry < 1);

    std::string data{"New Software 1.1.0"};
    while (true) {
      secSocketReceive(ssl, buff, callback);
      SSL_write(ssl, data.c_str(), data.size() + 1);
      // socketReceive(clientSocket, buff, callback);
      // send(clientSocket, data.c_str(), data.size() + 1, 0);
      std::cout << "Waiting another connection from client" << std::endl;
    }
    // sockClose(clientSocket);
    // sockQuit();
    SSL_shutdown(ssl);
    SSL_free(ssl);
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

  void socketConnect(const std::string &channelName, const std::string &ip,
                     std::uint16_t port,
                     std::function<void(const std::string &data)> callback) {

    if (sockInit() != 0) {
      std::cout << "Client STEP 2" << std::endl;
      throw sktTcpIp::socket_error_exception();
      return;
    }
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET || sock == SOCKET_ERROR) {
      std::cout << "Client STEP 3" << std::endl;
      sockQuit();
      throw sktTcpIp::socket_error_exception();
    }
    std::cout << "Client STEP 4" << std::endl;
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);
    int connResult = connect(sock, (sockaddr *)&hint, sizeof(hint));
    if (connResult == SOCKET_ERROR) {
      std::cout << "Client STEP 5" << std::endl;
      std::cout << "Client cannot connect to the server" << std::endl;
      sockClose(sock);
      sockQuit();
      std::cout << "Client STEP 6" << std::endl;
      throw sktTcpIp::socket_error_exception();
      std::cout << "Client STEP 7" << std::endl;
    }

    client_sockets[channelName] = sock;

    /**
     * These configurations is the Secure Socket Layer for the client side.
     * To ensure that the connection are encrypted in both sides, over tcp/ip.
     */
    SSL_CTX *m_ctx = SSL_CTX_new(SSLv23_method());
    SSL_CTX_set_verify(m_ctx, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT,
                       NULL);
    SSL_CTX_load_verify_locations(m_ctx, CAFILE.c_str(), "CA_cert/");
    SSL *m_ssl = SSL_new(m_ctx);
    std::cout << "Client STEP 1" << std::endl;

    /**
     * Starting configuring the Client side of the TCP/IP communication.
     * The connection will be encrypted.
     */
    SSL_set_fd(m_ssl, sock);
     if (SSL_connect(m_ssl) < 1) {
       std::cout << "Client SSL_connect fail" << std::endl;
       SSL_shutdown(m_ssl);
       SSL_free(m_ssl);
       return;
     }

    std::cout << "Client End Config" << std::endl;

    /*
    std::cout<<"Client STEP 9"<<std::endl;

    while(true)
    {
       std::cout<<"Client STEP 10"<<std::endl;
       secSocketReceive(m_ssl, buff, callback);
    }*/
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

  void secSocketReceive(SSL *ssl, char buff[],
                        std::function<void(const std::string &data)> callback) {
    int bytesReceived = SSL_read(ssl, buff, BUFF_SIZE);
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

  bool getCertificatAndPrivateKey(X509 *cert, EVP_PKEY *pkey) {
    BIO *in = BIO_new(BIO_s_file());
    if (!BIO_read_filename(in, (char *)CERT.c_str())) {
      BIO_free(in);
      std::cout << "Error reading the certificate" << std::endl;
      return false;
    }
    std::cout << "LINE 233" << std::endl;
    PKCS12 *p12 = d2i_PKCS12_bio(in, NULL);
    BIO_free(in);
    if (p12 == NULL) {
      std::cout << "Error the file cert.p12 is corrupted" << std::endl;
      return false;
    }
    std::cout << "LINE 240" << std::endl;
    if (PKCS12_parse(p12, password.c_str(), &pkey, &cert, &ca)) {
      std::cout << "LINE 242" << std::endl;
      PKCS12_free(p12);
      return true;
    } else {
      std::cout << "LINE 246" << std::endl;
      PKCS12_free(p12);
      std::cout << "Error cannot read the certificate" << std::endl;
      return false;
    }
  }

private:
  X509 *cert;
  EVP_PKEY *pkey;
  char buff[BUFF_SIZE];
  char host[NI_MAXHOST];
  char service[NI_MAXSERV];
  const std::string password = {"nuno"};
  STACK_OF(X509) *ca = NULL;
  const std::string CERT{"cert.p12"};
  const std::string CAFILE{"Certificate.pem"};
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
} // namespace sktTcpIp
#endif
