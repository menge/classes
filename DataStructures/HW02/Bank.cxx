#include "Bank.h"

#include <assert.h>
#include <stdio.h> // for printf

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
         if ( (accountValid[i] == true) && (accounts[i].getName() == name)) {
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
      /* if passed name is invalid (empty string), return EMPTY_STRING */
      if (name == "") {
         return Bank::EMPTY_STRING;
      }

      /* try to find and delete*/
      for (int i = 0; i < Bank::MAX_ACCOUNTS; i++) {
         if ( (accountValid[i] == true) && (name == accounts[i].getName()) ) {
            /* delete account by invalidating it making it free for further use */
            accountValid[i] = false;
            return Bank::NO_ERROR;
         }
      }

      /* did not find account, thus return ACCOUNT_NOT_FOUND */
      return Bank::ACCOUNT_NOT_FOUND;
   }

   int Bank::accountDeposit(string name, int accountType, unsigned long amount) {
      /* if passed name is invalid (empty string), return EMPTY_STRING */
      if (name == "") {
         return Bank::EMPTY_STRING;
      }

      /* try to find */
      for (int i = 0; i < Bank::MAX_ACCOUNTS; i++) {
         if ( (accountValid[i] == true) && (name == accounts[i].getName()) ) {
            unsigned int currAmount = 0;

            /* found the account, now get the amount */
            if (accountType == Account::CHECKINGS) {
               currAmount = accounts[i].getCheckingsAmount();
            }
            else if (accountType == Account::SAVINGS) {
               currAmount = accounts[i].getSavingsAmount();
            }
            else {
               /* WE SHOULD NEVER GET HERE */
               assert(false);
            }

            /* now check for overflow */
            if (currAmount + amount < currAmount) {
               return Bank::OVERFLOW;
            }

            /* no overflow, so go ahead and make deposit and return*/
            accounts[i].deposit(accountType, amount);
            return Bank::NO_ERROR;
         }
      }

      /* didn't find the account */
      return Bank::ACCOUNT_NOT_FOUND;
   }

   int Bank::accountWithdraw(string name, int accountType, unsigned long amount) {
      /* if passed name is invalid (empty string), return EMPTY_STRING */
      if (name == "") {
         return Bank::EMPTY_STRING;
      }

      /* try to find */
      for (int i = 0; i < Bank::MAX_ACCOUNTS; i++) {
         if ( (accountValid[i] == true) && (name == accounts[i].getName()) ) {
            unsigned int currAmount = 0;

            /* found the account, now get the amount */
            if (accountType == Account::CHECKINGS) {
               currAmount = accounts[i].getCheckingsAmount();
            }
            else if (accountType == Account::SAVINGS) {
               currAmount = accounts[i].getSavingsAmount();
            }
            else {
               /* WE SHOULD NEVER GET HERE */
               assert(false);
            }

            /* now check for overflow */
            if (currAmount < amount) {
               return Bank::INSUFFICIENT_FUNDS;
            }

            /* no overflow, so go ahead and make deposit and return*/
            accounts[i].withdraw(accountType, amount);
            return Bank::NO_ERROR;
         }
      }

      /* didn't find the account */
      return Bank::ACCOUNT_NOT_FOUND;
   }

   unsigned long long Bank::getTotalAccountValues() {
      unsigned long long total = 0;
      for (int i = 0; i < Bank::MAX_ACCOUNTS; i++) {
         if (accountValid[i] == true) {
            total += accounts[i].getTotalAccountValue();
         }
      }

      return total;
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
