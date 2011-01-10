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
      int found = -1;

      /* if passed name is invalid (empty string), return EMPTY_STRING */
      if (name == "") {
         return Bank::EMPTY_STRING;
      }

      /* see if name is duplicated or not, if so return DUPLICATE_NAME */
      for (int i = 0; i < Bank::MAX_ACCOUNTS; i++) {
         if ( (accountValid[i] == true) and (accounts[i].getName() == name)) {
            return Bank::DUPLICATE_NAME;
         }
      }

      /* find first instance of free account in array */
      for (int i = 0; i < Bank::MAX_ACCOUNTS; i++) {
         if (accountValid[i] == false) {
            found = i;
            break;
         }
      }

      /* if not enough space (not found), return TOO_MANY_ACCOUNTS */
      if (found == -1) {
         return Bank::TOO_MANY_ACCOUNTS;
      }

      /* create account, and set it to be valid */
      accounts[found] = Account(name, checkings, savings);
      accountValid[found] = true;

      /* everything is fine */
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
