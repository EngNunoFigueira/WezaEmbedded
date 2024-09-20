#ifndef TCPIPOVERSSL
#define TCPIPOVERSSL

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
#include <memory>
#include "SocketTcpIp.hpp"

namespace sktTcpIp {

const int BUFFER_SIZE = 4096;

class TcpIpOverSsl {

public:
  TcpIpOverSsl(int socketFileDescriptor):
  socketFd{socketFileDescriptor}
  {
    // do nothing
  }

  void SslServerConfiguration()
  {
    /**
     * These are the Server side Secure Socket Layer configuration for TCP/IP
     * encrypted connection.
     */
   SSL_CTX *m_ctx = SSL_CTX_new(SSLv23_server_method());
    if (!getCertificatAndPrivateKey(cert, pkey)) {
      std::cout<<"throw sktTcpIp::socket_error_exception()"<<std::endl;
    }
    SSL_CTX_use_certificate(m_ctx, cert);
    SSL_CTX_use_PrivateKey(m_ctx, pkey);
    ssl = SSL_new(m_ctx);
    SSL_set_fd(ssl, socketFd);
    if((SSL_accept(ssl)) !=0)
    {
       std::cout<<"Error accepting SSL connection on server side"<<std::endl;
       return;
    }
  }

  void SslClientConfiguration()
  {
    /**
    * These configuration is the Secure Socket Layer for the client side.
    * To ensure that the connection are encrypted in both sides, over tcp/ip.
    */
    SSL_CTX *m_ctx = SSL_CTX_new(SSLv23_method());
    SSL_CTX_set_verify(m_ctx, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT,
                       NULL);
    SSL_CTX_load_verify_locations(m_ctx, CAFILE.c_str(), "CA_cert/");
    ssl = SSL_new(m_ctx);
    SSL_set_fd(ssl, socketFd);
  }

  void secSocketReceive(char buff[],
                     std::function<void(const std::string &data)> callback) {
      int bytesReceived = SSL_read(ssl, buff, BUFF_SIZE);
      if (bytesReceived == SOCKET_ERROR) {
        throw sktTcpIp::socket_error_exception();
      }
      if (bytesReceived > BUFF_SIZE) {
        //throw sktTcpIp::data_size_exception();
         std::cout<<"Error the message reiceive is out of buffer size"<<std::endl;
      }
      if (bytesReceived > 0) {
        callback(std::string(buff, 0, bytesReceived));
      } else {
        return;
      }
    }

  void secSocketSend(const std::string & data)
  {
    if (data.size() > BUFF_SIZE) {
      throw sktTcpIp::data_size_exception();
    }

    int sendResult = SSL_write(ssl, data.c_str(), data.size() + 1);
    if (sendResult == SOCKET_ERROR) {
        //throw sktTcpIp::socket_error_exception();
       std::cout<<"throw sktTcpIp::socket_error_exception()"<<std::endl;
      }
     std::cout<<"SSL ERROR SPECIFICATION "<< SSL_get_error(ssl,sendResult)<<std::endl;
     switch (SSL_get_error(ssl,sendResult))
        {
            case SSL_ERROR_SSL:
                std::cout<<"SSL ERROR SSL"<<std::endl;
                break;
            case SSL_ERROR_SYSCALL:
                std::cout<<"SSL ERROR SYSCALL"<<std::endl;
                break;
            case SSL_ERROR_WANT_ASYNC_JOB:
                std::cout<<"SSL ERROR WANT ASYNC_LOOKUP"<<std::endl;
                break;
            case SSL_ERROR_WANT_ASYNC:
                std::cout<<"SSL ERROR WANT X509_LOOKUP"<<std::endl;
                break;
            case SSL_ERROR_WANT_X509_LOOKUP:
                std::cout<<"SSL ERROR WANT X509_LOOKUP"<<std::endl;
                break;
            case SSL_ERROR_WANT_WRITE:
                std::cout<<"SSL ERROR WANT WRITE"<<std::endl;
                break;
            case SSL_ERROR_WANT_READ:
                std::cout<<"SSL ERROR WANT READ"<<std::endl;
                break;
            case SSL_ERROR_ZERO_RETURN:
                std::cout<<"SSL ERROR SSL_ERROR_ZERO_RETURN"<<std::endl;
                break;
            case SSL_ERROR_NONE:
                break;
            
            default:
                break;
        }
  }

 void secSocketCloseConnection() {
     // sockClose(s);
     // sockQuit();
    }

private:
  bool getCertificatAndPrivateKey(X509 *cert, EVP_PKEY *pkey) {
    BIO *in = BIO_new(BIO_s_file());
    if (!BIO_read_filename(in, (char *)CERT.c_str())) {
      BIO_free(in);
      std::cout << "Error reading the certificate" << std::endl;
      return false;
    }
    PKCS12 *p12 = d2i_PKCS12_bio(in, NULL);
    BIO_free(in);
    if (p12 == NULL) {
      std::cout << "Error the file cert.p12 is corrupted" << std::endl;
      return false;
    }
    if (PKCS12_parse(p12, password.c_str(), &pkey, &cert, &ca)) {
      PKCS12_free(p12);
      return true;
    }
   else {
      PKCS12_free(p12);
      std::cout << "Error cannot read the certificate" << std::endl;
      return false;
    }
  }

  SSL *ssl;
  X509 *cert;
  int socketFd;
  EVP_PKEY *pkey;
  char buff[BUFFER_SIZE];
  STACK_OF(X509) *ca = NULL;
  const std::string password={"nuno"};
  const std::string CERT{"cert.p12"};
  const std::string CAFILE{"Certificate.pem"};

};
} // namespace TCPIPOVERSSL
#endif
