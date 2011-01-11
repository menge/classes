#include <cstdlib> // for EXIT_SUCCESS
#include <iostream> // for cout
#include "Account.h"
#include "Bank.h"

using namespace std;
using namespace net_oatsnet_class_datastructures;

int main(int argc, char **argv) {
   Bank myBank = Bank();
   bool done = false;

   cout << "Welcome to the Bank!!" << endl;

   while (!done) {
      char command;

      cout << "Enter command ( [q]uit, [a]dd account, [d]elete account, [g]et total value, d[e]posit, [w]ithdraw, [p]rint debug): " << endl;
      cin >> command;

      switch (command) {
      case 'a':
      case 'A':
         {
            int result;
            unsigned long checkings;
            unsigned long savings;
            string name;

            /* get information about adding an account */
            cout << "Please enter name of account: "  << endl;
            cin >> name;
            cout << "Please enter the initial amount of checkings: " << endl;
            cin >> checkings;
            cout << "Please enter the initial amount of savings: " << endl;
            cin >> savings;

            /* add account and check for errors */
            result = myBank.addAccount(name, checkings, savings);
            switch (result) {
            case Bank::TOO_MANY_ACCOUNTS:
               {
                  cerr << "!!!There is no room for new accounts" << endl;
                  break;
               }
            case Bank::DUPLICATE_NAME:
               {
                  cerr << "!!!Account by name [" << name << "] already exists" << endl;
                  break;
               }
            case Bank::EMPTY_STRING:
               {
                  cerr << "!!!Cannot enter account with no name information" << endl;
                  break;
               }
            case Bank::NO_ERROR:
               {
                  /* everything is fine, nothing needed */
                  break;
               }
            default:
               {
                  cerr << "!!!unrecognized return value" << endl;
                  break;
               }
            }

            break;
         }
      case 'd':
      case 'D':
         {
            string name;
            int result;

            /* get information to delete from account */
            cout << "Please enter name of account to delete:" << endl;
            cin >> name;

            /* remove account and check for errors */
            result = myBank.deleteAccount(name);
            switch (result) {
            case Bank::ACCOUNT_NOT_FOUND:
               {
                  cerr << "!!!Account by name [" << name << "] not found" << endl;
                  break;
               }
            case Bank::EMPTY_STRING:
               {
                  cerr << "!!!Cannot enter account with no name information" << endl;
                  break;
               }
            case Bank::NO_ERROR:
               {
                  /* everything is fine, nothing needed */
                  break;
               }
            default:
               {
                  cerr << "!!!unrecognized return value" << endl;
                  break;
               }
            }

            break;
         }
      case 'e':
      case 'E':
         {
            string name;
            char checkingsOrSavings;
            unsigned int amount;
            int accountType;
            bool okay = true;

            cout << "Please enter name of account to deposit to: " << endl;
            cin >> name;
            cout << "Please enter the type of account [(c)heckings, (s)avings]: " << endl;
            cin >> checkingsOrSavings;
            cout << "Please enter the amount: " << endl;
            cin >> amount;

            switch (checkingsOrSavings) {
            case 'c':
            case 'C':
               {
                  accountType = Account::CHECKINGS;
                  break;
               }
            case 's':
            case 'S':
               {
                  accountType = Account::SAVINGS;
                  break;
               }
            default:
               {
                  cerr << "Invalid entry for account type" << endl;
                  okay = false;
                  break;
               }
            }

            if (okay) {
               int result;

               result = myBank.accountDeposit(name, accountType, amount);

               switch (result) {
               case Bank::ACCOUNT_NOT_FOUND:
                  {
                     cerr << "!!!Account by name [" << name << "] not found" << endl;
                     break;
                  }
               case Bank::EMPTY_STRING:
                  {
                     cerr << "!!!Cannot enter account with no name information" << endl;
                     break;
                  }
               case Bank::OVERFLOW:
                  {
                     cerr << "!!!Adding amount requested would result in overflow" << endl;
                     break;
                  }
               case Bank::NO_ERROR:
                  {
                     /* everything is fine, nothing needed */
                     break;
                  }
               default:
                  {
                     cerr << "!!!unrecognized return value" << endl;
                     break;
                  }
               }
            }
            break;
         }
      case 'g':
      case 'G':
         {
            cout << "Bank has a total of in all active accounts: " << myBank.getTotalAccountValues() << endl;
            break;
         }
      case 'p':
      case 'P':
         {
            myBank.printAllAccounts();
            break;
         }
      case 'q':
      case 'Q':
         {
            done = true;
            break;
         }
      default:
         {
            cerr << "!!!Unrecognized Command, try again" << endl;
            break;
         }
      }
   }

   return EXIT_SUCCESS;
}
