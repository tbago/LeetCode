//
//  main.cpp
//  string-to-integer
//
//  Created by tbago on 2018/7/31.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int strLen = (int)str.length();
        int32_t strIndex = 0;
        const char *strStart = str.c_str();
        while (strStart[strIndex] == ' ') {     ///< remove space character
            strIndex++;
        }
        
        const int minInt = pow(-2, 31);
        const int maxInt = pow(2, 31) - 1;
        bool bNegative = false;
        if (strIndex < strLen) {
            if (strStart[strIndex] == '-') {
                bNegative = true;
                strIndex++;
            }
            else if (strStart[strIndex] == '+') {
                strIndex++;
            }
        }
        long result = 0;
        while (strIndex < strLen && strStart[strIndex] >= '0' && strStart[strIndex] <= '9') {
            result = result * 10 + strStart[strIndex] - '0';
            if (result > maxInt) {
                if (bNegative) {
                    return minInt;
                }
                else {
                    return maxInt;
                }
            }
            strIndex++;
        }
        
        if (bNegative) {
            result = result * -1;
        }
        return (int)result;
    }
};

int main(int argc, const char * argv[]) {
    string demoString = "-91283472332";
    Solution solution;
    cout<<"convert string "<<demoString<<" to interger is "<<solution.myAtoi(demoString)<<endl;
    return 0;
}
