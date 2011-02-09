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

// BEGIN TESTS: enqueue
TEST_F(QueueTest, EnqueueNormal) {
   int aq0[] = {100};
   int aq1[] = {0, 100};
   int aq2[] = {0, 1, 100};
   int aq3[] = {0, 1, 2, 100};
   int aq9[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 100};

   q0.enqueue(100);
   q1.enqueue(100);
   q2.enqueue(100);
   q3.enqueue(100);
   q9.enqueue(100);

   checkWalk(&q0, aq0, 1);
   checkWalk(&q1, aq1, 2);
   checkWalk(&q2, aq2, 3);
   checkWalk(&q3, aq3, 4);
   checkWalk(&q9, aq9, 10);
}

TEST_F(QueueTest, EnqueueEmpty) {
   int aq0[] = {0};

   EXPECT_EQ(q0.getNumElements(), 0);
   EXPECT_TRUE(q0.isEmpty());
   checkWalk(&q0, (int*) NULL, 0);

   q0.enqueue(0);

   EXPECT_EQ(q0.getNumElements(), 1);
   EXPECT_FALSE(q0.isEmpty());
   checkWalk(&q0, aq0, 1);
}

TEST_F(QueueTest, EnqueueMultiple) {
   int aq0[] = {0, 1, -1, 2, -2};

   EXPECT_EQ(q0.getNumElements(), 0);
   EXPECT_TRUE(q0.isEmpty());
   checkWalk(&q0, (int*) NULL, 0);

   q0.enqueue(0);
   q0.enqueue(1);
   q0.enqueue(-1);
   q0.enqueue(2);
   q0.enqueue(-2);

   EXPECT_EQ(q0.getNumElements(), 5);
   EXPECT_FALSE(q0.isEmpty());
   checkWalk(&q0, aq0, 5);
}
// END   TESTS: enqueue

// BEGIN TESTS: dequeue
TEST_F(QueueTest, DequeueNormal) {
   int aq1[] = {};
   int aq2[] = {1};
   int aq3[] = {1, 2};
   int aq9[] = {1, 2, 3, 4, 5, 6, 7, 8};

   EXPECT_EQ(q1.dequeue(), 0);
   EXPECT_EQ(q2.dequeue(), 0);
   EXPECT_EQ(q3.dequeue(), 0);
   EXPECT_EQ(q9.dequeue(), 0);

   checkWalk(&q0, (int *) NULL, 0);
   checkWalk(&q1, aq1, 0);
   checkWalk(&q2, aq2, 1);
   checkWalk(&q3, aq3, 2);
   checkWalk(&q9, aq9, 8);
}

TEST_F(QueueTest, DequeueAll) {
   int aq1[] = {};
   int aq2[] = {};
   int aq3[] = {};
   int aq9[] = {};

   EXPECT_EQ(q1.dequeue(), 0);
   EXPECT_EQ(q2.dequeue(), 0);
   EXPECT_EQ(q3.dequeue(), 0);
   EXPECT_EQ(q9.dequeue(), 0);

   EXPECT_EQ(q2.dequeue(), 1);
   EXPECT_EQ(q3.dequeue(), 1);
   EXPECT_EQ(q9.dequeue(), 1);

   EXPECT_EQ(q3.dequeue(), 2);
   EXPECT_EQ(q9.dequeue(), 2);

   EXPECT_EQ(q9.dequeue(), 3);
   EXPECT_EQ(q9.dequeue(), 4);
   EXPECT_EQ(q9.dequeue(), 5);
   EXPECT_EQ(q9.dequeue(), 6);
   EXPECT_EQ(q9.dequeue(), 7);
   EXPECT_EQ(q9.dequeue(), 8);

   checkWalk(&q0, (int *) NULL, 0);
   checkWalk(&q1, aq1, 0);
   checkWalk(&q2, aq2, 0);
   checkWalk(&q3, aq3, 0);
   checkWalk(&q9, aq9, 0);
}

TEST_F(QueueTest, DequeueWhenEmpty) {
   try {
      q0.dequeue();
   }
   catch (string error) {
      EXPECT_TRUE(error == string("Cannot dequeue from empty list"));
   }
}

TEST_F(QueueTest, DequeueFromFullToBeyondEmpty) {
   EXPECT_EQ(q9.dequeue(), 0);
   EXPECT_EQ(q9.dequeue(), 1);
   EXPECT_EQ(q9.dequeue(), 2);
   EXPECT_EQ(q9.dequeue(), 3);
   EXPECT_EQ(q9.dequeue(), 4);
   EXPECT_EQ(q9.dequeue(), 5);
   EXPECT_EQ(q9.dequeue(), 6);
   EXPECT_EQ(q9.dequeue(), 7);
   EXPECT_EQ(q9.dequeue(), 8);
   try {
      q9.dequeue();
   }
   catch (string error) {
      EXPECT_TRUE(error == string("Cannot dequeue from empty list"));
   }
}

TEST_F(QueueTest, DequeueThenEnqueue) {
   int aq9[] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
   int aq99[] = {6, 7, 8, 9, 10, 11, 12, 13, 14};

   EXPECT_EQ(q9.dequeue(), 0);
   q9.enqueue(9);
   EXPECT_EQ(q9.dequeue(), 1);
   q9.enqueue(10);
   EXPECT_EQ(q9.dequeue(), 2);
   q9.enqueue(11);

   checkWalk(&q9, aq9, 9);

   EXPECT_EQ(q9.dequeue(), 3);
   EXPECT_EQ(q9.dequeue(), 4);
   EXPECT_EQ(q9.dequeue(), 5);
   q9.enqueue(12);
   q9.enqueue(13);
   q9.enqueue(14);

   checkWalk(&q9, aq99, 9);
}
// END   TESTS: dequeue

// BEGIN TESTS: isEmpty
TEST_F(QueueTest, IsEmptyNormal) {
   EXPECT_TRUE(q0.isEmpty());
   EXPECT_FALSE(q1.isEmpty());
   EXPECT_FALSE(q2.isEmpty());
   EXPECT_FALSE(q3.isEmpty());
   EXPECT_FALSE(q9.isEmpty());
}

TEST_F(QueueTest, IsNotEmptyAfterEnqueueingIntoEmptyQueue) {
   EXPECT_TRUE(q0.isEmpty());
   q0.enqueue(0);
   EXPECT_FALSE(q0.isEmpty());
}

TEST_F(QueueTest, IsNotEmptyAfterEnqueueingIntoNonEmptyQueue) {
   EXPECT_FALSE(q1.isEmpty());
   q1.enqueue(0);
   EXPECT_FALSE(q1.isEmpty());
}

TEST_F(QueueTest, IsNotEmptyAfterDequeueingAndQueueNotEmpty) {
   EXPECT_FALSE(q2.isEmpty());
   q2.dequeue();
   EXPECT_FALSE(q2.isEmpty());
}

TEST_F(QueueTest, IsEmptyAfterDequeueingAndQueueIsEmpty) {
   EXPECT_FALSE(q1.isEmpty());
   q1.dequeue();
   EXPECT_TRUE(q1.isEmpty());
}
// END   TESTS: isEmpty

// BEGIN TESTS: toArray
TEST_F(QueueTest, EmptyQueueToArray) {
   EXPECT_TRUE(q0.toArray() == NULL);
}

TEST_F(QueueTest, SingleElementQueueToArray) {
   int *myArray;
   myArray = q1.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 0);

   free(myArray);
}

TEST_F(QueueTest, MultipleElementQueueToArray) {
   int *myArray;
   myArray = q9.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 0);
   EXPECT_TRUE(myArray[1] == 1);
   EXPECT_TRUE(myArray[2] == 2);
   EXPECT_TRUE(myArray[3] == 3);
   EXPECT_TRUE(myArray[4] == 4);
   EXPECT_TRUE(myArray[5] == 5);
   EXPECT_TRUE(myArray[6] == 6);
   EXPECT_TRUE(myArray[7] == 7);
   EXPECT_TRUE(myArray[8] == 8);

   free(myArray);
}

TEST_F(QueueTest, ArrayWalkingAfterRemovalAndInsertion) {
   int *myArray;
   myArray = q9.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 0);
   EXPECT_TRUE(myArray[1] == 1);
   EXPECT_TRUE(myArray[2] == 2);
   EXPECT_TRUE(myArray[3] == 3);
   EXPECT_TRUE(myArray[4] == 4);
   EXPECT_TRUE(myArray[5] == 5);
   EXPECT_TRUE(myArray[6] == 6);
   EXPECT_TRUE(myArray[7] == 7);
   EXPECT_TRUE(myArray[8] == 8);
   free(myArray);

   q9.dequeue();

   myArray = q9.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 1);
   EXPECT_TRUE(myArray[1] == 2);
   EXPECT_TRUE(myArray[2] == 3);
   EXPECT_TRUE(myArray[3] == 4);
   EXPECT_TRUE(myArray[4] == 5);
   EXPECT_TRUE(myArray[5] == 6);
   EXPECT_TRUE(myArray[6] == 7);
   EXPECT_TRUE(myArray[7] == 8);
   free(myArray);

   q9.enqueue(9);

   myArray = q9.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 1);
   EXPECT_TRUE(myArray[1] == 2);
   EXPECT_TRUE(myArray[2] == 3);
   EXPECT_TRUE(myArray[3] == 4);
   EXPECT_TRUE(myArray[4] == 5);
   EXPECT_TRUE(myArray[5] == 6);
   EXPECT_TRUE(myArray[6] == 7);
   EXPECT_TRUE(myArray[7] == 8);
   EXPECT_TRUE(myArray[8] == 9);
   free(myArray);
}
// END   TESTS: toArray

// BEGIN TESTS: getNumElements
TEST_F(QueueTest, GetNumElementsDefault) {
   EXPECT_EQ(q0.getNumElements(), 0);
   EXPECT_EQ(q1.getNumElements(), 1);
   EXPECT_EQ(q2.getNumElements(), 2);
   EXPECT_EQ(q3.getNumElements(), 3);
   EXPECT_EQ(q9.getNumElements(), 9);
}

TEST_F(QueueTest, GetNumElementsAddEmpty) {
   EXPECT_EQ(q0.getNumElements(), 0);
   q0.enqueue(0);
   EXPECT_EQ(q0.getNumElements(), 1);
}

TEST_F(QueueTest, GetNumElementsAddEmptyRemoveToMakeEmpty) {
   EXPECT_EQ(q0.getNumElements(), 0);
   q0.enqueue(0);
   EXPECT_EQ(q0.getNumElements(), 1);
   q0.dequeue();
   EXPECT_EQ(q0.getNumElements(), 0);
}

TEST_F(QueueTest, GetNumElementsRemoveBeyondEmpty) {
   EXPECT_EQ(q0.getNumElements(), 0);
   try {
      q0.dequeue();
   }
   catch (string error) {
      EXPECT_TRUE(error == string("Cannot dequeue from empty list"));
   }
   EXPECT_EQ(q0.getNumElements(), 0);
}
// END   TESTS: getNumElements
