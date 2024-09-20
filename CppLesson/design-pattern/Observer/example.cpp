/**
 * Observer Design Pattern
 *
 * Intent: Lets define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

#include <iostream>
#include <list>
#include <string>

// INTERFACE #1
class IObserver {
public:
  virtual ~IObserver(){};
  virtual void Update(const std::string &message_from_subject) = 0;
};

// INTERFACE #2
class ISubject {
public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

class Subject : public ISubject {
public:
  virtual ~Subject() {
    std::cout << "Goodbye, I was the Subject.\n" << std::endl;
  }

  /**
   * The subscription management methods.
   */
  void Attach(IObserver *observer) override {
    list_observer_.push_back(observer);
  }
  void Detach(IObserver *observer) override { list_observer_.remove(observer); }
  void Notify() override {
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(message_);
      ++iterator;
    }
  }

  void CreateMessage(std::string message = "Empty") {
    this->message_ = message;
    Notify();
  }

  void HowManyObserver() {
    std::cout << "There are " << list_observer_.size()
              << " observers in the list.\n";
  }

  /**
   * Usually, the subscription logic is only a fraction of what a Subject can
   * really do. Subjects commonly hold some important business logic, that
   * triggers a notification method whenever something important is about to
   * happen (or after it).
   */
  void SomeBusinessLogic() {
    this->message_ = "change message message";
    Notify();
    std::cout << "I'm about to do some thing important\n";
  }

private:
  std::list<IObserver *> list_observer_;
  std::string message_;
};

// GENERAL OBSERVER ...
class Observer : public IObserver {
public:
  Observer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_
              << "\".\n";
    this->number_ = Observer::static_number_;
  }

  virtual ~Observer() {
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
  }

  void Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }

  void RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
  }

  void PrintInfo() {
    std::cout << "Observer \"" << this->number_
              << "\": a new message is available --> "
              << this->message_from_subject_ << "\n";
  }

private:
  std::string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

// DATABASE SUBJECTS
class DatabaseSubject : public ISubject {
public:
  virtual ~DatabaseSubject() {
    std::cout << "Finish the database subject" << std::endl;
  }

  /**
   * The subscription management methods.
   */
  void Attach(IObserver *observer) override {
    observers.push_back(observer);
    numberOfSubscribers = observers.size();
  }

  void Detach(IObserver *observer) override { observers.remove(observer); }

  void Notify() override {
    std::list<IObserver *>::iterator iterator = observers.begin();
    while (iterator != observers.end()) {
      (*iterator)->Update(message);
      ++iterator;
    }
  }

  void databaseCommit(std::string_view sqlMessage) {
    this->message = sqlMessage;
    Notify();
  }

  int getNumberOfSubscribers() { return numberOfSubscribers; }

private:
  std::list<IObserver *> observers;
  std::string message;
  int numberOfSubscribers{0};
};

//  DATABASE OBSERVER ...
class DatabaseObserver : public IObserver {
public:
  DatabaseObserver(DatabaseSubject &dbContext) : subjectsToObserver(dbContext) {
    setObserverId(this->subjectsToObserver.getNumberOfSubscribers());
    this->subjectsToObserver.Attach(this);
    std::cout << "Starting observing the database events" << std::endl;
  }

  virtual ~DatabaseObserver() {
    std::cout << "Goodbye observer \"" << observerId << "\".\n";
  }

  void Update(const std::string &message_from_subject) override {
    this->messageFromSubject = message_from_subject;
    PrintInfo();
  }

  void RemoveMeFromTheList() {
    this->subjectsToObserver.Detach(this);
    std::cout << "The observer \"" << observerId
              << "\" was removed from the list.\n";
  }

  void PrintInfo() { std::cout << this->messageFromSubject << "\n"; }

  int getObserverId() { return observerId; }

  void setObserverId(int id) { observerId = id + 1; }

private:
  int observerId;
  DatabaseSubject &subjectsToObserver;
  static int staticNumber;
  std::string messageFromSubject;
};

//  DATABASE ADMINISTRATOR OBSERVER ...
class ManagerDatabaseAdministratorTaskOberver : public IObserver {
public:
  ManagerDatabaseAdministratorTaskOberver(DatabaseSubject &dbContext)
      : subjectsToObserver(dbContext) {
    setObserverId(this->subjectsToObserver.getNumberOfSubscribers());
    this->subjectsToObserver.Attach(this);
    std::cout << "The Database Adiministrator is working now." << std::endl;
  }

  virtual ~ManagerDatabaseAdministratorTaskOberver() {
    std::cout << "The database adiministrator exit \"" << observerId << "\".\n";
  }

  void Update(const std::string &message_from_subject) override {
    this->messageFromSubject = message_from_subject;
    std::cout << "Execution database adiministrator task after new operations "
                 "be commited"
              << std::endl;
  }

  void RemoveMeFromTheList() {
    this->subjectsToObserver.Detach(this);
    std::cout << "The observer \"" << observerId
              << "\" was removed from the list.\n";
  }

  void PrintInfo() { std::cout << this->messageFromSubject << "\n"; }

  int getObserverId() { return observerId; }

  void setObserverId(int id) { observerId = id + 1; }

private:
  int observerId;
  DatabaseSubject &subjectsToObserver;
  static int staticNumber;
  std::string messageFromSubject;
};

int Observer::static_number_ = 0;

void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  Observer *observer4;
  Observer *observer5;
  subject->CreateMessage("Hello World! :D");
  observer3->RemoveMeFromTheList();
  subject->CreateMessage("The weather is hot today! :p");
  observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  observer5 = new Observer(*subject);

  subject->CreateMessage("My new car is great! ;)");
  observer5->RemoveMeFromTheList();

  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer5;
  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete subject;
}

int main() {
  // ClientCode();
  char opt{};
  Subject *subject = new Subject;
  DatabaseSubject *dataBaseServices = new DatabaseSubject;
  Observer *observer1 = new Observer(*subject);
  DatabaseObserver *dbSubscriber = new DatabaseObserver(*dataBaseServices);
  DatabaseObserver *adminDbSubscriber = new DatabaseObserver(*dataBaseServices);
  ManagerDatabaseAdministratorTaskOberver *adminTasks =
      new ManagerDatabaseAdministratorTaskOberver(*dataBaseServices);

  do {
    std::cin >> opt;
    switch (opt) {
    case 'a':
      subject->CreateMessage("OBSERVER STARTING");
      dataBaseServices->databaseCommit(
          "New register inserted in Database Table UsersAccount");
      break;
    case 'b':
      std::cout << "The number of observers are: "
                << dataBaseServices->getNumberOfSubscribers() << std::endl;
      break;
    default:
      // std::cout<< "To see the result you need press the keyboard letter
      // [a]"<<std::endl;
      break;
    }
  } while (opt != 'e');

  delete observer1;
  delete subject;
  delete dataBaseServices;
  delete dbSubscriber;
  delete adminDbSubscriber;

  return 0;
}