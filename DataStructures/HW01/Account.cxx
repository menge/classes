#include <assert.h>

#include "Account.h"

namespace net_oatsnet_class_datastructures {
   Account::Account() {
      name = "";
      checkingsAmount = 0;
      savingsAmount = 0;
   }

   Account::Account(string name, unsigned long checkingsAmount, unsigned long savingsAmount) {
      this->name = name;
      this->checkingsAmount = checkingsAmount;
      this->savingsAmount = savingsAmount;
   }

   Account::~Account() {
   }

   void Account::deposit(int accountType, unsigned long amount) {
      switch(accountType) {
      case Account::CHECKINGS:
         {
            checkingsAmount += amount;
            break;
         }
      case Account::SAVINGS:
         {
            savingsAmount += amount;
            break;
         }
      default:
         {
            assert(false);
            break;
         }
      }
   }

   void Account::withdraw(int accountType, unsigned long amount) {
      switch(accountType) {
      case Account::CHECKINGS:
         {
            checkingsAmount -= amount;
            break;
         }
      case Account::SAVINGS:
         {
            savingsAmount -= amount;
            break;
         }
      default:
         {
            assert(false);
            break;
         }
      }
   }

   unsigned long long Account::getTotalAccountValue() {
      return (unsigned long long) checkingsAmount + (unsigned long long) savingsAmount;
   }

   unsigned long Account::getCheckingsAmount() {
      return checkingsAmount;
   }

   unsigned long Account::getSavingsAmount() {
      return savingsAmount;
   }

   string Account::getName() {
      return name;
   }
}
