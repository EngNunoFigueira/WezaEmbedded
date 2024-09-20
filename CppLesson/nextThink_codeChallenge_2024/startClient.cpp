#include "SocketTcpIp.hpp"
//#include "TcpIpOverSsl.hpp"
//#include "SocketManager.hpp"
#include <iostream>

using namespace std;
using namespace sktTcpIp;

std::string sftwVersion{"1.0.0"};
char *buff;
void serviceUpdateSoftwareVersion(const std::string &data) {
  data.compare("version") == 0
      ? std::cout << "Application Version " << sftwVersion << endl
      : std::cout << "Application Version " << data << std::endl;
}

int main(int argc, char *argv[]) {

  unsigned option{0};
  char closeConn{'O'};

  serviceUpdateSoftwareVersion("version");
  SocketTcpIp connManager;
  // SocketManager connManager;
  connManager.socketConnect("test", "127.0.0.1", 54500,
                            serviceUpdateSoftwareVersion);
  // TcpIpOverSsl sslConn(connManager.socketConnect("test", "127.0.0.1",
  // 54500)); sslConn.SslClientConfiguration();
  do {
    std::cout << "Select an option" << std::endl;
    std::cin >> option;
    switch (option) {
    case 1:
      connManager.socketSend("test", "update");
      connManager.socketReceive("test", serviceUpdateSoftwareVersion);
      // sslConn.secSocketReceive(buff,serviceUpdateSoftwareVersion);
      // sslConn.secSocketSend("TSSL");
      break;
    case 2:
      closeConn = {'X'};
      std::cout << "Client shutdown connection." << std::endl;
      connManager.closeConnection("test");
      break;
    default:
      // std::cout << "Waiting for another connection" << std::endl;
      break;
    }
  } while (closeConn == 'O');

  return 0;
}

//[&](){}