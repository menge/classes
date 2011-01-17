#include <gtest/gtest.h>
#include "LinkedList.h"

using namespace net_oatsnet_class_datastructures;

class LinkedListTest : public testing::Test {
   protected: 
      virtual void SetUp() {
         myll1.appendTail(0);

         myll2.appendTail(0);
         myll2.appendTail(1);

         myll3.appendTail(0);
         myll3.appendTail(1);
         myll3.appendTail(2);

         myll9.appendTail(0);
         myll9.appendTail(1);
         myll9.appendTail(2);
         myll9.appendTail(3);
         myll9.appendTail(4);
         myll9.appendTail(5);
         myll9.appendTail(6);
         myll9.appendTail(7);
         myll9.appendTail(8);
      }

      virtual void TearDown() {
      }

      void verifySearchElement(LinkedList *ll, int searchValue, bool expectedNull) {
         if (expectedNull) {
            EXPECT_TRUE(ll->search(searchValue) == NULL);
            return;
         }

         int *val_p = ll->search(searchValue);
         ASSERT_TRUE(val_p != NULL);
         EXPECT_EQ(*val_p, searchValue);
      }

      // Declares the variables your tests want to use.
      LinkedList myll0;
      LinkedList myll1;
      LinkedList myll2;
      LinkedList myll3;
      LinkedList myll9;
};

// BEGIN TESTS: Initialization
TEST_F(LinkedListTest, TestInitializesToEmpty) {
   EXPECT_EQ(myll0.getNumElements(), 0);
   EXPECT_TRUE(myll0.setHead() == NULL);
   EXPECT_TRUE(myll0.setTail() == NULL);
   EXPECT_TRUE(myll0.isEmpty());
}
// END   TESTS: Initialization

// BEGIN TESTS: insert
// BEGIN TESTS: insertHead
// BEGIN TESTS: append
// BEGIN TESTS: appendTail
// BEGIN TESTS: remove

// BEGIN TESTS: isEmpty
TEST_F(LinkedListTest, TestIsEmpty) {
   EXPECT_TRUE(myll0.isEmpty());
   EXPECT_FALSE(myll1.isEmpty());
   EXPECT_FALSE(myll2.isEmpty());
   EXPECT_FALSE(myll3.isEmpty());
   EXPECT_FALSE(myll9.isEmpty());
}

TEST_F(LinkedListTest, TestIsEmptyAfterInsertingInEmpty) {
   EXPECT_TRUE(myll0.isEmpty());
   myll0.insert(-1);
   EXPECT_FALSE(myll0.isEmpty());
}

TEST_F(LinkedListTest, TestIsEmptyAfterRemovingAllElements) {
   EXPECT_FALSE(myll1.isEmpty());
   myll1.remove();
   EXPECT_TRUE(myll1.isEmpty());

   EXPECT_FALSE(myll9.isEmpty());
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   EXPECT_TRUE(myll9.isEmpty());
}
// END   TESTS: isEmpty

// BEGIN TESTS: search
TEST_F(LinkedListTest, TestSearchExist) {
   verifySearchElement(&myll1, 0, true);

   verifySearchElement(&myll2, 0, true);
   verifySearchElement(&myll2, 1, true);

   verifySearchElement(&myll3, 0, true);
   verifySearchElement(&myll3, 1, true);
   verifySearchElement(&myll3, 2, true);

   verifySearchElement(&myll9, 0, true);
   verifySearchElement(&myll9, 1, true);
   verifySearchElement(&myll9, 2, true);
   verifySearchElement(&myll9, 3, true);
   verifySearchElement(&myll9, 4, true);
   verifySearchElement(&myll9, 5, true);
   verifySearchElement(&myll9, 6, true);
   verifySearchElement(&myll9, 7, true);
   verifySearchElement(&myll9, 8, true);
}

TEST_F(LinkedListTest, TestSearchNotExist) {
   verifySearchElement(&myll0, -1, false);
   verifySearchElement(&myll1, -1, false);
   verifySearchElement(&myll2, -1, false);
   verifySearchElement(&myll3, -1, false);
   verifySearchElement(&myll9, -1, false);
}

TEST_F(LinkedListTest, TestSearchCursorUpdate) {
   int *val_p;

   verifySearchElement(&myll9, 5, true); // cursor should point to 5 now

   val_p = myll9.next(); // going next should point to 6
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 6);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 5);

   verifySearchElement(&myll9, 7, true); // cursor should point to 7 now

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 6);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 5);
}

TEST_F(LinkedListTest, TestSearchCursorNotUpdated) {
   int *val_p;

   verifySearchElement(&myll9, 5, true); // cursor should point to 5 now

   verifySearchElement(&myll9, -1, false); // should not update cursor

   val_p = myll9.next(); // going next should point to 6
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 6);
}
// END   TESTS: search

// BEGIN TESTS: getNumElements
TEST_F(LinkedListTest, TestGetNumElements) {
   EXPECT_EQ(myll0.getNumElements(), 0);
   EXPECT_EQ(myll1.getNumElements(), 1);
   EXPECT_EQ(myll2.getNumElements(), 2);
   EXPECT_EQ(myll3.getNumElements(), 3);
   EXPECT_EQ(myll9.getNumElements(), 9);
}

TEST_F(LinkedListTest, TestGetNumElementsAfterInserting) {
   EXPECT_EQ(myll0.getNumElements(), 0);
   myll0.insert(-1);
   EXPECT_EQ(myll0.getNumElements(), 1);

   EXPECT_EQ(myll1.getNumElements(), 1);
   myll1.insert(-1);
   EXPECT_EQ(myll1.getNumElements(), 2);

   EXPECT_EQ(myll2.getNumElements(), 2);
   myll2.insert(-1);
   EXPECT_EQ(myll2.getNumElements(), 3);

   EXPECT_EQ(myll3.getNumElements(), 3);
   myll3.insert(-1);
   EXPECT_EQ(myll3.getNumElements(), 4);

   EXPECT_EQ(myll9.getNumElements(), 9);
   myll3.insert(-1);
   EXPECT_EQ(myll3.getNumElements(), 10);
}

TEST_F(LinkedListTest, TestGetNumElementsAfterRemoving) {
   EXPECT_EQ(myll0.getNumElements(), 0);
   myll0.remove();
   EXPECT_EQ(myll0.getNumElements(), 0);

   EXPECT_EQ(myll1.getNumElements(), 1);
   myll1.remove();
   EXPECT_EQ(myll1.getNumElements(), 0);

   EXPECT_EQ(myll2.getNumElements(), 2);
   myll2.remove();
   EXPECT_EQ(myll2.getNumElements(), 1);

   EXPECT_EQ(myll3.getNumElements(), 3);
   myll3.remove();
   EXPECT_EQ(myll3.getNumElements(), 2);

   EXPECT_EQ(myll9.getNumElements(), 9);
   myll3.remove();
   EXPECT_EQ(myll3.getNumElements(), 8);
}
// END   TESTS: getNumElements

// BEGIN TESTS: setHead
TEST_F(LinkedListTest, TestSetHead) {
   int *val_p;

   val_p = myll0.setHead();
   EXPECT_TRUE(val_p == NULL);

   val_p = myll1.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);

   val_p = myll2.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);

   val_p = myll3.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);

   val_p = myll9.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);
}
// END   TESTS: setHead

// BEGIN TESTS: setTail
TEST_F(LinkedListTest, TestSetTail) {
   int *val_p;

   val_p = myll0.setTail();
   EXPECT_TRUE(val_p == NULL);

   val_p = myll1.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);

   val_p = myll2.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 1);

   val_p = myll3.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 2);

   val_p = myll9.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 8);
}
// END   TESTS: setTail

// BEGIN TESTS: prev
TEST_F(LinkedListTest, TestPrevFromTail) {
   int *val_p;

   val_p = myll9.setTail();
   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 7);
}

TEST_F(LinkedListTest, TestPrevFromHead) {
   int *val_p;

   val_p = myll9.setHead();
   val_p = myll9.prev();
   EXPECT_TRUE(val_p == NULL);
}

TEST_F(LinkedListTest, TestPrevFromNull) {
   int *val_p;

   val_p = myll9.setHead();
   val_p = myll9.prev();
   EXPECT_TRUE(val_p == NULL);

   // going prev from NULL
   val_p = myll9.prev();
   EXPECT_TRUE(val_p == NULL);
}
// END   TESTS: prev

// BEGIN TESTS: next
TEST_F(LinkedListTest, TestNextFromHead) {
   int *val_p;

   val_p = myll9.setHead();
   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 1);
}

TEST_F(LinkedListTest, TestNextFromTail) {
   int *val_p;

   val_p = myll9.setTail();
   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);
}

TEST_F(LinkedListTest, TestNextFromNull) {
   int *val_p;

   val_p = myll9.setTail();
   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);

   // going next from NULL
   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);
}
// END   TESTS: next
