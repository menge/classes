#include <stdlib.h> // for NULL

#include "LinkedList.h"

namespace net_oatsnet_class_datastructures {
   LinkedList::LinkedList() {
      head = NULL;
      tail = NULL;
      cursor = NULL;
      numElements = 0;
   }

   LinkedList::~LinkedList() {
   }

   void LinkedList::insert(int pos, int value) {
   }

   int LinkedList::remove(int pos) {
      return 0;
   }

   int* LinkedList::search(int pos) {
      return NULL;
   }

   int LinkedList::getNumElements() {
      return 0;
   }

   int* LinkedList::getElement(int pos) {
      return NULL;
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
