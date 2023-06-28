#ifndef MOCKBANKSERVICE_H
#define MOCKBANKSERVICE_H

#include <iostream>
#include "BankService.hpp"
#include "gmock/gmock.h"

class MockBankService : public BankService
{
  public:
   MOCK_METHOD( void, PrintMessage, () , (override));
   MOCK_METHOD( bool, UserLogin, (std::string user, std::string pwd), (override));
   MOCK_METHOD( void, GetValue, (double), (override));
   MOCK_METHOD( bool, UserLogOut, (), (override));
   MOCK_METHOD( double, ShowScore, (), (override));
   MOCK_METHOD( double, SendMoney, (double), (override));
};
#endif
