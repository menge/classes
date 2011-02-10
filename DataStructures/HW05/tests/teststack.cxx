#include <malloc.h>
#include <stdlib.h>
#include <string>
#include <gtest/gtest.h>
#include "Stack.h"

using namespace net_oatsnet_class_datastructures;

class StackTest : public testing::Test {
   protected: 
      virtual void SetUp() {
         q1.push(0);

         q2.push(0);
         q2.push(1);

         q3.push(0);
         q3.push(1);
         q3.push(2);

         q9.push(0);
         q9.push(1);
         q9.push(2);
         q9.push(3);
         q9.push(4);
         q9.push(5);
         q9.push(6);
         q9.push(7);
         q9.push(8);
      }

      virtual void TearDown() {
      }

      template <class T>
      void checkWalk(Stack<T> *q, T* checkArray, int checkSize) {
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
      Stack<int> q0;
      Stack<int> q1;
      Stack<int> q2;
      Stack<int> q3;
      Stack<int> q9;
};

// BEGIN TESTS: Initialization
TEST_F(StackTest, InitializesToEmpty) {
   int aq1[] = {0};
   int aq2[] = {1, 0};
   int aq3[] = {2, 1, 0};
   int aq9[] = {8, 7, 6, 5, 4, 3, 2, 1, 0};

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
TEST_F(StackTest, DestructorFreesMemory) {
   struct mallinfo miBefore, miDuring, miAfter;

   miBefore = mallinfo();
   {
      Stack<int> a;

      a.push(0);
      a.push(1);
      a.push(2);
      a.push(3);
      a.push(4);
      a.push(5);
      a.push(6);

      miDuring = mallinfo();
   }
   miAfter = mallinfo();

   // Ensures that memory is actually being tracked
   EXPECT_TRUE(miDuring.uordblks > miBefore.uordblks);
   // Ensures that memory is freed appropriately
   EXPECT_EQ(miBefore.uordblks, miAfter.uordblks);
}
// END   TESTS: Destructor

// BEGIN TESTS: push
TEST_F(StackTest, PushNormal) {
   int aq0[] = {100};
   int aq1[] = {100, 0};
   int aq2[] = {100, 1, 0};
   int aq3[] = {100, 2, 1, 0};
   int aq9[] = {100, 8, 7, 6, 5, 4, 3, 2, 1, 0};

   q0.push(100);
   q1.push(100);
   q2.push(100);
   q3.push(100);
   q9.push(100);

   checkWalk(&q0, aq0, 1);
   checkWalk(&q1, aq1, 2);
   checkWalk(&q2, aq2, 3);
   checkWalk(&q3, aq3, 4);
   checkWalk(&q9, aq9, 10);
}

TEST_F(StackTest, PushEmpty) {
   int aq0[] = {0};

   EXPECT_EQ(q0.getNumElements(), 0);
   EXPECT_TRUE(q0.isEmpty());
   checkWalk(&q0, (int*) NULL, 0);

   q0.push(0);

   EXPECT_EQ(q0.getNumElements(), 1);
   EXPECT_FALSE(q0.isEmpty());
   checkWalk(&q0, aq0, 1);
}

TEST_F(StackTest, PushMultiple) {
   int aq0[] = {-2, 2, -1, 1, 0};

   EXPECT_EQ(q0.getNumElements(), 0);
   EXPECT_TRUE(q0.isEmpty());
   checkWalk(&q0, (int*) NULL, 0);

   q0.push(0);
   q0.push(1);
   q0.push(-1);
   q0.push(2);
   q0.push(-2);

   EXPECT_EQ(q0.getNumElements(), 5);
   EXPECT_FALSE(q0.isEmpty());
   checkWalk(&q0, aq0, 5);
}
// END   TESTS: push

// BEGIN TESTS: pop
TEST_F(StackTest, PopNormal) {
   int aq1[] = {};
   int aq2[] = {0};
   int aq3[] = {1, 0};
   int aq9[] = {7, 6, 5, 4, 3, 2, 1, 0};

   EXPECT_EQ(q1.pop(), 0);
   EXPECT_EQ(q2.pop(), 1);
   EXPECT_EQ(q3.pop(), 2);
   EXPECT_EQ(q9.pop(), 8);

   checkWalk(&q0, (int *) NULL, 0);
   checkWalk(&q1, aq1, 0);
   checkWalk(&q2, aq2, 1);
   checkWalk(&q3, aq3, 2);
   checkWalk(&q9, aq9, 8);
}

TEST_F(StackTest, PopAll) {
   int aq1[] = {};
   int aq2[] = {};
   int aq3[] = {};
   int aq9[] = {};

   EXPECT_EQ(q1.pop(), 0);
   EXPECT_EQ(q2.pop(), 1);
   EXPECT_EQ(q3.pop(), 2);
   EXPECT_EQ(q9.pop(), 8);

   EXPECT_EQ(q2.pop(), 0);
   EXPECT_EQ(q3.pop(), 1);
   EXPECT_EQ(q9.pop(), 7);

   EXPECT_EQ(q3.pop(), 0);
   EXPECT_EQ(q9.pop(), 6);

   EXPECT_EQ(q9.pop(), 5);
   EXPECT_EQ(q9.pop(), 4);
   EXPECT_EQ(q9.pop(), 3);
   EXPECT_EQ(q9.pop(), 2);
   EXPECT_EQ(q9.pop(), 1);
   EXPECT_EQ(q9.pop(), 0);

   checkWalk(&q0, (int *) NULL, 0);
   checkWalk(&q1, aq1, 0);
   checkWalk(&q2, aq2, 0);
   checkWalk(&q3, aq3, 0);
   checkWalk(&q9, aq9, 0);
}

TEST_F(StackTest, PopWhenEmpty) {
   try {
      q0.pop();
   }
   catch (string error) {
      EXPECT_TRUE(error == string("Cannot remove from empty list"));
   }
}

TEST_F(StackTest, PopFromFullToBeyondEmpty) {
   EXPECT_EQ(q9.pop(), 8);
   EXPECT_EQ(q9.pop(), 7);
   EXPECT_EQ(q9.pop(), 6);
   EXPECT_EQ(q9.pop(), 5);
   EXPECT_EQ(q9.pop(), 4);
   EXPECT_EQ(q9.pop(), 3);
   EXPECT_EQ(q9.pop(), 2);
   EXPECT_EQ(q9.pop(), 1);
   EXPECT_EQ(q9.pop(), 0);
   try {
      q9.pop();
   }
   catch (string error) {
      EXPECT_TRUE(error == string("Cannot remove from empty list"));
   }
}

TEST_F(StackTest, PopThenPush) {
   int aq9[] = {11, 7, 6, 5, 4, 3, 2, 1, 0};
   int aq99[] = {14, 13, 12, 5, 4, 3, 2, 1, 0};

   EXPECT_EQ(q9.pop(), 8);
   q9.push(9);
   EXPECT_EQ(q9.pop(), 9);
   q9.push(10);
   EXPECT_EQ(q9.pop(), 10);
   q9.push(11);

   checkWalk(&q9, aq9, 9);

   EXPECT_EQ(q9.pop(), 11);
   EXPECT_EQ(q9.pop(), 7);
   EXPECT_EQ(q9.pop(), 6);
   q9.push(12);
   q9.push(13);
   q9.push(14);

   checkWalk(&q9, aq99, 9);
}
// END   TESTS: pop

// BEGIN TESTS: isEmpty
TEST_F(StackTest, IsEmptyNormal) {
   EXPECT_TRUE(q0.isEmpty());
   EXPECT_FALSE(q1.isEmpty());
   EXPECT_FALSE(q2.isEmpty());
   EXPECT_FALSE(q3.isEmpty());
   EXPECT_FALSE(q9.isEmpty());
}

TEST_F(StackTest, IsNotEmptyAfterPushingIntoEmptyQueue) {
   EXPECT_TRUE(q0.isEmpty());
   q0.push(0);
   EXPECT_FALSE(q0.isEmpty());
}

TEST_F(StackTest, IsNotEmptyAfterPushingIntoNonEmptyQueue) {
   EXPECT_FALSE(q1.isEmpty());
   q1.push(0);
   EXPECT_FALSE(q1.isEmpty());
}

TEST_F(StackTest, IsNotEmptyAfterPoppingAndQueueNotEmpty) {
   EXPECT_FALSE(q2.isEmpty());
   q2.pop();
   EXPECT_FALSE(q2.isEmpty());
}

TEST_F(StackTest, IsEmptyAfterPoppingAndQueueIsEmpty) {
   EXPECT_FALSE(q1.isEmpty());
   q1.pop();
   EXPECT_TRUE(q1.isEmpty());
}
// END   TESTS: isEmpty

// BEGIN TESTS: toArray
TEST_F(StackTest, EmptyQueueToArray) {
   EXPECT_TRUE(q0.toArray() == NULL);
}

TEST_F(StackTest, SingleElementQueueToArray) {
   int *myArray;
   myArray = q1.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 0);

   free(myArray);
}

TEST_F(StackTest, MultipleElementQueueToArray) {
   int *myArray;
   myArray = q9.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 8);
   EXPECT_TRUE(myArray[1] == 7);
   EXPECT_TRUE(myArray[2] == 6);
   EXPECT_TRUE(myArray[3] == 5);
   EXPECT_TRUE(myArray[4] == 4);
   EXPECT_TRUE(myArray[5] == 3);
   EXPECT_TRUE(myArray[6] == 2);
   EXPECT_TRUE(myArray[7] == 1);
   EXPECT_TRUE(myArray[8] == 0);

   free(myArray);
}

TEST_F(StackTest, ArrayWalkingAfterRemovalAndInsertion) {
   int *myArray;
   myArray = q9.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 8);
   EXPECT_TRUE(myArray[1] == 7);
   EXPECT_TRUE(myArray[2] == 6);
   EXPECT_TRUE(myArray[3] == 5);
   EXPECT_TRUE(myArray[4] == 4);
   EXPECT_TRUE(myArray[5] == 3);
   EXPECT_TRUE(myArray[6] == 2);
   EXPECT_TRUE(myArray[7] == 1);
   EXPECT_TRUE(myArray[8] == 0);
   free(myArray);

   q9.pop();

   myArray = q9.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 7);
   EXPECT_TRUE(myArray[1] == 6);
   EXPECT_TRUE(myArray[2] == 5);
   EXPECT_TRUE(myArray[3] == 4);
   EXPECT_TRUE(myArray[4] == 3);
   EXPECT_TRUE(myArray[5] == 2);
   EXPECT_TRUE(myArray[6] == 1);
   EXPECT_TRUE(myArray[7] == 0);
   free(myArray);

   q9.push(9);

   myArray = q9.toArray();
   EXPECT_FALSE(myArray == NULL);
   EXPECT_TRUE(myArray[0] == 9);
   EXPECT_TRUE(myArray[1] == 7);
   EXPECT_TRUE(myArray[2] == 6);
   EXPECT_TRUE(myArray[3] == 5);
   EXPECT_TRUE(myArray[4] == 4);
   EXPECT_TRUE(myArray[5] == 3);
   EXPECT_TRUE(myArray[6] == 2);
   EXPECT_TRUE(myArray[7] == 1);
   EXPECT_TRUE(myArray[8] == 0);
   free(myArray);
}
// END   TESTS: toArray

// BEGIN TESTS: getNumElements
TEST_F(StackTest, GetNumElementsDefault) {
   EXPECT_EQ(q0.getNumElements(), 0);
   EXPECT_EQ(q1.getNumElements(), 1);
   EXPECT_EQ(q2.getNumElements(), 2);
   EXPECT_EQ(q3.getNumElements(), 3);
   EXPECT_EQ(q9.getNumElements(), 9);
}

TEST_F(StackTest, GetNumElementsAddEmpty) {
   EXPECT_EQ(q0.getNumElements(), 0);
   q0.push(0);
   EXPECT_EQ(q0.getNumElements(), 1);
}

TEST_F(StackTest, GetNumElementsAddEmptyRemoveToMakeEmpty) {
   EXPECT_EQ(q0.getNumElements(), 0);
   q0.push(0);
   EXPECT_EQ(q0.getNumElements(), 1);
   q0.pop();
   EXPECT_EQ(q0.getNumElements(), 0);
}

TEST_F(StackTest, GetNumElementsRemoveBeyondEmpty) {
   EXPECT_EQ(q0.getNumElements(), 0);
   try {
      q0.pop();
   }
   catch (string error) {
      EXPECT_TRUE(error == string("Cannot remove from empty list"));
   }
   EXPECT_EQ(q0.getNumElements(), 0);
}
// END   TESTS: getNumElements
