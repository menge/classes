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
#if 0
      while (!isEmpty()) {
         remove();
      }
#endif
   }

   void LinkedList::insert(int value) {
      Node *p = new Node;
      p->data = value;

      /* if cursor is NULL, try to set it to head */
      if (cursor == NULL) {
         cursor = head;
      }

      /* if cursor is still NULL, then we have an empty list */
      if (cursor == NULL) {
         head = p;
         tail = p;
         p->next = NULL;
         p->prev = NULL;
      }
      /* cursor exists... insert in front of it */
      else {
         p->next = cursor;
         p->prev = cursor->prev;
         
         /* is p is the new head */
         if (p->prev == NULL) {
            head = p;
         }
         else {
            p->prev->next = p;
         }

         cursor->prev = p;
      }

      /* p is our new cursor */
      cursor = p;

      /* we've added, so update count */
      numElements += 1;
   }

   void LinkedList::insertHead(int value) {
      setHead();
      insert(value);
   }

   void LinkedList::append(int value) {
   }

   void LinkedList::appendTail(int value) {
      setTail();
      append(value);
   }

   void LinkedList::remove() {
   }

   bool LinkedList::isEmpty() {
      if (numElements == 0) {
         return true;
      }
      return false;
   }

   int* LinkedList::search(int pos) {
      return NULL;
   }

   int LinkedList::getNumElements() {
      return numElements;
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
      if (cursor == NULL) {
         return NULL;
      }

      cursor = cursor->prev;
      return &(cursor->data);
   }

   int* LinkedList::next() {
      if (cursor == NULL) {
         return NULL;
      }

      cursor = cursor->next;
      return &(cursor->data);
   }

   void LinkedList::print() {
   }
}
