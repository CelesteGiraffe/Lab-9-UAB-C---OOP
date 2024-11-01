// Tests generated using Git Hub's CodePiolot with the prompt:
//#file:MyString.h Create Google Test cases to thoroughly test all functions of the MyString class, including edge cases.
#include <gtest/gtest.h>
#include "MyString.h"

class MyStringTest : public ::testing::Test {
protected:
    void SetUp() override {
        str1 = new MyString("Hello");
        str2 = new MyString("World");
    }

    void TearDown() override {
        delete str1;
        delete str2;
    }

    MyString* str1;
    MyString* str2;
};

TEST_F(MyStringTest, Constructor) {
    MyString str("Test");
    EXPECT_EQ(str.toString(), "Test");
}

TEST_F(MyStringTest, CopyConstructor) {
    MyString copy(*str1);
    EXPECT_EQ(copy.toString(), str1->toString());
}

TEST_F(MyStringTest, Destructor) {
    MyString* str = new MyString("Temporary");
    delete str;
    SUCCEED();
}

TEST_F(MyStringTest, ToString) {
    EXPECT_EQ(str1->toString(), "Hello");
}

TEST_F(MyStringTest, Length) {
    EXPECT_EQ(str1->length(), 5);
}

TEST_F(MyStringTest, Substr) {
    MyString sub = str1->substr(1, 3);
    EXPECT_EQ(sub.toString(), "ell");
}

TEST_F(MyStringTest, SubstrDefault) {
    MyString sub = str1->substr(1);
    EXPECT_EQ(sub.toString(), "ello");
}

TEST_F(MyStringTest, OperatorPlus) {
    MyString result = *str1 + *str2;
    EXPECT_EQ(result.toString(), "HelloWorld");
}

TEST_F(MyStringTest, OperatorAssign) {
    MyString str;
    str = *str1;
    EXPECT_EQ(str.toString(), "Hello");
}

TEST_F(MyStringTest, OperatorEqual) {
    MyString copy(*str1);
    EXPECT_TRUE(*str1 == copy);
}

TEST_F(MyStringTest, OperatorNotEqual) {
    EXPECT_TRUE(*str1 != *str2);
}

TEST_F(MyStringTest, OperatorLessThan) {
    EXPECT_TRUE(*str1 < *str2);
}

TEST_F(MyStringTest, OperatorLessThanOrEqual) {
    MyString copy(*str1);
    EXPECT_TRUE(*str1 <= copy);
    EXPECT_TRUE(*str1 <= *str2);
}

TEST_F(MyStringTest, OperatorGreaterThan) {
    EXPECT_TRUE(*str2 > *str1);
}

TEST_F(MyStringTest, OperatorGreaterThanOrEqual) {
    MyString copy(*str1);
    EXPECT_TRUE(*str1 >= copy);
    EXPECT_TRUE(*str2 >= *str1);
}

TEST_F(MyStringTest, OperatorOutput) {
    std::ostringstream oss;
    oss << *str1;
    EXPECT_EQ(oss.str(), "Hello");
}