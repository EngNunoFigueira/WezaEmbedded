#include<iostream>
#include<stdio.h>
#include<gtest/gtest.h>
using namespace std;


class Person
{

 public:
 	Person(){}
    Person(std::string _name, std::string _surname, int _age) :
     name(_name)
    ,surname(_surname)
    ,age(_age)
    {}

 	std::string getName() const
 	{
 		return name;
 	}
 	void setName(std::string _name)
 	{
       name=_name;
 	}
 	void setAge( const int _age) 
 	{
 		age=_age;
 	}
 	int const getAge() const
 	{
 		return age;
 	}
 private:
 	int age{0};
 	std::string name{};
 	std::string	surname{};

};

struct  TestSuit : public testing::Test
{
    Person *man = nullptr;
    void SetUp()
    {
        std::cout<<"NUNO MIGUEL Test 3"<< std::endl;
        man = new Person("yazaa", "english", 34);
    }

    void TearDown()
    {
        std::cout<<"delete the memory allocated"<< std::endl;
        delete man;
    }
};

TEST_F(TestSuit, test3)   
{
    //std::cout<< "Print age: "<<man->getAge()<<std::endl;
    //ASSERT_EQ(man->getAge(),34);
    EXPECT_NE(man->getAge(),0);
}

TEST_F(TestSuit, test4)   
{
    EXPECT_NE(man->getAge(),130);
}

/*
TEST(Person, test1)
{
    Person Ismael;
    Ismael.setName("Alex");
    Ismael.setAge(22);
    EXPECT_EQ("Alex", Ismael.getName());
    EXPECT_EQ(22, Ismael.getAge());
}


 TEST(globalfunctions, test2)
 {
    int max {100};
    int min {10};
    EXPECT_GT(max,min);
 }

*/

int main(int argc, char ** argv)
{
    std::cout<<"STARTING TESTING WITH GOOGLE TEST FOR C++"<<std::endl;
    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

    /*
    Person *man = nullptr;
    man = new Person("yazaa", "english", 34);
    std::cout<<"The age is: "<< man->getAge()<<std::endl;
    delete man;
    return 0;
    */
}