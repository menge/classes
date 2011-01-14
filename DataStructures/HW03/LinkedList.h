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
      /* no-argument constructor
       * Pre-condition: None
       * Post-condition: object's members variables are set to default values ("", 0s)
       */
      LinkedList();

      /* Account destructor
       * Pre-condition: None
       * Post-condition: Any allocated memory in object is freed
       */
      ~LinkedList();

      void insert(int pos, int value);

      int remove(int pos);

      int getNumElements();
   private:
      Node *head;
      Node *tail;
      int numElements;
   };
}

#endif
