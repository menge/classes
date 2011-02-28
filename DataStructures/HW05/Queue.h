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
      }

      /* Account destructor
       * Pre-condition: None
       * Post-condition: Any allocated memory in object is freed
       */
      ~Queue() {
      }

      /* Enqueues an element into the queue (at the tail)
       * Pre-condition: None
       * Post-condition: None
       */
      void enqueue(T value) {
      }

      /* Element is dequeued and returned from head of queue.
       * Pre-condition: There must be at least one element in list before attempting to dequeue. 
                        If this condition is not met, an exception is to be thrown
                        (currently string("Cannot dequeue from empty list"))
       * Post-condition: element is dequeued and returned
       */
      T dequeue() {
         T asdf = this->dequeue();
         return asdf;
      }

      /* Returns true if no elements exist in Queue, false if otherwise
       * Pre-condition: None
       * Post-condition: None
       * Returns: true  - Queue is empty
                  false - Queue is not empty
       */
      bool isEmpty() {
         return false;
      }


      /* Returns a pointer to an allocated array which contains the elements in the Queue
       * with the head starting at index 0, and the last element (tail) at the last index.
       * If Queue is empty returns null pointer.
       * Pre-condition: None
       * Post-condition: Queue is untouched, responsibility of caller to deallocate memory with free
       * Returns: Null if there are no elements in Queue
       *          pointer to array T is returned
       */
      T* toArray() {
         return NULL;
      }

      /* Returns the number of elements in the queue
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
