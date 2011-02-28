#ifndef STACK_H
#define STACK_H

#include <stdio.h> // for printf
#include <stdlib.h> // for NULL

#include "LinkedList.h"

using namespace std;

namespace net_oatsnet_class_datastructures {
   template <class T>
   class Stack {
   public:
      /* A stack is created using a LinkedList as its implementation
       * Pre-condition: None
       * Post-condition: A stack is ready to use
       */
      Stack() {
      }

      /* Account destructor
       * Pre-condition: None
       * Post-condition: Any allocated memory in object is freed
       */
      ~Stack() {
      }

      /* Pushes an element into the stack (at the head)
       * Pre-condition: None
       * Post-condition: None
       */
      void push(T value) {
      }

      /* Element is popped and returned from head of stack.
       * Pre-condition: There must be at least one element in list before attempting to pop. 
                        If this condition is not met, an exception is to be thrown
                        (currently string("Cannot remove from empty list"))
       * Post-condition: element is dequeued and returned
       */
      T pop() {
         T retval = this->pop();
         return retval;
      }

      /* Returns true if no elements exist in stack, false if otherwise
       * Pre-condition: None
       * Post-condition: None
       * Returns: true  - stack is empty
                  false - stack is not empty
       */
      bool isEmpty() {
         return true;
      }


      /* Returns a pointer to an allocated array which contains the elements in the Stack
       * with the head starting at index 0, and the last element (tail) at the last index.
       * If Stack is empty returns null pointer.
       * Pre-condition: None
       * Post-condition: Stack is untouched, responsibility of caller to deallocate memory with free
       * Returns: Null if there are no elements in stack
       *          pointer to array T is returned
       */
      T* toArray() {
         return NULL;
      }

      /* Returns the number of elements in the stack
       * Pre-condition: None
       * Post-condition: Queue is not modified
       * Returns: number of elements in queue
       */
      int getNumElements() {
         return 0;
      }

   private:
      LinkedList<T> ll;
   };
}

#endif
