#include <malloc.h>
#include <stdlib.h>
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

      void verifySearchElement(LinkedList *ll, int searchValue, bool expectToFind) {
         if (!expectToFind) {
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
TEST_F(LinkedListTest, TestInsertInEmptyList) {
   int *val_p;

   myll0.insert(-1);

   EXPECT_EQ(myll0.getNumElements(), 1);

   val_p = myll0.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll0.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   EXPECT_FALSE(myll0.isEmpty());
}

TEST_F(LinkedListTest, TestInsertInFrontOfHead) {
   int *val_p;

   myll9.setHead();
   myll9.insert(-1);

   val_p = myll9.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   EXPECT_EQ(myll9.getNumElements(), 10);
}

TEST_F(LinkedListTest, TestInsertInFrontOfTail) {
   int *val_p;

   myll9.setTail();
   myll9.insert(-1);

   val_p = myll9.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 8);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   EXPECT_EQ(myll9.getNumElements(), 10);
}

TEST_F(LinkedListTest, TestInsertInMiddle) {
   int *val_p;

   myll9.search(5);
   myll9.insert(-1);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 4);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 5);

   EXPECT_EQ(myll9.getNumElements(), 10);
}

TEST_F(LinkedListTest, TestInsertWithNullCursor) {
   int *val_p;
   myll9.setTail();
   val_p = myll9.next();

   EXPECT_TRUE(val_p == NULL);

   myll9.insert(-100);
   
   val_p = myll9.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -100);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -100);

   EXPECT_EQ(myll9.getNumElements(), 10);
}
// END   TESTS: insert

// BEGIN TESTS: insertHead
TEST_F(LinkedListTest, TestInsertHeadNormal) {
   int *val_p;

   myll0.insertHead(-1);
   myll1.insertHead(-1);
   myll2.insertHead(-1);
   myll3.insertHead(-1);
   myll9.insertHead(-1);

   EXPECT_EQ(myll0.getNumElements(), 1);
   EXPECT_EQ(myll1.getNumElements(), 2);
   EXPECT_EQ(myll2.getNumElements(), 3);
   EXPECT_EQ(myll3.getNumElements(), 4);
   EXPECT_EQ(myll9.getNumElements(), 10);

   val_p = myll0.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll1.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll2.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll3.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);
}

TEST_F(LinkedListTest, TestInsertHeadCursorAtTail) {
   int *val_p;

   myll0.setTail();
   myll1.setTail();
   myll2.setTail();
   myll3.setTail();
   myll9.setTail();

   myll0.insertHead(-1);
   myll1.insertHead(-1);
   myll2.insertHead(-1);
   myll3.insertHead(-1);
   myll9.insertHead(-1);

   EXPECT_EQ(myll0.getNumElements(), 1);
   EXPECT_EQ(myll1.getNumElements(), 2);
   EXPECT_EQ(myll2.getNumElements(), 3);
   EXPECT_EQ(myll3.getNumElements(), 4);
   EXPECT_EQ(myll9.getNumElements(), 10);

   val_p = myll0.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll1.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll2.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll3.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);
}

TEST_F(LinkedListTest, TestInsertHeadCursorIsNull) {
   int *val_p;

   myll0.setTail();
   myll1.setTail();
   myll2.setTail();
   myll3.setTail();
   myll9.setTail();

   val_p = myll0.next();
   EXPECT_TRUE(val_p == NULL);
   val_p = myll1.next();
   EXPECT_TRUE(val_p == NULL);
   val_p = myll2.next();
   EXPECT_TRUE(val_p == NULL);
   val_p = myll3.next();
   EXPECT_TRUE(val_p == NULL);
   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);


   myll0.insertHead(-1);
   myll1.insertHead(-1);
   myll2.insertHead(-1);
   myll3.insertHead(-1);
   myll9.insertHead(-1);

   EXPECT_EQ(myll0.getNumElements(), 1);
   EXPECT_EQ(myll1.getNumElements(), 2);
   EXPECT_EQ(myll2.getNumElements(), 3);
   EXPECT_EQ(myll3.getNumElements(), 4);
   EXPECT_EQ(myll9.getNumElements(), 10);

   val_p = myll0.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll1.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll2.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll3.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);
}
// END   TESTS: insertHead

// BEGIN TESTS: append
TEST_F(LinkedListTest, TestAppendInEmptyList) {
   int *val_p;

   myll0.append(-1);

   EXPECT_EQ(myll0.getNumElements(), 1);

   val_p = myll0.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll0.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   EXPECT_FALSE(myll0.isEmpty());
}

TEST_F(LinkedListTest, TestAppendAfterHead) {
   int *val_p;

   myll9.setHead();
   myll9.append(-1);

   val_p = myll9.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   EXPECT_EQ(myll9.getNumElements(), 10);
}

TEST_F(LinkedListTest, TestAppendAfterTail) {
   int *val_p;

   myll9.setTail();
   myll9.append(-1);

   val_p = myll9.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 8);

   EXPECT_EQ(myll9.getNumElements(), 10);
}

TEST_F(LinkedListTest, TestAppendInMiddle) {
   int *val_p;

   myll9.search(5);
   myll9.append(-1);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 5);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 6);

   EXPECT_EQ(myll9.getNumElements(), 10);
}

TEST_F(LinkedListTest, TestAppendWithNullCursor) {
   int *val_p;
   myll9.setTail();
   val_p = myll9.next();

   EXPECT_TRUE(val_p == NULL);

   myll9.append(-100);
   
   val_p = myll9.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -100);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 8);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -100);

   EXPECT_EQ(myll9.getNumElements(), 10);
}
// END   TESTS: append

// BEGIN TESTS: appendTail
TEST_F(LinkedListTest, TestAppendTailNormal) {
   int *val_p;

   myll0.appendTail(-1);
   myll1.appendTail(-1);
   myll2.appendTail(-1);
   myll3.appendTail(-1);
   myll9.appendTail(-1);

   EXPECT_EQ(myll0.getNumElements(), 1);
   EXPECT_EQ(myll1.getNumElements(), 2);
   EXPECT_EQ(myll2.getNumElements(), 3);
   EXPECT_EQ(myll3.getNumElements(), 4);
   EXPECT_EQ(myll9.getNumElements(), 10);

   val_p = myll0.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll1.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll2.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll3.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);
}

TEST_F(LinkedListTest, TestAppendTailCursorAtHead) {
   int *val_p;

   myll0.setHead();
   myll1.setHead();
   myll2.setHead();
   myll3.setHead();
   myll9.setHead();

   myll0.appendTail(-1);
   myll1.appendTail(-1);
   myll2.appendTail(-1);
   myll3.appendTail(-1);
   myll9.appendTail(-1);

   EXPECT_EQ(myll0.getNumElements(), 1);
   EXPECT_EQ(myll1.getNumElements(), 2);
   EXPECT_EQ(myll2.getNumElements(), 3);
   EXPECT_EQ(myll3.getNumElements(), 4);
   EXPECT_EQ(myll9.getNumElements(), 10);

   val_p = myll0.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll1.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll2.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll3.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);
}

TEST_F(LinkedListTest, TestAppendTailCursorIsNull) {
   int *val_p;

   myll0.setTail();
   myll1.setTail();
   myll2.setTail();
   myll3.setTail();
   myll9.setTail();

   val_p = myll0.next();
   EXPECT_TRUE(val_p == NULL);
   val_p = myll1.next();
   EXPECT_TRUE(val_p == NULL);
   val_p = myll2.next();
   EXPECT_TRUE(val_p == NULL);
   val_p = myll3.next();
   EXPECT_TRUE(val_p == NULL);
   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);


   myll0.appendTail(-1);
   myll1.appendTail(-1);
   myll2.appendTail(-1);
   myll3.appendTail(-1);
   myll9.appendTail(-1);

   EXPECT_EQ(myll0.getNumElements(), 1);
   EXPECT_EQ(myll1.getNumElements(), 2);
   EXPECT_EQ(myll2.getNumElements(), 3);
   EXPECT_EQ(myll3.getNumElements(), 4);
   EXPECT_EQ(myll9.getNumElements(), 10);

   val_p = myll0.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll1.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll2.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll3.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll9.setTail();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);
}
// END   TESTS: appendTail

// BEGIN TESTS: remove
TEST_F(LinkedListTest, TestRemoveFromHead) {
   int *val_p;

   myll9.setHead();
   myll9.remove();

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 2);

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 1);

   val_p = myll9.prev();
   EXPECT_TRUE(val_p == NULL);
}

TEST_F(LinkedListTest, TestRemoveFromTail) {
   int *val_p;

   myll9.setTail();
   myll9.remove();

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 6);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 7);

   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);
}

TEST_F(LinkedListTest, TestRemoveFromMiddle) {
   int *val_p;

   myll9.search(5);
   myll9.remove();

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 4);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 6);
}

TEST_F(LinkedListTest, TestRemoveWithNullCursor) {
   int *val_p;

   myll9.setTail();
   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);

   myll9.remove();

   val_p = myll9.prev();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 6);

   val_p = myll9.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 7);

   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);
}

TEST_F(LinkedListTest, TestRemoveLast) {
   int *val_p;

   myll1.remove();

   val_p = myll1.setHead();
   EXPECT_TRUE(val_p == NULL);

   val_p = myll1.setTail();
   EXPECT_TRUE(val_p == NULL);
}

TEST_F(LinkedListTest, TestRemoveAll) {
   int *val_p;

   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();
   myll9.remove();

   val_p = myll9.setHead();
   EXPECT_TRUE(val_p == NULL);

   val_p = myll9.setTail();
   EXPECT_TRUE(val_p == NULL);
}

TEST_F(LinkedListTest, TestRemoveWhenEmpty) {
   int *val_p;

   EXPECT_EQ(myll0.getNumElements(), 0);

   myll0.remove();

   val_p = myll0.setHead();
   EXPECT_TRUE(val_p == NULL);

   val_p = myll0.setTail();
   EXPECT_TRUE(val_p == NULL);
}

TEST_F(LinkedListTest, TestRemoveThenInsert) {
   int *val_p;

   myll3.search(1);
   myll3.remove();
   myll3.insert(-1);

   val_p = myll3.setHead();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);

   val_p = myll3.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, -1);

   val_p = myll3.next();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 2);

   val_p = myll3.next();
   EXPECT_TRUE(val_p == NULL);
}
// END   TESTS: remove

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
   myll9.insert(-1);
   EXPECT_EQ(myll9.getNumElements(), 10);
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
   myll9.remove();
   EXPECT_EQ(myll9.getNumElements(), 8);
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

// BEGIN TESTS: getCursorData
TEST_F(LinkedListTest, TestGetCursorDataFromHead) {
   int *val_p;

   val_p = myll9.setHead();
   val_p = myll9.getCursorData();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 0);
}

TEST_F(LinkedListTest, TestGetCursorDataFromTail) {
   int *val_p;

   val_p = myll9.setTail();
   val_p = myll9.getCursorData();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 8);
}

TEST_F(LinkedListTest, TestGetCursorDataFromMiddle) {
   int *val_p;

   val_p = myll9.search(5);
   val_p = myll9.getCursorData();
   ASSERT_TRUE(val_p != NULL);
   EXPECT_EQ(*val_p, 5);
}

TEST_F(LinkedListTest, TestGetCursorDataWhenCursorIsNull) {
   int *val_p;

   val_p = myll9.setTail();
   val_p = myll9.next();
   EXPECT_TRUE(val_p == NULL);

   val_p = myll9.getCursorData();
   EXPECT_TRUE(val_p == NULL);
}
// END   TESTS: getCursorData

// BEGIN TESTS: destructor
TEST_F(LinkedListTest, TestDestructorFreesMemory) {
   struct mallinfo miBefore, miDuring, miAfter;

   miBefore = mallinfo();
   {
      LinkedList a;

      a.appendTail(0);
      a.appendTail(1);
      a.appendTail(2);
      a.appendTail(3);
      a.appendTail(4);
      a.appendTail(5);
      a.appendTail(6);

      miDuring = mallinfo();
   }
   miAfter = mallinfo();

   // Ensures that memory is actually being tracked
   EXPECT_TRUE(miDuring.uordblks > miBefore.uordblks);
   // Ensures that memory is freed appropriately
   EXPECT_EQ(miBefore.uordblks, miAfter.uordblks);
}
// END   TESTS: destructor
