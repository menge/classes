#include <malloc.h>
#include <stdlib.h>
#include <string>
#include <gtest/gtest.h>
#include "Queue.h"

using namespace net_oatsnet_class_datastructures;

class QueueTest : public testing::Test {
   protected: 
      virtual void SetUp() {
         q1.enqueue(0);

         q2.enqueue(0);
         q2.enqueue(1);

         q3.enqueue(0);
         q3.enqueue(1);
         q3.enqueue(2);

         q9.enqueue(0);
         q9.enqueue(1);
         q9.enqueue(2);
         q9.enqueue(3);
         q9.enqueue(4);
         q9.enqueue(5);
         q9.enqueue(6);
         q9.enqueue(7);
         q9.enqueue(8);
      }

      virtual void TearDown() {
      }

      template <class T>
      void checkWalk(Queue<T> *q, T* checkArray, int checkSize) {
         ASSERT_EQ(q->getNumElements(), checkSize);

         if (q->getNumElements() == 0) {
            EXPECT_TRUE(q->toArray() == (T *)NULL);
            return;
         }

         T *p = q->toArray();
         ASSERT_TRUE(p != NULL);
         for (int i = 0; i < checkSize; i++) {
            EXPECT_EQ(p[i], checkArray[i]);
         }
         free(p);
      }

      // Declares the variables your tests want to use.
      Queue<int> q0;
      Queue<int> q1;
      Queue<int> q2;
      Queue<int> q3;
      Queue<int> q9;
};

// BEGIN TESTS: Initialization
TEST_F(QueueTest, InitializesToEmpty) {
   int aq1[] = {0};
   int aq2[] = {0, 1};
   int aq3[] = {0, 1, 2};
   int aq9[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

   EXPECT_EQ(q0.getNumElements(), 0);
   EXPECT_TRUE(q0.isEmpty());
   checkWalk(&q0, (int*) NULL, 0);

   EXPECT_EQ(q1.getNumElements(), 1);
   EXPECT_TRUE(!q1.isEmpty());
   checkWalk(&q1, aq1, 1);

   EXPECT_EQ(q2.getNumElements(), 2);
   EXPECT_TRUE(!q2.isEmpty());
   checkWalk(&q2, aq2, 2);

   EXPECT_EQ(q3.getNumElements(), 3);
   EXPECT_TRUE(!q3.isEmpty());
   checkWalk(&q3, aq3, 3);

   EXPECT_EQ(q9.getNumElements(), 9);
   EXPECT_TRUE(!q9.isEmpty());
   checkWalk(&q9, aq9, 9);
}
// END   TESTS: Initialization

// BEGIN TESTS: Destructor
TEST_F(QueueTest, DestructorFreesMemory) {
   struct mallinfo miBefore, miDuring, miAfter;

   miBefore = mallinfo();
   {
      Queue<int> a;

      a.enqueue(0);
      a.enqueue(1);
      a.enqueue(2);
      a.enqueue(3);
      a.enqueue(4);
      a.enqueue(5);
      a.enqueue(6);

      miDuring = mallinfo();
   }
   miAfter = mallinfo();

   // Ensures that memory is actually being tracked
   EXPECT_TRUE(miDuring.uordblks > miBefore.uordblks);
   // Ensures that memory is freed appropriately
   EXPECT_EQ(miBefore.uordblks, miAfter.uordblks);
}
// END   TESTS: Destructor
