#include <iostream>
#include <assert.h>
#include "ReverseWordsInString.h"
using namespace std;
using namespace AutodeskAssignment;

int main()
{
	string EMPTY_STRING = "";
	string ONE_LENGTH_ALPHA = "A";
	string ONE_LENGTH_NUMBER = "1";
	string ONE_LENGTH_SYMBOL = ";";
	string SPECIAL_CHARS = ";!@#$%^ ^";
	string SPACES = "                     ";
	string ALPHANUMERIC_SPECIAL_CHARS1 = "a b 1 2 3 5 6 7 ; #";
	
	string ALPHA_LOWER_CASE = "abcdefghijklmnopqrstuvwxyz";
	string ALPHA_UPPER_CASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ONLY_ALPHANUMERIC = "abcd1234ABCD";
	string NUMBERS = "0123456789";
	
	string ALPHANUMERIC_SPECIAL_CHARS2 = "Stri_ng;-%   2b$#e reversed";
	string ALPHANUMERIC_SPECIAL_CHARS3 = "ABCD 1234 abcd";
	
    ReverseWordsInString revWords;
	//Given testcase
    assert("irtS_gn;-%   b2$#e desrever" == revWords.reverseWords(ALPHANUMERIC_SPECIAL_CHARS2));
	
	// Tests where input remains same
	assert(EMPTY_STRING == revWords.reverseWords(EMPTY_STRING));
	assert(ONE_LENGTH_ALPHA == revWords.reverseWords(ONE_LENGTH_ALPHA));
	assert(ONE_LENGTH_NUMBER == revWords.reverseWords(ONE_LENGTH_NUMBER));
	assert(ONE_LENGTH_SYMBOL == revWords.reverseWords(ONE_LENGTH_SYMBOL));
	assert(SPECIAL_CHARS == revWords.reverseWords(SPECIAL_CHARS));
	assert(SPACES == revWords.reverseWords(SPACES));
	assert(ALPHANUMERIC_SPECIAL_CHARS1 == revWords.reverseWords(ALPHANUMERIC_SPECIAL_CHARS1));
	
	// Tests where input is reversed
	assert("zyxwvutsrqponmlkjihgfedcba" == revWords.reverseWords(ALPHA_LOWER_CASE));
	assert("ZYXWVUTSRQPONMLKJIHGFEDCBA" == revWords.reverseWords(ALPHA_UPPER_CASE));
	assert("DCBA4321dcba" == revWords.reverseWords(ONLY_ALPHANUMERIC));
	assert("9876543210" == revWords.reverseWords(NUMBERS));
	assert("DCBA 4321 dcba" == revWords.reverseWords(ALPHANUMERIC_SPECIAL_CHARS3));
	
    return 0;
}