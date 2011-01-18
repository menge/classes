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

      cout << "Enter command ([q]uit, [p]rint, [i]nsert): " << endl;
      cin >> command;

      switch (command) {
      case 'i':
         {
            int num;

            cout << "Enter number to insert" << endl;
            cin >> num;

            myll.insert(num);
            break;
         }
      case 'p':
      case 'P':
         {
            myll.print();
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
