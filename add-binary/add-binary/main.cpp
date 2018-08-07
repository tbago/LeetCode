//
//  main.cpp
//  add-binary
//
//  Created by tbago on 2018/8/7.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string resultString = "";
        
        int aLength = (int)a.length();
        int bLength = (int)b.length();
        
        if (aLength == 0) {
            resultString = b;
            return resultString;
        }
        else if (bLength == 0) {
            resultString = a;
            return resultString;
        }
        
        int maxLength = aLength>bLength?aLength:bLength;
        bool needAdd = false;
        for (uint32_t i = 0; i < maxLength; i++) {
            char aChar = '0';
            char bChar = '0';
            if (i < aLength) {
                aChar = a[aLength - i - 1];
            }
            if (i <bLength) {
                bChar = b[bLength - i - 1];
            }
            if (aChar == '1' && bChar == '1') {
                if (needAdd) {
                    resultString ="1" + resultString;
                }
                else {
                    resultString = "0" + resultString;
                }
                needAdd = true;
            }
            else if (aChar == '1' || bChar == '1') {
                if (needAdd) {
                    resultString = "0" + resultString;
                    needAdd = true;
                }
                else {
                    resultString = "1" + resultString;
                }
            }
            else {
                if (needAdd) {
                    resultString ="1" + resultString;
                    needAdd = false;
                }
                else {
                    resultString ="0" + resultString;
                }
            }
        }
        if (needAdd) {
            resultString = "1"+resultString;
        }
        return resultString;
    }
};

int main(int argc, const char * argv[]) {
    string inputString1 = "1";
    string inputString2 = "11";
    Solution solution;
    cout<<"add binary result is "<<solution.addBinary(inputString1, inputString2)<<endl;
    return 0;
}
