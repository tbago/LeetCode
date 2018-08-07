//
//  main.cpp
//  plus-one
//
//  Created by tbago on 2018/8/7.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool needMove = false;
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++) {
            if (*it + 1 < 10) {
                *it += 1;
                needMove = false;
                return digits;
            }
            else {
                *it = 0;
                needMove = true;
            }
        }
        if (needMove) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {9,9,9,9};
    Solution solution;
    vector<int> resultVector = solution.plusOne(inputDemo);
    cout<<"get result solution"<<endl;
    return 0;
}
