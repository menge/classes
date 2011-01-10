#include "Bank.h"

namespace net_oatsnet_class_datastructures {
   Bank::Bank() {
      for (int i = 0; i < Bank::MAX_ACCOUNTS; i++) {
         accountValid[i] = false;
      }
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
   }
}
