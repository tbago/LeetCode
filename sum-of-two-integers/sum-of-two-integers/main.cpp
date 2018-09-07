//
//  main.cpp
//  sum-of-two-integers
//
//  Created by tbago on 2018/9/7.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        else if (b == 0) {
            return a;
        }
        int ignoreSum = a^b;
        int needChange = (a&b)<<1;
        return getSum(ignoreSum, needChange);
    }
};

int main(int argc, const char * argv[]) {
    int inputDemo = 2;
    int inputDemo2 = 3;
    Solution solution;
    std::cout<<"solution is "<<solution.getSum(inputDemo, inputDemo2)<<std::endl;
    return 0;
}
