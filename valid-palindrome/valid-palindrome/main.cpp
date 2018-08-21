//
//  main.cpp
//  valid-palindrome
//
//  Created by tbago on 2018/8/21.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string needCheckString = convertToValidString(s);
        uint32_t needCheckStringLength = (uint32_t)needCheckString.length();
        if (needCheckStringLength <= 1) {
            return true;
        }
        
        for (uint32_t i = 0; i < needCheckStringLength/2; i++) {
            char compareChar1 = needCheckString[i];
            char compareChar2 = needCheckString[needCheckStringLength - i - 1];
            if (compareChar1 != compareChar2) {
                return false;
            }
        }
        return true;
    }
private:
    string convertToValidString(string inputString) {
        string resultString = "";
        for (uint32_t i = 0; i < inputString.length(); i++) {
            char charValue = inputString[i];
            if (charValue >= 'A' && charValue <= 'Z') {     ///< convert to lower char
                charValue -= 'A' - 'a';
            }
            
            if (charValue >='a' && charValue <= 'z') {
                resultString += charValue;
            }
            else if (charValue >='0' && charValue<='9') {
                resultString += charValue;
            }
        }
        return resultString;
    }
};

int main(int argc, const char * argv[]) {
    string inputDemo = "A man, a plan, a canal: Panama";
    Solution solution;
    std::cout << "solution result is "<<solution.isPalindrome(inputDemo)<<endl;;
    return 0;
}
