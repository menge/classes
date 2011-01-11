#ifndef BANK_H
#define BANK_H

#include <string>
#include "Account.h"

using namespace std;

namespace net_oatsnet_class_datastructures {
   class Bank {
   public:
      enum BankError {
         NO_ERROR           = 0,
         DUPLICATE_NAME     = -1,
         OVERFLOW           = -2,
         TOO_MANY_ACCOUNTS  = -3,
         ACCOUNT_NOT_FOUND  = -4,
         EMPTY_STRING       = -5,
         INSUFFICIENT_FUNDS = -6
      };

      /* Pre-condition: None
       * Post-condition: Bank is created with no accounts
       */
      Bank();

      /* Pre-condition: None
       * Post-condition: All allocated memory from Bank is freed
       */
      ~Bank();

      /* Pre-condition: None
       * Post-condition: Account is created if no errors exist, and NO_ERROR is returned
       * Params:
       *    string        name     : the account the name is filed under
       *    unsigned long checkings: the initial amount in the checkings account
       *    unsigned long savings  : the initial amount in the savings account
       * Returned error-conditions:
       *    TOO_MANY_ACCOUNTS: There is not enough room to add another account (exceeds
       *                                 MAX_ACCOUNTS)
       *    DUPLICATE_NAME   : a duplicate name already exists in a previous account
       *    EMPTY_STRING     : cannot add a name that is empty (e.g. "")
       */
      int addAccount(string name, unsigned long checkings, unsigned long savings);

      /* Pre-condition: None
       * Post-condition: Account with matching name is deleted, returns NO_ERROR
       * Params:
       *    string        name     : the account the name is filed under
       * Returned error-conditions:
       *    ACCOUNT_NOT_FOUND: Given name is not in list of accounts
       *    EMPTY_STRING     : cannot search for an empty name
       */
      int deleteAccount(string name);

      /* Pre-condition:
       *    None
       * Post-condition: 
       *    The total value of all account types (checkings + savings) for every
       *    account that is held at the Bank is returned
       */
      unsigned long long getTotalAccountValues();

      /* Pre-condition:
       *    accountType is using AccountType enum, and does not deviate from it
       * Post-condition: 
       *    Account is credited with the correct amount if no errors, and NO_ERROR is returned
       *    If an error exists, nothing is to change
       * Params:
       *    string        name       : the account the name is filed under
       *    int           accountType: AccountType.CHECKINGS, AccountType.SAVINGS
       *    unsigned long amount     : amount the account is to be credited
       * Returned error-conditions:
       *    ACCOUNT_NOT_FOUND: Given name is not in list of accounts
       *    EMPTY_STRING     : cannot search for an empty name
       *    OVERFLOW         : requested operation would result in an overflow
       */
      int accountDeposit(string name, int accountType, unsigned long amount);

      /* Pre-condition:
       *    accountType is using AccountType enum, and does not deviate from it
       * Post-condition: 
       *    Account is debited with the correct amount if no errors, and BankERror.NO_ERROR is returned
       *    If an error exists, nothing is to change
       * Params:
       *    string        name       : the account the name is filed under
       *    int           accountType: AccountType.CHECKINGS, AccountType.SAVINGS
       *    unsigned long amount     : amount the account is to be credited
       * Returned error-conditions:
       *    ACCOUNT_NOT_FOUND : Given name is not in list of accounts
       *    EMPTY_STRING      : cannot search for an empty name
       *    INSUFFICIENT_FUNDS: requested accounts does not have enough funds
       */
      int accountWithdraw(string name, int accountType, unsigned long amount);

      /* Pre-condition: None
       * Post-condition: debugging information is printed to stdout
       */
      void printAllAccounts();

   private:
      /* describes number of accounts a Bank can hold */
      static const int MAX_ACCOUNTS = 50;

      /* Allocates room for the number of accounts */
      Account accounts[Bank::MAX_ACCOUNTS];

      /* current number of active accounts */
      bool accountValid[Bank::MAX_ACCOUNTS];
   };
}

#endif
