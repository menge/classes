#include <stdlib.h> // for NULL

#include "LinkedList.h"

namespace net_oatsnet_class_datastructures {
   LinkedList::LinkedList() {
      head = NULL;
      tail = NULL;
      numElements = 0;
   }

   LinkedList::~LinkedList() {
   }
}
