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
         head = NULL;
         tail = NULL;
         cursor = NULL;
         numElements = 0;
      }

      /* Account destructor
       * Pre-condition: None
       * Post-condition: Any allocated memory in object is freed
       */
      ~LinkedList() {
         while (!isEmpty()) {
            remove();
         }
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
         Node<T> *p = new Node<T>;
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


      /* Insert an element into the linked list before the head. Inserted element becomes the new cursor.
       * Pre-condition: None
       * Post-condition: element added in front of LinkedList
       *                 cursor becomes the added element
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      void insertHead(T value) {
         setHead();
         insert(value);
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
         Node<T> *p = new Node<T>;
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

      /* Append an element at the end of the linked list. Appended element becomes the new cursor.
       * Pre-condition: None
       * Post-condition: element added at end of LinkedList
       *                 cursor becomes the added element
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      void appendTail(T value) {
         setTail();
         append(value);
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
         Node<T> *deleteme = cursor;

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

      /* Returns true if no elements exist in LinkedList, false otherwise
       * Pre-condition: None
       * Post-condition: No private member variables are modified
       * Returns: true  - LinkedList is empty
                  false - LinkedList is not empty
       */
      bool isEmpty() {
         if (numElements == 0) {
            return true;
         }
         return false;
      }

      /* Searches through the linked list and returns a pointer to the data if found
       * Pre-condition: None
       * Post-condition: only cursor will be modified to point to the Node if value is found. 
                         If not found, cursor should remain the same as before the call
       * Returns: pointer pointing to the data if found, NULL if not found
       */
      T* search(T value) {
         for (Node<T> *p = head; p != NULL; p = p->next) {
            if (p->data == value) {
               /* we've found a match */
               cursor = p;
               return &(cursor->data);
            }
         }
         return NULL;
      }

      /* Returns the number of elements in the list
       * Pre-condition: None
       * Post-condition: no private variables will be modified
       * Returns: number of elements in list
       */
      int getNumElements() {
         return numElements;
      }

      /* Sets cursor to head and returns a pointer to the value it holds
       * Pre-condition: None
       * Post-condition: only cursor should be changed
       * Returns: a pointer to the value stored in the head Node (note: this can be NULL when list is empty)
       */
      T* setHead() {
         if (head == NULL) {
            return NULL;
         }

         cursor = head;
         return &(cursor->data);
      }

      /* Sets cursor to tail and returns a pointer to the value it holds
       * Pre-condition: None
       * Post-condition: only cursor should be changed
       * Returns: a pointer to the value stored in the tail Node (note: this can be NULL when list is empty)
       */
      T* setTail() {
         if (tail == NULL) {
            return NULL;
         }

         cursor = tail;
         return &(cursor->data);
      }

      /* Sets the cursor to what is previous to it, and returns a pointer to the value stored in the new cursor
       * Pre-condition: None
       * Post-condition: only cursor should be changed
       * Returns: a pointer to the data the new cursor points to (note: this can be NULL when list is empty or going prev from HEAD)
       */
      T* prev() {
         if (cursor == NULL) {
            return NULL;
         }

         cursor = cursor->prev;
         return &(cursor->data);
      }

      /* Sets the cursor to what is next to it, and returns a pointer to the value stored in the new cursor
       * Pre-condition: None
       * Post-condition: only cursor should be changed
       * Returns: a pointer to the data the new cursor points to (note: this can be NULL when list is empty or going next from TAIL)
       */
      T* next() {
         if (cursor == NULL) {
            return NULL;
         }

         cursor = cursor->next;
         return &(cursor->data);
      }

      /* Returns pointer to data of item that cursor points to. If cursor is not valid, will return NULL.
       * Pre-condition: None
       * Post-condition: no private variables will be modified
       * Returns: a pointer to the data that the cursor points to (note: this can be NULL when list is empty or when cursor is already NULL)
       */
      T* getCursorData() {
         if (cursor == NULL) {
            return NULL;
         }

         return &(cursor->data);
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
