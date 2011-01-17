#include <gtest/gtest.h>
#include "LinkedList.h"

using namespace net_oatsnet_class_datastructures;

class LinkedListTest : public testing::Test {
   protected: 
      virtual void SetUp() {
         myll1.insert(0, 0);

         myll2.insert(0, 1);
         myll2.insert(0, 0);

         myll3.insert(0, 2);
         myll3.insert(0, 1);
         myll3.insert(0, 0);

         myll3.insert(0, 8);
         myll3.insert(0, 7);
         myll3.insert(0, 6);
         myll3.insert(0, 5);
         myll3.insert(0, 4);
         myll3.insert(0, 3);
         myll3.insert(0, 2);
         myll3.insert(0, 1);
         myll3.insert(0, 0);
      }

      virtual void TearDown() {
      }

      void verifyElement(LinkedList *ll, int pos, int expectedValue, bool posExpectedNull) {
         /* position given expected to be null */
         if (posExpectedNull) {
            EXPECT_TRUE(ll->getElement(pos) == NULL);
            return;
         }

         /* position given expected to exist */
         int *val_p = ll->getElement(pos);
         ASSERT_TRUE(val_p != NULL);
         EXPECT_EQ(*val_p, expectedValue);
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

TEST_F(LinkedListTest, TestInitializesToEmpty) {
   EXPECT_EQ(myll0.getNumElements(), 0);
   EXPECT_TRUE(myll0.begin() == NULL);
   EXPECT_TRUE(myll0.end() == NULL);
}

TEST_F(LinkedListTest, TestGetNumElements) {
   EXPECT_EQ(myll0.getNumElements(), 0);
   EXPECT_EQ(myll1.getNumElements(), 1);
   EXPECT_EQ(myll2.getNumElements(), 2);
   EXPECT_EQ(myll3.getNumElements(), 3);
   EXPECT_EQ(myll9.getNumElements(), 9);
}

TEST_F(LinkedListTest, TestGetElement) {
   verifyElement(&myll0, 0, 0, false);

   verifyElement(&myll1, 0, 0, true);
   verifyElement(&myll1, 1, 0, false);

   verifyElement(&myll2, 0, 0, true);
   verifyElement(&myll2, 1, 1, true);
   verifyElement(&myll2, 2, 0, false);

   verifyElement(&myll3, 0, 0, true);
   verifyElement(&myll3, 1, 1, true);
   verifyElement(&myll3, 2, 2, true);
   verifyElement(&myll3, 3, 0, false);

   verifyElement(&myll9, 0, 0, true);
   verifyElement(&myll9, 1, 1, true);
   verifyElement(&myll9, 2, 2, true);
   verifyElement(&myll9, 3, 3, true);
   verifyElement(&myll9, 4, 4, true);
   verifyElement(&myll9, 5, 5, true);
   verifyElement(&myll9, 6, 6, true);
   verifyElement(&myll9, 7, 7, true);
   verifyElement(&myll9, 8, 8, true);
   verifyElement(&myll9, 9, 0, false);
}

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

TEST_F(LinkedListTest, TestInsertIntoEmpty) {
   //TODO
}

TEST_F(LinkedListTest, TestInsertBeforeHead) {
   //TODO
}

TEST_F(LinkedListTest, TestInsertInMiddle) {
   //TODO
}

TEST_F(LinkedListTest, TestInsertAfterTail) {
   //TODO
}
