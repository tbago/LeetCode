//
//  main.cpp
//  sqrtx
//
//  Created by tbago on 2018/8/8.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 1;
        int right = x;
        while (left < right - 1) {
            int middle = left + (right - left)/2;
            int divideValue = x/middle;
            if (divideValue == middle) {
                return divideValue;
            }
            else if (divideValue < middle) {
                right = middle;
            }
            else {
                left = middle;
            }
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    int inputDemo = 8;
    Solution solution;
    cout<<"result is "<<solution.mySqrt(inputDemo)<<endl;
    return 0;
}
