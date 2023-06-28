#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <thread>
#include <future>
#include <utility>
#include <memory>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <initializer_list>
#include <cstddef>
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <fstream>
//#include <concepts>

using namespace std;

struct employee {
  unsigned id;
  std::string name;
  std::string role;
  float salary;
};


// CODE CHALLENGE FUNCTIONS
template<class... Args>
int combination(Args... numbers)
{
  return (... * numbers);
}

int squareRoot(int a, int b, int c)
{
  //std::cout<< "D= "<<std::sqrt((b*b)-4*a*c)<<std::endl;
  //int delt = (b-std::sqrt((b*b)-4*a*c))/(2*a);
  //std::cout<< "x1 = "<< delt<<std::endl;
  return abs(b - std::sqrt((b * b) - 4 * a * c)) / (2 * a);
}

void isEvenOrodd(int *numbers, int size)
{
  int endTransform {0};
  std::array<int, 3> outputArray{0, 0, 0};
  for (int i = 0; i < size; i++)
  {
    numbers += i;
    std::cout << "For i = " << i << " the value is " << (*numbers) << std::endl;
    /* if((*numbers)%2 == 0)
     {
        std::cout<<"i = "<<i<<" is an Even "<<((*numbers+i)-2)<<std::endl;
        outputArray[i] = (*numbers)-2;

     }
     else
     {
       std::cout<<"i = "<<i<<" is an Odd "<<((*numbers+i)+2)<<std::endl;
       outputArray[i] = (*numbers+i)+2;
     }*/
  }

  endTransform++;
  //print the results
  std::cout << "[ ";
  for (int nmber : outputArray)
  {
    std::cout << nmber;
  }
  std::cout << " ]" << std::endl;

  /*
  if(transformTimes != endTransform)
    isEvenOrodd(numbers, (transformTimes - endTransform));
    */

}
//END

class Vehicle
{

private:
  int speed{0};
  std::string model{};
public:
  Vehicle(std::string modelV, int speedV)
    : model{std::move(modelV)}
    , speed(speedV)
  {}
  auto getModel() const {return model;}
  auto getSpeed() const {return speed;}

};

class Car
{
private:
  int speed{0};
public:
  Car(std::string modelV, int speedV):
    speed(speedV)
  {}
  auto getSpeed() const {return speed;}
};

/*
template<class T>
concept CheckRequeriments = requires(T &vhp ) {
   { vhp.getModel() }->std::as_same<std::string>;
   { vhp.getSpeed() }->std::as_same<int>;
}
*/

/* This is an example of normal function that return a lambada function*/
static auto consumer (auto &container) {
  return [&] (auto value) {
    container.push_back(value);
  };
}

std::string Mamarela(const std::string & name, const std::string & email, const std::string & phone, const std::string & country)
{
  std::cout << "This is the user personal contacts" << std::endl;
  std::cout << "Name: Mr. " << name << std::endl;
  std::cout << "e-mail: " << email << std::endl;
  std::cout << "Mobile phone: " << phone << std::endl;
  std::cout << "Country " << country << std::endl;

  return "Mamarela info";
}

void reference(int & value)
{
  std::cout << "The values read is " << value << endl;
}

class Magic
{
public:
  Magic() {
    std::cout << "This class use a std::iniliatizer to fill a vector" << std::endl;
  }
  Magic(std::initializer_list<int> nmbers) {
    for (int values : nmbers)
    {
      numbers.push_back(values);
    }
  }
  void PrintValues()
  {
    std::cout << "These are the values inserted" << std::endl;
    std::cout << "[";
    for (int opValues : numbers)
    {
      std::cout << opValues << " ";
    }
    std::cout << "]" << std::endl;
  }
private:
  std::vector<int> numbers{};
};

class TcpIpLayer
{
public:
  TcpIpLayer() {
    std::cout << "The Netowrk must be configuration before used any service" << std::endl;
  }
  TcpIpLayer(std::string _url, std::string _portName, std::string _ipAddress)
    : url(_url)
    , portName(_portName)
    , ipAddress(_ipAddress)
  {
    std::cout << "Netowrk configuration successfully" << std::endl;
  }
  ~TcpIpLayer() {};
  std::string getUrl()
  {
    return url;
  }
  std::string getPortName()
  {
    return portName;
  }
  std::string geIpAddress()
  {
    return ipAddress;
  }
private:
  std::string url{};
  std::string portName{};
  std::string ipAddress{};
};

int& pinCode(int &pin)
{

  pin = pin + 9;
  std::cout << "The pin code was successfully restored" << std::endl;
  //std::cout<<"This is the new pin code "<< pin<< std::endl;

  return pin;
}
// INIT MAIN FUNCTION

int main(int argc, char ** argv)
{

  /*Code to test std::move*/
  std::string girl{"hola"};
  std::string sister{};
  sister = std::move(girl);
  std::cout << "This is the name of my syster " << sister << std::endl;
  std::cout << "The girl now is : " << girl << std::endl;
//end

  /*manual Test the std::initializer_list*/
  Magic _magicBox = {1, 2, 3, 3, 4, 54, 660};
  _magicBox.PrintValues();
//end

  /* utility header to use std::function*/
  auto f_lambda = [](int jobDays) { return jobDays + 1; };
  std::cout << "You work " << f_lambda(5) << " days" << std::endl;
  std::function<int(int)> funcPtr1 = f_lambda;

  std::string name    = {"Nuno Figueira"};
  std::string email   = {"nuno.figueira@nundelTech.com"};
  std::string phone   = {"+41 54 65 464"};
  std::string country = {"Switzerland"};
  std::function<std::string(const std::string&, const std::string&, const std::string&, const std::string&)>functPtr2 = Mamarela;
//functPtr2(name, email, phone, country);
  auto mamarela = std::bind(functPtr2, name, email, phone, std::placeholders::_1);
  std::cout << "This is the return type " << mamarela(country) << std::endl;
//end

  /*Study references */
  std::function<void(int &)> referenceFunc = reference;
  int marta{8340};
  referenceFunc(marta);
//end

  /*Study example smart_ptr*/
  auto ptr = std::make_unique<Magic>(_magicBox);
  std::cout << "I am the Unique pointer saving the value: " << std::endl;
  ptr->PrintValues();
//end

  /*std::future using std::packaged_task*/
  std::packaged_task<int()> task([ = ]() {return marta / 4;});
  std::future<int> taskResult = task.get_future();
  std::thread(std::move(task)).detach();
  std::cout << "Waiting for the future task finish" << std::endl;
//taskResult.wait();
  for (int i = 0; i < 40000; i++);
  std::cout << "The result is " << taskResult.get() << std::endl;
//end

  /*std::future using std::async*/
  std::string url{"nundel.com"};
  std::string portName{"8080"};
  std::string ipAddress{"10.10.10.90"};
  TcpIpLayer network(url, portName, ipAddress);
  std::future<std::string> asyncronousFunction = std::async(std::launch::async, &TcpIpLayer::getUrl, network);

  for (int i = 0; i < 400000; i++);
  std::cout << "This is the url: " << asyncronousFunction.get() << std::endl;
  for (int i = 0; i < 40000; i++);
// end

  /* C++17 bind structre data with stucture*/
  std::vector<employee> bitoCompany {
    {1, "Bito Sambito", "CTO", 390.78},
    {2, "Sampalo Nzeto", "Security JD", 290.78},
    {3, "Wela Vuindela", "Financial Manager", 300.78},
    {4, "Mbila Etuvalela", "Account Manager", 290.78}
  };

  std::cout << "" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "These are the list of our employees names and roles:" << std::endl;
  for (auto & [id, name, role, salary] : bitoCompany )
  {
    std::cout << "Fullname: " << name << std::endl;
    std::cout << "Role: " << role << std::endl;
    //std::cout<<""<<std::endl;
    //std::cout<<""<<std::endl;
  }

// end

  /*C++17 Structure Binding with Map*/
  std::map<std::string, size_t> animal_population {
    {"humans", 7000000000},
    {"chickens", 17863376000},
    {"camels", 24246291},
    {"sheep", 1086881528}
  };

  for (const auto &[species, count] : animal_population) {
    std::cout << "There are " << count << " " << species << " on this planet.\n";
  }

// end

  /*std::copy_if ans std::trasnform_if example*/

  int controlAmplitud = 50;
  std::vector<int> intergerNumbers{20, 30, 58};
  std::vector<int> naturalNumbers{};
  std::copy_if(intergerNumbers.begin(), intergerNumbers.end(),  std::back_inserter(naturalNumbers), [ = ](int x) { return x < controlAmplitud;});

  std::cout << "These are the natural numbers:" << std::endl;
  std::cout << "[";
  for (int getNumbers : naturalNumbers)
  {
    std::cout << " " << getNumbers;
  }
  std::cout << " ]" << std::endl;

  std::copy_if(intergerNumbers.begin(), intergerNumbers.end(), std::ostream_iterator<int>(std::cout, " "), [](int x) { return x % 2 == 0; });
// end

  /* Std::accumulator C++17*/
  std::cout << "\n" << std::endl;
  std::cout << "Example of accumulator in C++ 17" << std::endl;
  std::vector<int> filterAcumulator {0, 2, 1, 3, 8, 9 , 10};
  std::cout << accumulate(filterAcumulator.begin(), filterAcumulator.end(), 0) << '\n';

  if (std::is_sorted(filterAcumulator.begin(), filterAcumulator.end()))
  {
    std::sort(filterAcumulator.begin(), filterAcumulator.end());
    std::cout << " These are the data after sorted the vector" << std::endl;
    for (int get : filterAcumulator)
    {
      std::cout << get << std::endl;
    }
  }
  else
  {
    std::cout << "The vector is not sorted " << std::endl;
  }
//end

  /* Example of std::remove and std::remove_if*/
  std::cout << "\n" << std::endl;
  std::vector<int> fpassBand {0, 2, 1, 3, 8, 9 , 10};
  std::vector<int>::iterator itr = std::remove_if(fpassBand.begin(), fpassBand.end(), [](int x) { return x == 10; });
  fpassBand.erase(itr, fpassBand.end());
  std::cout << "Data list after erase a zero :" << std::endl;
  std::cout << "[";
  for (int index : fpassBand )
  {
    std::cout << " " << index;
  }
  std::cout << " ]";
// end

  /*Example of algorithm of error calculation using two vectores*/
  int error{0};
  int errorQ{0};
  std::vector<int> pidData1 {0, 2};
  std::vector<int> pidData2 {1, 21};
  for (int i = 0; i < pidData2.size(); ++i)
  {
    error = error + ( pidData2.at(i) * pidData2.at(i) ) - ( pidData1.at(i) * pidData1.at(i) );
    errorQ = errorQ + (pidData1.at(i) * pidData1.at(i)) - 2 * (pidData1.at(i) * pidData2.at(i)) + (pidData2.at(i) * pidData2.at(i));
  }
  std::cout << "\nThis is the error: " << error << std::endl;
  std::cout << "\nThis is the errorQ: " << errorQ << std::endl;
//end

  /*C++ 17 generate the algorithm that we can use to fill a data structure like a vector*/
  auto funcDgenerator = [&]() { return marta / 2;};
  std::generate(pidData2.begin(), pidData2.end(), funcDgenerator);
  auto printValues = [](std::vector<int> & dataVector) {
    std::cout << "Fill a vector using a std::generate :" << std::endl;
    std::cout << "[ ";
    for (int iValue : dataVector)
    {
      std::cout << iValue << " ";
    }
    std::cout << " ]";
  };
  printValues(pidData2);
//end

  /* This is an example of how the C++ can return a lambada function*/
  auto getConsumer = consumer(pidData2);
  getConsumer(41);
  printValues(pidData2);
//end

  /* Example of structure Binding in C++17 */
// Structure binding not added any code performance just made the code more readble.
// ex.01
// This is one of the way we can use to declare a structure binding
  employee _pedroLafuente = {41, "Kalunga Gira", "Project Manager", 3400.98};

// ex.02
// employee _pedroLafuente = std::tuple<unsigned, std::string, std::string, float> german std::make_tuple(41, "Kalunga Gira", "Project Manager", 3400.98);
  std::tuple<unsigned, std::string, std::string, float> german;
  german = std::make_tuple(41, "Kalunga Gira", "Project Manager", 3400.98);
//employee _pedroLafuente;
  auto [id, bb, brole, hsalary] = german;

  std::cout << "\n The role is :" << brole << std::endl;
//end

  /*C++ 17 Binding with mapa key values*/
  std::map<int, std::string> pofessionalValuesCode {{201, "System Admin"}};
//end

// Example of iostream File in Modern C++17
  std::ifstream ifs; // input file stream
  std::string str{};
// input file stream
  ifs.open( "/media/nundelTech/CppLesson/study-cpp-11-14-17-20/testfile.txt", std::ios::in );

  if (ifs)
  {
    while ( !ifs.eof() )
    {
      std::getline ( ifs, str);
      std::cout << "This is the file read \n" << str << std::endl;
    }
    ifs.close();
  }
//end

  /*this example is valid for C++11,14,17,20 */
//Example of a function that receive return a integer reference
// and we received this reference and put another value inside.
  int bigKing = {21};
  pinCode(bigKing)  = 1;
// Thie second study case we received the reference and add to an integer pointer
//int getPin = pinCode(bigKing);
//int *ok = &getPin;
//std::cout<<"\nThe new pin puk is "<<(*ok)<<std::endl;
  std::cout << "New value is " << bigKing << std::endl;
//end

  /*Study case array in C++11*/
//std::array<int, 4> arrInteger;
//arrInteger.fill(0);
//std::cout<<"Playing with Modern Array in C++11\n"<<std::endl;
//std::cout<<"Array size : "<<arrInteger.size()<<std::endl;
//std::cout<<"Array empty: "<<arrInteger.empty()<<std::endl;
//std::cout<<"Array [0]  = "<<arrInteger.front()<<std::endl;
//std::cout<<"Array [3]  = "<<arrInteger.back()<<std::endl;
//int *arrPtr = arrInteger.data();
//*arrPtr = 24;
//arrPtr+=1;
//std::cout<<"Using C++98 pointer style to access array memory address values: (*ptr) = "<<(*arrPtr)<<std::endl;
//end

  /*Understand const functions in Modern C++11,14,17,20*/
  Vehicle kwanza("Eden river", 250);
  std::cout << "AThe car speed is " << kwanza.getSpeed() << std::endl;

  struct name_greeter {
    std::string name;
    void operator()() {
      std::cout << "Hello, " << name << '\n';
    }
  };

  name_greeter greet_john_doe {"John Doe"};
  greet_john_doe();
//end

  /*Example of a function that consume a variadic Template values in C++17*/
  int resultArgs = combination(2, 3);
  std::cout << "The first combination result is: " << resultArgs << std::endl;
  resultArgs     = combination(2, 3, 4);
  std::cout << "The second combination result is: " << resultArgs << std::endl;
  resultArgs     = combination(2, 3, 4, 5, 6);
  std::cout << "The third combination result is: " << resultArgs << std::endl;
//end

  std::cout << "The sqaure root of equation (a=2, b=-7,  c=3)  is: " << squareRoot(2, -7, 3) << std::endl;
  std::cout << "The sqaure root of equation (a=1, b=-12, c=28) is: " << squareRoot(1, -12, -28) << std::endl;
  std::cout << "The sqaure root of equation (a=1, b=2,   c=-3) is: " << squareRoot(1, 2, -3) << std::endl;

  std::cout << "\n\n\n" << std::endl;
  std::array<int, 3> sweetIntegers{1, 4, 3};
  isEvenOrodd(sweetIntegers.data(), 3);

  std::cout << "\n\n\n" << std::endl;
  return 0;
}
