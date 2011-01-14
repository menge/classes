#include <cstdlib> // for EXIT_SUCCESS
#include <iostream> // for cout
#include "LinkedList.h"

using namespace std;
using namespace net_oatsnet_class_datastructures;

int main(int argc, char **argv) {
   LinkedList myll = LinkedList();
   bool done = false;

   cout << "Welcome to the Linked List!!" << endl;

   while (!done) {
      char command;

      cout << "Enter command ([q]uit): " << endl;
      cin >> command;

      switch (command) {
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
