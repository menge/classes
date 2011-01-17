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

   void LinkedList::insert(int value) {
   }

   void LinkedList::insertHead(int value) {
   }

   void LinkedList::append(int value) {
   }

   void LinkedList::appendTail(int value) {
   }

   void LinkedList::remove() {
   }

   bool LinkedList::isEmpty() {
      return false;
   }

   int* LinkedList::search(int pos) {
      return NULL;
   }

   int LinkedList::getNumElements() {
      return 0;
   }

   int* LinkedList::setHead() {
      if (head == NULL) {
         return NULL;
      }
      cursor = head;
      return &(cursor->data);
   }

   int* LinkedList::setTail() {
      if (tail == NULL) {
         return NULL;
      }
      cursor = tail;
      return &(cursor->data);
   }

   int* LinkedList::prev() {
      return NULL;
   }

   int* LinkedList::next() {
      return NULL;
   }

   void LinkedList::print() {
   }
}
