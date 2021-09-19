/**
 * Copyright (C) 2021
 * Author: Tejaswini Naik
 *
 * This code was written for the Autodesk coding assignment
 *
 * Reverses every word in a string which contains alphanumeric
 * characters individually. The other symbols like space, %, /, etc., 
 * are kept intact.
 *
 */

#pragma once
#include <string>
using namespace std;

namespace AutodeskAssignment {
    class ReverseWordsInString {
    private:
        bool isAlphaNumeric(char input);
    public:
        string reverseWords(string input);
    };
}