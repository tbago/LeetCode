//
//  main.cpp
//  integer-to-roman
//
//  Created by tbago on 2018/7/30.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string resultString;
        while (num > 0) {
            if (num >= 1000) {
                resultString += "M";
                num -= 1000;
            }
            else if (num >= 900) {
                resultString += "CM";
                num -= 900;
            }
            else if (num >= 500) {
                resultString += "D";
                num -= 500;
            }
            else if (num >= 400) {
                resultString += "CD";
                num -= 400;
            }
            else if (num >= 100) {
                resultString += "C";
                num -= 100;
            }
            else if (num >= 90) {
                resultString += "XC";
                num -= 90;
            }
            else if (num >= 50) {
                resultString += "L";
                num -= 50;
            }
            else if (num >= 40) {
                resultString += "XL";
                num -= 40;
            }
            else if (num >= 10) {
                resultString += "X";
                num -= 10;
            }
            else if (num >= 9) {
                resultString += "IX";
                num -= 9;
            }
            else if (num >= 5) {
                resultString += "V";
                num -= 5;
            }
            else if (num >= 4) {
                resultString += "IV";
                num -= 4;
            }
            else if (num >= 1) {
                resultString += "I";
                num -= 1;
            }
        }
        return resultString;
    }
};

int main(int argc, const char * argv[]) {
    int demoInput = 9;
    Solution solution;
    cout<<"convert "<<demoInput<<" to roman result is "<<solution.intToRoman(demoInput)<<endl;
    return 0;
}
