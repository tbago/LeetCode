//
//  main.cpp
//  roman-to-integer
//
//  Created by tbago on 2018/7/27.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int preRomanInt = 0;
        for (uint32_t i = 0; i < s.length(); i++) {
            char romanChar = *(s.c_str() + i);
            int currentRomanInt = romanCharToInt(romanChar);
            if (preRomanInt == 1 && currentRomanInt == 5) {
                result += 3;
            }
            else if (preRomanInt == 1 && currentRomanInt == 10) {
                result += 8;
            }
            else if (preRomanInt == 10 && currentRomanInt == 50) {
                result += 30;
            }
            else if (preRomanInt == 10 && currentRomanInt == 100) {
                result += 80;
            }
            else if (preRomanInt == 100 && currentRomanInt == 500) {
                result += 300;
            }
            else if (preRomanInt == 100 && currentRomanInt == 1000) {
                result += 800;
            }
            else {
                result += currentRomanInt;
            }
            preRomanInt = currentRomanInt;
        }
        return result;
    }
    
private:
    int romanCharToInt(char romanChar) {
        int result = 0;
        switch (romanChar) {
            case 'I':
                result = 1;
                break;
            case 'V':
                result = 5;
                break;
            case 'X':
                result = 10;
                break;
            case 'L':
                result = 50;
                break;
            case 'C':
                result = 100;
                break;
            case 'D':
                result = 500;
                break;
            case 'M':
                result = 1000;
                break;
            default:
                break;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    string inputString = "MCMXCIV";
    Solution solution;
    cout<<inputString<<" roman to integer value is "<<solution.romanToInt(inputString)<<endl;
    return 0;
}
