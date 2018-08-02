//
//  main.cpp
//  valid-parentheses
//
//  Created by tbago on 2018/8/1.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int stringLength = (int)s.length();
        if (stringLength == 0) {
            return true;
        }
        if (stringLength%2 != 0 ) {
            return false;
        }
        
        int strBufferLength = (int)s.length() + 1;
        char *strBuffer = (char *)malloc(strBufferLength + 1);
        memset(strBuffer, 0, strBufferLength);
        memcpy(strBuffer, s.c_str(), s.length());
        int strLength = (int)s.length();
        bool result = true;
        while (true) {
            bool findClosePair = remotePairParentheses(strBuffer, strLength);
            if (!findClosePair) {
                result = false;
                break;
            }
            else if (strLength == 0) {
                result = true;
                break;
            }
        }
        free(strBuffer);
        return result;
    }
    bool isValidV2(string s) {
        int stringLength = (int)s.length();
        
        if (stringLength%2 != 0 ) {
            return false;
        }
        
        stack<char> pairStack;
        for (uint32_t i = 0; i < s.length(); i++) {
            if (pairStack.empty()) {
                pairStack.push(s[i]);
            }
            else {
                if (isPairParentheses(pairStack.top(), s[i])) {
                    pairStack.pop();
                }
                else {
                    pairStack.push(s[i]);
                }
            }
        }
        return pairStack.size() == 0;
    }
private:
    bool isPairParentheses(char leftChar, char rightChar) {
        if (leftChar == '(' && rightChar == ')') {
            return true;
        }
        else if (leftChar == '[' && rightChar == ']') {
            return true;
        }
        else if (leftChar == '{' && rightChar == '}') {
            return true;
        }
        return false;
    }
    
    bool remotePairParentheses(char *strBuffer, int &strBufferLength) {
        bool findClosePair = false;
        for (uint32_t i = 0; i < strBufferLength-1; i++) {
            char firstChar = *(strBuffer + i);
            char secondChar = *(strBuffer + i + 1);
            if (isPairParentheses(firstChar, secondChar)) {
                findClosePair = true;
                strBufferLength -= 2;
                if (i < strBufferLength) {
                    memcpy(strBuffer + i, strBuffer + i + 2, strBufferLength - i);
                    memset(strBuffer+strBufferLength, 0, 2);
                }
                break;
            }
        }
        return findClosePair;
    }
};


int main(int argc, const char * argv[]) {
    string inputString = "(([]){})";
    Solution solution;
    cout<<inputString<<" valid parentheses result is "<<solution.isValid(inputString)<<endl;
    return 0;
}
