/**
 * Copyright (C) 2021
 * Author: Tejaswini Naik
 *
 * This code was written for the Autodesk coding assignment
 *
 * Reverses every word in a string which contains alphanumeric
 * characters. Implementation of ReverseWordsInString class.
 *
 */
#include "ReverseWordsInString.h"
#include <stack>
using namespace std;

namespace AutodeskAssignment {
    // This method checks if char is alphabet/number by checking
    // for ASCII values
    // param:
    // input: char input
    // output: true if char is alphabet/number, false otherwise
    bool ReverseWordsInString::isAlphaNumeric(char input) {
        return ((input >= '0' && input <= '9')
            || (input >= 'A' && input <= 'Z')
            || (input >= 'a' && input <= 'z')) ? true : false;
    }

    // This method reverses individual words in a string.
    // param: 
    // input: test string
    // output: reversed test string in-place
    string ReverseWordsInString::reverseWords(string input) {
        size_t length = input.length();
        if (length == 0 || length == 1) {
            return input;
        }

        stack<char> alphaNumericStack;
        for (int i = 0; i < length; i++) {
            // Iterates from 0....length of input string 
            //if alphanumeric, pushes to the stack.  
            if (isAlphaNumeric(input[i])) {
                alphaNumericStack.push(input[i]);
            }
            else {
                // If specialChars/symbols/spaces, chars popped out of stack
                // (hence reversed), and inserted in-place in input string.
                while (!alphaNumericStack.empty()) {
                    input[i - alphaNumericStack.size()] = alphaNumericStack.top();
                    alphaNumericStack.pop();
                }
            }
        }
        
        // If there are characters at the end, the stack will still contain
        // characters. Reverse and insert at the end.
        while (!alphaNumericStack.empty()) {
            input[length - alphaNumericStack.size()] = alphaNumericStack.top();
            alphaNumericStack.pop();
        }

        return input;
    }
}