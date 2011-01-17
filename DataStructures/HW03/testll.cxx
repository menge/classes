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

TEST_F(LinkedListTest, TestInitializesToEmpty) {
   // TODO: review this... still correct?
   EXPECT_EQ(myll0.getNumElements(), 0);
   EXPECT_TRUE(myll0.setHead() == NULL);
   EXPECT_TRUE(myll0.setTail() == NULL);
}

TEST_F(LinkedListTest, TestGetNumElements) {
   EXPECT_EQ(myll0.getNumElements(), 0);
   EXPECT_EQ(myll1.getNumElements(), 1);
   EXPECT_EQ(myll2.getNumElements(), 2);
   EXPECT_EQ(myll3.getNumElements(), 3);
   EXPECT_EQ(myll9.getNumElements(), 9);
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

TEST_F(LinkedListTest, TestSearchCursorUpdate) {
   //TODO
}

TEST_F(LinkedListTest, TestSearchCursorNotUpdated) {
   //TODO
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
