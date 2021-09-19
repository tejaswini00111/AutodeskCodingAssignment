#include "pch.h"
#include "ReverseWordsInString.h"
using namespace AutodeskAssignment;
TEST(ReverseWordsInStringTests, EmptyString) {
	string EMPTY_STRING = "";
	ReverseWordsInString testStr;
	EXPECT_EQ(EMPTY_STRING, testStr.reverseWords(EMPTY_STRING));
}

TEST(ReverseWordsInStringTests, OneLengthStringAlphaNumeric) {
	string TEST_STRING = "a";
	ReverseWordsInString testStr;
	EXPECT_EQ(TEST_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, OneLengthStringSymbol) {
	string TEST_STRING = "%";
	ReverseWordsInString testStr;
	EXPECT_EQ(TEST_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaLowerCase) {
	string TEST_STRING = "abcdefghijklmnopqrstuvwxyz";
	string RESULT_STRING = "zyxwvutsrqponmlkjihgfedcba";
	ReverseWordsInString testStr;
	EXPECT_EQ(RESULT_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaUpperCase) {
	string TEST_STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string RESULT_STRING = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	ReverseWordsInString testStr;
	EXPECT_EQ(RESULT_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, Numbers) {
	string TEST_STRING = "0123456789";
	string RESULT_STRING = "9876543210";
	ReverseWordsInString testStr;
	EXPECT_EQ(RESULT_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, SpecialChars) {
	string TEST_STRING = "$%^&!@&";
	ReverseWordsInString testStr;
	EXPECT_EQ(TEST_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaNumeric1) {
	string TEST_STRING = "abcd1234fghi";
	string RESULT_STRING = "ihgf4321dcba";
	ReverseWordsInString testStr;
	EXPECT_EQ(RESULT_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaNumeric2) {
	string TEST_STRING = "1234abcd7890";
	string RESULT_STRING = "0987dcba4321";
	ReverseWordsInString testStr;
	EXPECT_EQ(RESULT_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaNumericSpecialChars1) {
	string TEST_STRING = "a b 1 2 3 4 ; # ";
	ReverseWordsInString testStr;
	EXPECT_EQ(TEST_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaNumericSpecialChars2) {
	string TEST_STRING = "%a%a%a%a";
	ReverseWordsInString testStr;
	EXPECT_EQ(TEST_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaNumericSpecialChars3) {
	string TEST_STRING = "Stri_ng;-%   2b$#e reversed";
	string RESULT_STRING = "irtS_gn;-%   b2$#e desrever";
	ReverseWordsInString testStr;
	EXPECT_EQ(RESULT_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaNumericSpecialChars4) {
	string TEST_STRING = "reversed 123 ; #$* reversed";
	string RESULT_STRING = "desrever 321 ; #$* desrever";
	ReverseWordsInString testStr;
	EXPECT_EQ(RESULT_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, AlphaNumericSpecialChars5) {
	string TEST_STRING = "123 321";
	string RESULT_STRING = "321 123";
	ReverseWordsInString testStr;
	EXPECT_EQ(RESULT_STRING, testStr.reverseWords(TEST_STRING));
}

TEST(ReverseWordsInStringTests, Spaces) {
	string TEST_STRING = "                                 ";
	ReverseWordsInString testStr;
	EXPECT_EQ(TEST_STRING, testStr.reverseWords(TEST_STRING));
}