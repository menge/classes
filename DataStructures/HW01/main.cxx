#include <cstdlib> // for EXIT_SUCCESS
#include <iostream> // for cout
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
