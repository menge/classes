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

      cout << "Enter command ( [q]uit ): " << endl;
      cin >> command;

      switch (command) {
      case 'q':
         {
            done = true;
            break;
         }
      default:
         {
            cout << "Unrecognized Command, try again" << endl;
            break;
         }
      }
   }

   return EXIT_SUCCESS;
}
