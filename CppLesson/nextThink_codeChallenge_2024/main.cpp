#include "SocketTcpIp.hpp"
#include "TcpIpOverSsl.hpp"
#include "SocketManager.hpp"
#include <iostream>

using namespace std;
using namespace sktTcpIp;

void handleData(const std::string &data) {
  std::cout << "Client sent: " + data << endl;
}

void serviceUpdateSoftwareVersion1(const std::string & softwareVersion)
{
    /**
     * Read the database file and load all sft version to vector of strings.
     * check if the received version is on list. If the version is on the list.
     **/
}

int main(int argc, char *argv[]) {

  char *buff;
  SocketTcpIp connManager;
  connManager.startServer("test", 54500, &handleData);
  //SocketManager connManager;
  //TcpIpOverSsl sslConn(connManager.startServer("test", 54500, &handleData));
  //sslConn.SslServerConfiguration();
  //sslConn.secSocketSend("TSSL");
  //sslConn.secSocketReceive(buff,&handleData);



  while(true)
  {
  	//connManager.socketSend("test", "Hello from server!");
  	// sslConn.secSocketReceive(buff,handleData);
  	 //sslConn.secSocketSend("TSSL");
  }	
  

  return 0;
}
