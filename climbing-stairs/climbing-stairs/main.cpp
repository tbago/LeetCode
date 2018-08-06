//
//  main.cpp
//  climbing-stairs
//
//  Created by tbago on 2018/8/6.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int32_t prePreStep = 1;
        int32_t preStep = 2;
        int32_t currentStep = 0;
        for (uint32_t i = 2; i < n; i++) {
            currentStep = preStep + prePreStep;
            prePreStep = preStep;
            preStep = currentStep;
        }
        return currentStep;
    }
};

int main(int argc, const char * argv[]) {
    int32_t demoInput = 5;
    Solution solution;
    cout<<"input "<<demoInput<<" solution is "<<solution.climbStairs(demoInput)<<endl;
    return 0;
}
