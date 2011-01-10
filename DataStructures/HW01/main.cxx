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
      cout << "Enter command: " << endl;
      done = true;
   }

   return EXIT_SUCCESS;
}
