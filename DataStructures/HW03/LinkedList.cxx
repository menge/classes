#include <stdio.h> // for printf
#include <stdlib.h> // for NULL

#include "LinkedList.h"

namespace net_oatsnet_class_datastructures {
   LinkedList::LinkedList() {
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
      return true;
   }

   int* LinkedList::search(int value) {
      return NULL;
   }

   int LinkedList::getNumElements() {
      return 0;
   }

   int* LinkedList::setHead() {
      return NULL;
   }

   int* LinkedList::setTail() {
      return NULL;
   }

   int* LinkedList::prev() {
      return NULL;
   }

   int* LinkedList::next() {
      return NULL;
   }

   int* LinkedList::getCursorData() {
      return NULL;
   }

   void LinkedList::print() {
      char header[] = "================================================================================";

      printf("%s\n", header);
      printf("LinkedList       : %10p\n", this);
      printf("this->head       : %10p\n", head);
      printf("this->tail       : %10p\n", tail);
      printf("this->cursor     : %10p\n", cursor);
      printf("this->numElements: %10i\n", numElements);
      printf("%s\n", header);

      for (Node *p = head; p != NULL; p = p->next) {
         printf("%8s%30s\n", "", "+----------------------------+");
         printf("%8s%1s%18s%10p%1s\n", "", "|", "Node:", p, "|");
         printf("%8s%30s\n", "", "+----------------------------+");
         printf("%8s%1s%18s%10i%1s\n", "", "|", "data:", p->data, "|");
         printf("%8s%1s%18s%10p%1s\n", "", "|", "prev:", p->prev, "|");
         printf("%8s%1s%18s%10p%1s\n", "", "|", "next:", p->next, "|");
         printf("%8s%30s\n", "", "+----------------------------+");
         printf("\n");
      }
   }
}
