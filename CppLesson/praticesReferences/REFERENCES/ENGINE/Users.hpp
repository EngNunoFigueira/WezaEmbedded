#ifndef REFERENCES_ENGINE_USERS_HPP
#define REFERENCES_ENGINE_USERS_HPP

#include <iostream>

using namespace std;

namespace REFERENCES {

namespace ENGINE {

public class Users
{
public:

  Users();
  Users(std::string& name);
  virtual ~Users();

private:

  int jobID{100};
  std::string techInfo{};
};

}
}
#endif
