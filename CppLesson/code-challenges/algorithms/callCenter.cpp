#include <algorithm>
#include <array>
#include <exception>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/**
 * All the classes and enums types will be declared here.
 * Ín order to better organize the code presentation...
 * Last updated 2024
 */

enum class STATUS { AVAIBLE = 0, BUSY, OK };

class Employee {
public:
  Employee();
  Employee(const std::string &_name, const std::string &_surname,
           const std::string &_role, const std::string &_docPassport,
           const std::string &_socialSecurityNumber,
           const std::string &_welcomeDateOnCompany, const double _salary)
      : name{_name}, surname{_surname}, role{_role}, docPassport{_docPassport},
        socialSecurityNumber{_socialSecurityNumber},
        welcomeDateOnCompany{_welcomeDateOnCompany}, salary{_salary} {
    // nothing todo
  }
  ~Employee(){};
  const std::string getRole() const { return role; }
  void showDocumentation() const {
    std::cout << "Good night sir, I am " << name << " " << surname
              << "and how can help you ?" << std::endl;
  }

private:
  std::string role{};
  std::string name{};
  std::string surname{};
  std::string docPassport{};
  std::string socialSecurityNumber{};
  std::string welcomeDateOnCompany{};
  double salary{};
};

class Respondent : public Employee {
public:
  Respondent();
  Respondent(const std::string &_name, const std::string &_surname,
             const std::string &_role, const std::string &_docPassport,
             const std::string &_socialSecurityNumber,
             const std::string &_welcomeDateOnCompany, const double _salary)
      : Employee(_name, _surname, _role, _docPassport, _socialSecurityNumber,
                 _welcomeDateOnCompany, _salary) {}
  void setStatus(const STATUS _busy) { isBusy = _busy; }
  const STATUS getStatus() { return isBusy; }
  void setNumberOfAttendedCall() { ++numberOfAttendedCall; }
  ~Respondent(){};

private:
  STATUS isBusy{};
  int numberOfAttendedCall{0};
};

class Manager : public Employee {
public:
  Manager();
  Manager(const std::string &_name, const std::string &_surname,
          const std::string &_role, const std::string &_docPassport,
          const std::string &_socialSecurityNumber,
          const std::string &_welcomeDateOnCompany, const double _salary)
      : Employee(_name, _surname, _role, _docPassport, _socialSecurityNumber,
                 _welcomeDateOnCompany, _salary) {}
  void setStatus(const STATUS _busy) { isBusy = std::move(_busy); }
  const STATUS getStatus() const { return isBusy; }
  void setNumberOfAttendedCall() { ++numberOfAttendedCall; }
  ~Manager(){};

private:
  STATUS isBusy{};
  int numberOfAttendedCall{0};
};

class Director : public Employee {
public:
  Director();
  Director(const std::string &_name, const std::string &_surname,
           const std::string &_role, const std::string &_docPassport,
           const std::string &_socialSecurityNumber,
           const std::string &_welcomeDateOnCompany, const double _salary)
      : Employee(_name, _surname, _role, _docPassport, _socialSecurityNumber,
                 _welcomeDateOnCompany, _salary) {}
  void setStatus(const STATUS _busy) { isBusy = _busy; }
  const STATUS getStatus() const { return isBusy; }
  void setNumberOfAttendedCall() { ++numberOfAttendedCall; }
  ~Director(){};

private:
  STATUS isBusy{};
  int numberOfAttendedCall{0};
};

class PhoneCall {
public:
  PhoneCall();
  PhoneCall(int _number, std::string _origin, int _calltimeDuration)
      : number{_number}, origin{_origin}, callTimeDuration{_calltimeDuration} {
    // Nothing todo
  }
  ~PhoneCall(){};
  const int getCallTimeDuration(const int _callTimeDuration) const {
    return callTimeDuration;
  }
  const int getPhoneNumber() const { return number; }
  const std::string getOrigin() { return origin; }

private:
  int number{0};
  std::string origin{};
  int callTimeDuration{0};
};

/**
 * The answerCall method receive the profile of the avaible employee to answer
 the call and update the status and the number of calls atended by this
 employee.
 * Input parameters is a template to be deduze in the parameters listed below:

 * const std::vector<Respondent>
 * const std::vector<Manager>
 * const std::vector<Director>
 */
template <typename EMPLOYEE>
STATUS answerCall(std::vector<EMPLOYEE> &empAvaible) {

  typename std::vector<EMPLOYEE>::iterator nextEmployee = empAvaible.begin();
  while (nextEmployee != empAvaible.end()) {
    if ((*nextEmployee).getStatus() == STATUS::AVAIBLE) {

      std::cout << "Your call we be attended by our "
                << (*nextEmployee).getRole() << std::endl;
      (*nextEmployee).showDocumentation();
      (*nextEmployee).setStatus(STATUS::BUSY);
      (*nextEmployee).setNumberOfAttendedCall();

      return STATUS::OK;
    }
    ++nextEmployee;
  }
  return STATUS::BUSY;
}

/**
 * The dispatch method manager all entry calls linking the ring to avaible each
 * avaible respondent.
 *
 * In case of all respondent are busy, the call is forwarding to the manager
 * room and if all managers are busy too, it must be scaled or forwarding to the
 * directors room. In the case of anyone is free to answer the call this is put
 * on waiting state for 5 minutes.
 *
 * Input Parameters:
 *
 * const PhoneCall entryCall
 * const std::vector<Respondent> resp
 * const std::vector<Manager> manager
 * const std::vector<Director> director
 */
void dispatchCall(PhoneCall entryCall, std::vector<Respondent> &resp,
                  std::vector<Manager> &manager,
                  std::vector<Director> &director) {

  if (STATUS::OK != answerCall(resp))
    if (STATUS::OK != answerCall(manager))
      if (STATUS::OK != answerCall(director)) {
        std::cout << "Sorry this time we cannot atend your call, but keep in "
                     "line asap one of our employees will help you."
                  << std::endl;
        std::cout << "Starting play a music and wait a minutes in line"
                  << std::endl;
      }
}

int main(int argc, char **agrv) {

  std::vector<Respondent> respondent;
  respondent.push_back({"Helton", "Sambo", "respondent", "QQWJVDI23UWW",
                        "53434343RQ", "09-04-2000", 58.0});

  respondent.push_back({"Mario", "Dreck", "respondent", "QQWJVDI23UWW",
                        "53434343RQ", "09-04-2000", 58.0});
  respondent.push_back({"David", "Pearson", "respondent", "QQWJVDI23UWW",
                        "53434343RQ", "09-04-2000", 58.0});
  respondent.push_back({"Anne", "Louvely", "respondent", "QQWJVDI23UWW",
                        "53434343RQ", "09-04-2000", 58.0});
  respondent.push_back({"Marlon", "Darlen", "respondent", "QQWJVDI23UWW",
                        "53434343RQ", "09-04-2000", 58.0});
  respondent.push_back({"Cristian", "Manuel", "respondent", "QQWJVDI23UWW",
                        "53434343RQ", "09-04-2000", 58.0});

  std::vector<Manager> manager;
  manager.push_back({"Carls", "Even", "manager", "4RJRIJIFJ5IIR",
                     "005555323212", "19-01-1980", 158.0});
  manager.push_back({"Carls", "Even", "manager", "4RJRIJIFJ5IIR",
                     "005555323212", "19-01-1980", 158.0});
  manager.push_back({"Carls", "Even", "manager", "4RJRIJIFJ5IIR",
                     "005555323212", "19-01-1980", 158.0});

  std::vector<Director> director;
  director.push_back({"Carls", "Even", "director", "4RJRIJIFJ5IIR",
                      "005555323212", "19-01-1980", 158.0});
  director.push_back({"Carls", "Even", "director", "4RJRIJIFJ5IIR",
                      "005555323212", "19-01-1980", 158.0});

  // PhoneCall(int _number, std::string _origin, int _calltimeDuration)
  PhoneCall entryCall(345456780, "Madrid", 0);

  // starting atending the phones calls arrived...
  for (int i{0}; i < 7; ++i) {
    dispatchCall(entryCall, respondent, manager, director);
  }

  std::array<int, 10> numbers{1, 3, 5, 19, 3, 8, 4, 5, 2, 19};

  // Testing a sort algorithm test
  int previousValue{0};
  std::sort(numbers.begin(), numbers.end());
  for_each(numbers.begin(), numbers.end(), [&](int value) mutable {
    if ((value - previousValue) == 0)
      std::cout << "Found a duplicated number" << value << std::endl;
    previousValue = value;
  });
  return 0;
}