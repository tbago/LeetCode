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
};


int main(int argc, const char * argv[]) {
    string inputString = "(([]){})";
    Solution solution;
    cout<<inputString<<" valid parentheses result is "<<solution.isValid(inputString)<<endl;
    return 0;
}
