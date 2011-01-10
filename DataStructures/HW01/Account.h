#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

namespace net_oatsnet_class_datastructures {
   class Account {
   public:
      enum AccountType {
         CHECKINGS,
         SAVINGS
      };
      Account();
      Account(string name, unsigned long checkingsAmount, unsigned long savingsAmount);
      ~Account();
      void deposit(int accountType, unsigned long amount);
      void withdraw(int accountType, unsigned long amount);
      unsigned long long getTotalAccountValue();
      string getName();
   private:
      string name;
      unsigned long checkingsAmount;
      unsigned long savingsAmount;
   };
}

#endif
