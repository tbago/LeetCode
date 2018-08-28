//
//  main.cpp
//  count-primes
//
//  Created by tbago on 2018/8/28.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        else if (n == 3) {
            return 1;
        }
        int counter = 1;
        for (uint32_t i = 3; i < n; i+=2) {
            bool valid = true;
            for (uint32_t j = 3; j < i; j+=2) {
                if (i%j == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                counter++;
            }
        }
        return counter;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    std::cout<<"count primes is "<<solution.countPrimes(499979)<<std::endl;
    return 0;
}
