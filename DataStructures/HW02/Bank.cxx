#include "Bank.h"

#include <assert.h>
#include <stdio.h> // for printf

namespace net_oatsnet_class_datastructures {
   Bank::Bank() {
   }

   Bank::~Bank() {
   }

   int Bank::addAccount(string name, unsigned long checkings, unsigned long savings) {
      return Bank::NO_ERROR;
   }

   int Bank::deleteAccount(string name) {
      return Bank::NO_ERROR;
   }

   int Bank::accountDeposit(string name, int accountType, unsigned long amount) {
      return Bank::NO_ERROR;
   }

   int Bank::accountWithdraw(string name, int accountType, unsigned long amount) {
      return Bank::NO_ERROR;
   }

   unsigned long long Bank::getTotalAccountValues() {
      return 0;
   }

   void Bank::printAllAccounts() {
      for (int i = 0; i < Bank::MAX_ACCOUNTS; i++) {
         if (accountValid[i] == false) {
            printf("account[%4u] is invalid\n", i);
         }
         else {
            printf("account[%4u] is valid\n", i);
            printf("account[%4u].name            = %s\n", i, accounts[i].getName().c_str());
            printf("account[%4u].checkingsAmount = %lu\n", i, accounts[i].getCheckingsAmount());
            printf("account[%4u].savingsAmount   = %lu\n", i, accounts[i].getSavingsAmount());
            printf("account[%4u].totalAmount     = %llu\n", i, accounts[i].getTotalAccountValue());
         }
      }
   }
}
