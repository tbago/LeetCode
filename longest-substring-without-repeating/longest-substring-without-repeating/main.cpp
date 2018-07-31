//
//  main.cpp
//  longest-substring-without-repeating
//
//  Created by tbago on 2018/7/31.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string inputString) {
        int maxLength = 0;

        for (uint32_t i = 0; i < inputString.length(); i++) {
            char inputChar = *(inputString.c_str() + i);
            string checkString = "";
            checkString += inputChar;
            for (uint32_t j = i+1; j < inputString.length(); j++) {
                char checkChar = *(inputString.c_str() + j);
                if (checkString.find(checkChar) != string::npos) {
                    break;
                }
                else {
                    checkString += checkChar;
                }
            }
            if (checkString.length() > maxLength) {
                maxLength = (int)checkString.length();
            }
        }
        return maxLength;
    }
};

int main(int argc, const char * argv[]) {
    string inputString = "pwwkew";
    Solution solution;
    cout<<inputString<<" longest substring without repeating string is "<<solution.lengthOfLongestSubstring(inputString)<<endl;
    return 0;
}
