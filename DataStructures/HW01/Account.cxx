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
   }

   void Account::withdraw(int accountType, unsigned long amount) {
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
