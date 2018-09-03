//
//  main.cpp
//  power-of-two
//
//  Created by tbago on 2018/9/3.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if (n%2 != 0) {
                return false;
            }
            n = n/2;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    int inputDemo = 16;
    Solution solution;
    std::cout<<"solution is "<<solution.isPowerOfTwo(inputDemo)<<std::endl;
    return 0;
}
