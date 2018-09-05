//
//  main.cpp
//  power-of-three
//
//  Created by tbago on 2018/9/5.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if (n%3 != 0) {
                return false;
            }
            n/=3;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    int inputDemo = 27;
    Solution solution;
    std::cout<<"solution is "<<solution.isPowerOfThree(inputDemo)<<std::endl;
    return 0;
}
