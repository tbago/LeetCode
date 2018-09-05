//
//  main.cpp
//  power-of-four
//
//  Created by tbago on 2018/9/5.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        if (num & (num-1)) {
            return false;
        }
        return num & 0x55555555;
    }
};

int main(int argc, const char * argv[]) {
    int inputDemo = 1;
    Solution solution;
    std::cout<<"solution is "<<solution.isPowerOfFour(inputDemo)<<std::endl;
    return 0;
}
