//
//  main.cpp
//  guess-number-higher-or-lower
//
//  Created by tbago on 2018/9/10.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
    const int checkValue = 1;
    if (num == checkValue) {
        return 0;
    }
    else if (num > checkValue) {
        return 1;
    }
    else {
        return -1;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int lowerValue = 1;
        int higherValue = n;
        while (lowerValue <= higherValue) {
            int middle = lowerValue + (higherValue - lowerValue)/2;
            int result = guess(middle);
            if (result == 0) {
                return middle;
            }
            else if (result == 1) {
                lowerValue = middle + 1;
            }
            else if (result == -1) {
                higherValue = middle - 1;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    std::cout<<"solution is "<<solution.guessNumber(1)<<std::endl;
    return 0;
}
