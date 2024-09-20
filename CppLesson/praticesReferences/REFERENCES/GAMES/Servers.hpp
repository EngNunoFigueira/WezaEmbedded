#ifndef REFERENCES_GAMES_SERVERS_HPP
#define REFERENCES_GAMES_SERVERS_HPP

#include <iostream>

using namespace std;

namespace REFERENCES {

namespace GAMES {

public class Servers
{
public:

  Servers();
  Servers(std::string& game);
  virtual ~Servers();

private:

  int serialPT{100};
  std::string name{};
};
}
}
#endif
