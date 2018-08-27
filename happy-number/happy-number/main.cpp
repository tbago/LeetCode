//
//  main.cpp
//  happy-number
//
//  Created by tbago on 2018/8/27.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isHappy(int n) {
        const int maxTryCount = 100;
        int resultNumber = n;
        for (int i = 0; i < maxTryCount; i++) {
            resultNumber = convertNumber(resultNumber);
            if (resultNumber == 1) {
                return true;
            }
        }
        return false;
    }
private:
    int convertNumber(int n) {
        int result = 0;
        while(n > 0) {
            int temp = n%10;
            result += temp*temp;
            n /= 10;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    int inputDemo = 19;
    Solution solution;
    std::cout<<"solution is "<<solution.isHappy(inputDemo)<<std::endl;
    return 0;
}
