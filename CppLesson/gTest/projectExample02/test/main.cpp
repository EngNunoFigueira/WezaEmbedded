#include "Foo.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockBankService.hpp"
using namespace std;
using ::testing::NiceMock;
using ::testing::AtLeast;

struct TestClass : public testing::Test
{
  Foo *_foo = nullptr;
  void SetUp()
  {
    _foo = new Foo();
    _foo->SetCounterValue(10);
    std::cout << "update the value to compare" << std::endl;
  }
  void TearDown()
  {
    std::cout << "clean the counter after finish the test " << std::endl;
    delete _foo;
  }
};


TEST(TestClasses, DISABLED_Parameters)
{
  Foo _foo;
  EXPECT_EQ(100, _foo.GetMax());
}


TEST_F(TestClass, DISABLED_CheckCounterValue)
{
  EXPECT_EQ(10, _foo->GetMax());
}


TEST(Mock, testMock)
{
  // arrangement
  NiceMock<MockBankService> mockServices;
  Foo john(mockServices);
  
  /*
    ON_CALL(mockServices, PrintMessage())
    .WillByDefault(testing::Return());
    */

  EXPECT_CALL(mockServices, PrintMessage())
  .Times(AtLeast(1));
  /*
    ON_CALL(mockServices, UserLogin("ekumbi", "salas519"))
    .WillByDefault(testing::Return("Nuno Bacano"));


    ON_CALL(mockServices, ShowScore())
    .WillByDefault(testing::Return(100.00));
    */

  // Action
// double getScore = john.ShowScore();
  //std::cout<<"The account score is "<< getScore<<"US $ "<<std::endl;
  // Assert
  //EXPECT_EQ(100.00, getScore);

  EXPECT_CALL(mockServices, UserLogin("ekumbi", "salas519"))
  .Times(1)
  .WillOnce(testing::Return(true));

  EXPECT_CALL(mockServices, ShowScore())
  .Times(1)
  .WillOnce(testing::Return(true))
   .WillRepeatedly(testing::DoDefault());


  john.PrintMessage("START CALL THE FOO OBJECT");
  bool case01 = john.BankLogin();
  bool case02 = john.ShowScore();
  EXPECT_TRUE(case01);
  EXPECT_TRUE(case02);

}

int main(int argc, char ** argv)
{
  std::cout << "STARTING TESTING WITH GOOGLE TEST FOR C++ & CMAKE compile settings" << std::endl;
  testing::InitGoogleTest(&argc, argv);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
