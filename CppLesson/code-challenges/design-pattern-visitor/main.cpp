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
#include <cstring>
#include <iomanip>
#include <list>
#include <sstream>
#include <regex>


class Licor;
class Tobacco;
class Necessity;

class Visitor {

public:
    virtual double visit(const Licor *licor) const = 0;
    virtual double visit(const Tobacco *tobacco) const = 0;
    virtual double visit(const Necessity *necessity) const = 0;
};

class Visitable
{
public:

    virtual ~Visitable() {};
    virtual double accept(Visitor *visitor) const = 0;

};

/*Now we implement the these classes used in the VISITOR INTERFACE*/

class Licor : public Visitable
{
public:
    Licor(double price):
        productPrice(price) {}
    double getPrice() const {
        return productPrice;
    }
    virtual double accept(Visitor *visitor) const override {
        return visitor->visit(this);
    }

private:
    double productPrice {};
};

class Tobacco : public Visitable
{
public:
    Tobacco(double price):
        productPrice(price) {}
    double getPrice() const {
        return productPrice;
    }
    virtual double accept(Visitor * visitor) const override {
        return visitor->visit(this);
    }
private:
    double productPrice {};
};

class Necessity : public Visitable
{
public:
    Necessity(double price):
        productPrice(price) {}
    double getPrice() const { 
        return productPrice; 
    }
    virtual double accept(Visitor *visitor) const override {
        return visitor->visit(this);
    }
private:
    double productPrice {};
};

/*----- This is the class that will consume the resource of the design pattern visitor----*/

class ConsumerVisitor : public Visitor
{
public:
    virtual double visit(const Licor *licor) const override {
        std::cout << "The licor price is " << licor->getPrice() << std::endl;
        return licor->getPrice();
    }
    virtual double visit(const Tobacco *tobacco) const override {
        std::cout << "The licor price is " << tobacco->getPrice() << std::endl;
        return tobacco->getPrice();
    }
    virtual double visit(const Necessity *necessity) const override {
        std::cout << "The licor price is " << necessity->getPrice() << std::endl;
        return necessity->getPrice();
    }
};


int main()
{
    std::cout << "This exercise show as the design pattern visitor is implemented" << std::endl;
    std::cout << "What the Visitor design pattern can do for us." << std::endl;
    std::cout << "FIRST FEATURE:" << std::endl;
    std::cout << "Allow you to add methods to classes of different types without much altering those classes." << std::endl;
    std::cout << "SECOND FEATURE:" << std::endl;
    std::cout << "You can make completely different methods depending on the class used" << std::endl;
    std::cout << "SECOND THIRD:" << std::endl;
    std::cout << "Allow you to define external classes that can extend other classes without majorly editing them" << std::endl;

    Licor     *limao  = new Licor(34.99);
    Tobacco   *garret = new Tobacco(12.30);
    Necessity *cloths = new Necessity(745.59);
    ConsumerVisitor typeProductLicor;
    typeProductLicor.visit(limao);
    typeProductLicor.visit(cloths);

    return 0;
}
