//
//  main.cpp
//  length-of-last-word
//
//  Created by tbago on 2018/8/7.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastSpaceIndex = -1;
        
        bool findLastChar = false;
        int removeLastSpaceStringLength = (int)s.length();
        for (int32_t i = (int)s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!findLastChar) {
                    removeLastSpaceStringLength--;
                }
                else {
                    lastSpaceIndex = i;
                    break;
                }
            }
            else {
                findLastChar = true;
            }
        }
        if (lastSpaceIndex == -1) {
            return (int)removeLastSpaceStringLength;
        }
        else {
            return (int)(removeLastSpaceStringLength - lastSpaceIndex - 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    string inputString = "Hello  world";
    Solution solution;
    cout<<"last space word length is "<<solution.lengthOfLastWord(inputString)<<endl;
    return 0;
}
