//
//  main.cpp
//  maximum-subarray
//
//  Created by tbago on 2018/8/6.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = nums[0];
        for (uint32_t i = 1; i <nums.size(); i++) {
            if (maxValue <nums[i]) {
                maxValue = nums[i];
            }
        }
        
        for (uint32_t i = 0; i < nums.size(); i++) {
            int totalValue = nums[i];
            for (uint32_t j = i + 1; j <nums.size(); j++) {
                totalValue += nums[j];
                if (totalValue > maxValue) {
                    maxValue = totalValue;
                }
            }
        }
        return maxValue;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {-1,0,-2};
    Solution solution;
    cout<<"max value is "<<solution.maxSubArray(inputDemo)<<endl;
    return 0;
}
