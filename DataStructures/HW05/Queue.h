#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h> // for printf
#include <stdlib.h> // for NULL

#include "LinkedList.h"

using namespace std;

namespace net_oatsnet_class_datastructures {
   template <class T>
   class Queue {
   public:
      /* A queue is created using a LinkedList as its implementation
       * Pre-condition: None
       * Post-condition: A queue is ready to use
       */
      Queue() {
         ll = LinkedList<T>();
      }

      /* Account destructor
       * Pre-condition: None
       * Post-condition: Any allocated memory in object is freed
       */
      ~Queue() {
      }

      /* Insert an element into the linked list before the current cursor postition. Inserted element becomes the new cursor.
       * If cursor is NULL, item is inserted before head.
       * Pre-condition: None
       * Post-condition: element added in front of cursor
       *                 cursor becomes the added element
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      void enqueue(T value) {
         ll.appendTail(value);
      }

      /* Append an element into the linked list after the current cursor postition. Appended element becomes the new cursor.
       * If cursor is NULL, item is appended after tail.
       * Pre-condition: None
       * Post-condition: element added behind (next) the cursor
       *                 cursor becomes the added element
       *                 head and tail pointers are updated appropriately
       *                 numElements is updated appropriately
       */
      T dequeue() {
         T retval;

         if (isEmpty()) {
            // TODO: make a real exception?
            throw string("Cannot dequeue from empty list");
         }

         retval = *(ll.setHead());
         ll.remove();

         return retval;
      }

      /* Returns true if no elements exist in LinkedList, false otherwise
       * Pre-condition: None
       * Post-condition: No private member variables are modified
       * Returns: true  - LinkedList is empty
                  false - LinkedList is not empty
       */
      bool isEmpty() {
         return ll.isEmpty();
      }

      T* toArray() {
         T *newArray;

         if (getNumElements() == 0) {
            return NULL;
         }

         newArray = (T *) malloc(getNumElements() * sizeof(T));

         if (newArray == 0) {
            perror("Failed to allocate");
         }

         ll.setHead();
         for (int i = 0; i < getNumElements(); i++, ll.next()) {
            T *p = ll.getCursorData();
            newArray[i] = *p;
         }

         return newArray;
      }

      /* Returns the number of elements in the list
       * Pre-condition: None
       * Post-condition: no private variables will be modified
       * Returns: number of elements in list
       */
      int getNumElements() {
         return ll.getNumElements();
      }

   private:
      LinkedList<T> ll;
   };
}

#endif
