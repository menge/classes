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
      while (!isEmpty()) {
         remove();
      }
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
      Node *p = new Node;
      p->data = value;

      /* if cursor is NULL, try to set it to tail */
      if (cursor == NULL) {
         cursor = tail;
      }

      /* if cursor is still NULL, then we have an empty list */
      if (cursor == NULL) {
         head = p;
         tail = p;
         p->next = NULL;
         p->prev = NULL;
      }
      /* cursor exists... append after it */
      else {
         p->next = cursor->next;
         p->prev = cursor;

         /* check to see if p is the new tail */
         if (p->next == NULL) {
            tail = p;
         }
         else {
            p->next->prev = p;
         }

         cursor->next = p;
      }

      /* p is our new cursor */
      cursor = p;

      /* we've added, so update count */
      numElements += 1;
   }

   void LinkedList::appendTail(int value) {
      setTail();
      append(value);
   }

   void LinkedList::remove() {
      if (numElements == 0) {
         /* nothing to delete, so we're outta here */
         return;
      }

      /* deleting last element */
      if (numElements == 1) {
         delete cursor;

         head = NULL;
         tail = NULL;
         cursor = NULL;
         numElements = 0;
         return;
      }

      /* there's at least 2 elemets left */
      if (cursor == NULL) {
         cursor = tail;
      }

      //Save cursor to be deleted later
      Node *deleteme = cursor;

      // reconfigure pointers and assign new cursor
      if (cursor == head) {
         head = cursor->next;
         cursor->next->prev = NULL;

         cursor = head;
      }
      else if (cursor == tail) {
         tail = cursor->prev;
         cursor->prev->next = NULL;

         cursor = tail;
      }
      else {
         cursor->prev->next = cursor->next;
         cursor->next->prev = cursor->prev;

         cursor = cursor->next;
      }

      /* now we can delete node and update count */
      delete deleteme;
      numElements -= 1;
   }

   bool LinkedList::isEmpty() {
      if (numElements == 0) {
         return true;
      }
      return false;
   }

   int* LinkedList::search(int value) {
      for (Node *p = head; p != NULL; p = p->next) {
         if (p->data == value) {
            /* we've found a match */
            cursor = p;
            return &(cursor->data);
         }
      }
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
