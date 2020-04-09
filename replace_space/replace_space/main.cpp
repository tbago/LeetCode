//
//  main.cpp
//  replace_space
//
//  Created by tbago on 2020/4/9.
//  Copyright © 2020 tbago. All rights reserved.
//

#include <iostream>

#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        if (s.length() == 0) {
            return "";
        }
        int spaceCount = 0;
        const char *startCharPtr = s.c_str();
        for (int i = 0; i < s.length(); i++) {
            if (*(startCharPtr+i) == ' ') {
                spaceCount++;
            }
        }
        int outputStringLength = s.length() + spaceCount*2 + 1; // with '\0'
        char *outputBuffer = (char *)malloc(outputStringLength);
        memset(outputBuffer, '\0', outputStringLength);
        int endIndex = outputStringLength - 2;
        int index = s.length() - 1;
        while (index >= 0) {
            char currentChar = *(startCharPtr + index);
            if(currentChar == ' ') {
                outputBuffer[endIndex--] = '0';
                outputBuffer[endIndex--] = '2';
                outputBuffer[endIndex--] = '%';
            }
            else {
                outputBuffer[endIndex--] = currentChar;
            }
        }
        string resultString = outputBuffer;
        free(outputBuffer);
        return resultString;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;

    string outString = solution.replaceSpace("Hello World");
    return 0;
}
