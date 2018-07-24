//
//  main.cpp
//  palindrome-number
//
//  Created by tbago on 2018/7/24.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x >=0 && x < 10) {
            return true;
        }
        
        int reverseValue = 0;
        int storeValue = x;
        while(storeValue > 0) {
            reverseValue = reverseValue*10 + storeValue%10;
            storeValue /=10;
        }
        if (reverseValue == x) {
            return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    int inputValue = 10;
    Solution solution;
    std::cout<<inputValue<<" result is "<<solution.isPalindrome(inputValue)<<std::endl;
    return 0;
}
