//
//  main.cpp
//  longest-substring
//
//  Created by tbago on 23/07/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubStringLength = 0;
        for (uint32_t i = 0; i < s.length(); i++) {
            const char indexChar = *(s.c_str() + i);
            string tempString = "";
            tempString.push_back(indexChar);
            for (uint32_t j = i + 1; j< s.length(); j++) {
                char needCheckChar = *(s.c_str() + j);
                string needCheckString = "";
                needCheckString.push_back(needCheckChar);
                if (tempString.find(needCheckString) != string::npos) {
                    break;
                }
                tempString.push_back(needCheckChar);
            }
            if (tempString.length() > maxSubStringLength) {
                maxSubStringLength = (int)tempString.length();
            }
        }
        return maxSubStringLength;
    }
};

int main(int argc, const char * argv[]) {
    string demoString = "pwwkew";
    Solution solution;
    int longestStringLength = solution.lengthOfLongestSubstring(demoString);
    cout<<"demo string:"<<demoString<<endl;
    cout<<"longest string length:"<<longestStringLength<<endl;
    return 0;
}
