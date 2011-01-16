#include <stdlib.h> // for NULL

#include "LinkedList.h"

namespace net_oatsnet_class_datastructures {
   LinkedList::LinkedList() {
      head = NULL;
      tail = NULL;
      currPtr = NULL;
      numElements = 0;
   }

   LinkedList::~LinkedList() {
   }

   void LinkedList::insert(int pos, int value) {
   }

   int LinkedList::remove(int pos) {
      return 0;
   }

   int LinkedList::getNumElements() {
      return 0;
   }

   Node* LinkedList::begin() {
      return NULL;
   }

   Node* LinkedList::end() {
      return NULL;
   }

   Node* LinkedList::next() {
      return NULL;
   }
}
