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

      /* no-argument constructor
       * Pre-condition: None
       * Post-condition: object's members variables are set to default values ("", 0s)
       */
      Account();

      /* Constructor with passed variables
       * Pre-condition: None
       * Post-condition: object's members variables are set to what has been passed in
       * Params:
       *    name           : the account name
       *    checkingsAmount: the amount in checkings account
       *    savingsAmount  : the amount in savings account
       */
      Account(string name, unsigned long checkingsAmount, unsigned long savingsAmount);

      /* Account destructor
       * Pre-condition: None
       * Post-condition: Any allocated memory in object is freed
       */
      ~Account();

      /* Deposits into an account
       * Pre-condition: accountType is valid, and added amount won't cause overflow
       * Post-condition: correct account gets the correct amount deposited to it
       * Params:
       *   accountType: either Account:CHECKINGS or Account:SAVINGS
       *   amount     : amount to deposit
       */
      void deposit(int accountType, unsigned long amount);

      /* Withdraws from an account
       * Pre-condition: accountType is valid, and subtracted amount won't cause underflow
       * Post-condition: correct account gets the correct amount withdrawn from it
       * Params:
       *   accountType: either Account:CHECKINGS or Account:SAVINGS
       *   amount     : amount to deposit
       */
      void withdraw(int accountType, unsigned long amount);

      /* Gets total account value (note overflow can't happen as we're returning ULL)
       * Pre-condition: none
       * Post-condition: returns the total amount of both checkings and savings
       * Returns:
       *    the amount of both accounts added together in ULL
       */
      unsigned long long getTotalAccountValue();

      /* getter function for private varaible checkingsAmount
       * Pre-condition: none
       * Post-condition: none
       * Returns:
       *    the private variable checkingsAmount
       */
      unsigned long getCheckingsAmount();

      /* getter function for private varaible savingsAmount
       * Pre-condition: none
       * Post-condition: none
       * Returns:
       *    the private variable savingsAmount
       */
      unsigned long getSavingsAmount();

      /* getter function for private varaible name
       * Pre-condition: none
       * Post-condition: none
       * Returns:
       *    the private variable name
       */
      string getName();

   private:
      /* name of the account holder */
      string name;

      /* amount in checkings account */
      unsigned long checkingsAmount;

      /* amount in savings account */
      unsigned long savingsAmount;
   };
}

#endif
