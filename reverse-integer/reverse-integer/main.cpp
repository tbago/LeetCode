//
//  main.cpp
//  reverse-integer
//
//  Created by tbago on 23/07/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        const int minInt = pow(-2, 31);
        const int maxInt = pow(2, 31) - 1;

        long result = 0;

        long absValue = abs((long)x);
        int indexValue = 0;
        while(absValue != 0) {
            indexValue = absValue % 10;
            absValue /= 10;
            result = result * 10 + indexValue;
        }

        if (result < minInt || result > maxInt) {
            result = 0;
        }
        if (x < 0) {
            result *= -1;
        }
        return (int)result;
    }
};

int main(int argc, const char * argv[]) {
    int demoInput = -123;
    Solution solution;
    int result = solution.reverse(demoInput);
    cout<<demoInput<<" reverse value "<<result<<endl;
    return 0;
}
