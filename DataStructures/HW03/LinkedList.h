#ifndef LINKED_LIST_H
#define LINKED_LIST_H

using namespace std;

namespace net_oatsnet_class_datastructures {
   struct Node {
      int data;
      Node *next;
      Node *prev;
   };

   class LinkedList {
   public:
      /* Linked List constructor will create a linked list with no elements in it
       * Pre-condition: None
       * Post-condition: object's members variables are set to default values ("", 0s)
       */
      LinkedList();

      /* Account destructor
       * Pre-condition: None
       * Post-condition: Any allocated memory in object is freed
       */
      ~LinkedList();

      // TODO operator overloading (copy constructor... equals?)

      /* Insert an element into the linked list at directed position
       * Pre-condition: None
       * Post-condition: element added in position as directed
       */
      void insert(int pos, int value);

      int remove(int pos);

      int* getElement(int pos);

      int getNumElements();

      Node* begin();

      Node* end();

      Node* last();

      Node* next();

      void print();
   private:
      Node *head;
      Node *tail;
      Node *currPtr;
      int numElements;
   };
}

#endif
