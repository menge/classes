#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h> // for printf
#include <stdlib.h> // for NULL

using namespace std;

namespace net_oatsnet_class_datastructures {
   template <class T>
   struct Node {
      T data;
      Node<T> *next;
      Node<T> *prev;
   };

   template <class T>
   class LinkedList {
   public:
      /* Linked List constructor will create a linked list with no elements in it
       * Pre-condition: None
       * Post-condition: object's members variables are set to default values ("", 0s)
       */
      LinkedList() {
      }

      /* Account destructor
       * Pre-condition: None
       * Post-condition: Any allocated memory in object is freed
       */
      ~LinkedList() {
      }

      /* Insert an element into the linked list before the current cursor postition. Inserted element becomes the new cursor.
       * If cursor is NULL, item is inserted before head.
       * Pre-condition: None
       * Post-condition: element added in front of cursor
       *                 cursor becomes the added element
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      void insert(T value) {
      }


      /* Insert an element into the linked list before the head. Inserted element becomes the new cursor.
       * Pre-condition: None
       * Post-condition: element added in front of LinkedList
       *                 cursor becomes the added element
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      void insertHead(T value) {
      }

      /* Append an element into the linked list after the current cursor postition. Appended element becomes the new cursor.
       * If cursor is NULL, item is appended after tail.
       * Pre-condition: None
       * Post-condition: element added behind (next) the cursor
       *                 cursor becomes the added element
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      void append(T value) {
      }

      /* Append an element at the end of the linked list. Appended element becomes the new cursor.
       * Pre-condition: None
       * Post-condition: element added at end of LinkedList
       *                 cursor becomes the added element
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      void appendTail(T value) {
      }

      /* Removes the current cursor. Cursor then becomes the next in the list if not null, otherwise, becomes previous.
       * When removing the last element, cursor reverts to being NULL. If no elements left, and cursor is NULL, performs nothing.
       * If cursor is NULL, remove tail.
       * Pre-condition: None
       * Post-condition: The Node pointed to by the cursor is removed. If the next Node pointed to by the removed cursor is not NULL,
       *                 then it becomes the new cursor. Otherwise, the previous Node becomes the new cursor, even if NULL (meaning
       *                 that the LinkedList is empty.
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      void remove() {
      }

      /* Returns true if no elements exist in LinkedList, false otherwise
       * Pre-condition: None
       * Post-condition: No private member variables are modified
       * Returns: true  - LinkedList is empty
                  false - LinkedList is not empty
       */
      bool isEmpty() {
         return true;
      }

      /* Searches through the linked list and returns a pointer to the data if found
       * Pre-condition: None
       * Post-condition: only cursor will be modified to point to the Node if value is found. 
                         If not found, cursor should remain the same as before the call
       * Returns: pointer pointing to the data if found, NULL if not found
       */
      T* search(T value) {
         return NULL;
      }

      /* Returns the number of elements in the list
       * Pre-condition: None
       * Post-condition: no private variables will be modified
       * Returns: number of elements in list
       */
      int getNumElements() {
         return 0;
      }

      /* Sets cursor to head and returns a pointer to the value it holds
       * Pre-condition: None
       * Post-condition: only cursor should be changed
       * Returns: a pointer to the value stored in the head Node (note: this can be NULL when list is empty)
       */
      T* setHead() {
         return NULL;
      }

      /* Sets cursor to tail and returns a pointer to the value it holds
       * Pre-condition: None
       * Post-condition: only cursor should be changed
       * Returns: a pointer to the value stored in the tail Node (note: this can be NULL when list is empty)
       */
      T* setTail() {
         return NULL;
      }

      /* Sets the cursor to what is previous to it, and returns a pointer to the value stored in the new cursor
       * Pre-condition: None
       * Post-condition: only cursor should be changed
       * Returns: a pointer to the data the new cursor points to (note: this can be NULL when list is empty or going prev from HEAD)
       */
      T* prev() {
         return NULL;
      }

      /* Sets the cursor to what is next to it, and returns a pointer to the value stored in the new cursor
       * Pre-condition: None
       * Post-condition: only cursor should be changed
       * Returns: a pointer to the data the new cursor points to (note: this can be NULL when list is empty or going next from TAIL)
       */
      T* next() {
         return NULL;
      }

      /* Returns pointer to data of item that cursor points to. If cursor is not valid, will return NULL.
       * Pre-condition: None
       * Post-condition: no private variables will be modified
       * Returns: a pointer to the data that the cursor points to (note: this can be NULL when list is empty or when cursor is already NULL)
       */
      T* getCursorData() {
         return NULL;
      }

      /* prints out diagnostic information about list
       * Pre-condition: None
       * Post-condition: no private variables will be modified
       */
      void print() {
         char header[] = "================================================================================";

         printf("%s\n", header);
         printf("LinkedList       : %10p\n", this);
         printf("this->head       : %10p\n", head);
         printf("this->tail       : %10p\n", tail);
         printf("this->cursor     : %10p\n", cursor);
         printf("this->numElements: %10i\n", numElements);
         printf("%s\n", header);

         for (Node<T> *p = head; p != NULL; p = p->next) {
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

   private:
      Node<T> *head;
      Node<T> *tail;
      Node<T> *cursor;
      int numElements;
   };
}

#endif
