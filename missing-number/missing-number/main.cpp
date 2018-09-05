//
//  main.cpp
//  missing-number
//
//  Created by tbago on 2018/9/5.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int totalValue = 0;
        int maxValue = 0;
        int minValue = pow(2, 31) - 1;
        for (uint32_t i = 0; i < nums.size(); i++) {
            totalValue += nums[i];
            if (nums[i] > maxValue) {
                maxValue = nums[i];
            }
            if (nums[i] < minValue) {
                minValue = nums[i];
            }
        }
        if (minValue > 0) {
            return 0;
        }
        
        int numSize = (int)nums.size();
        int middleValue = (maxValue + 1)/2;
        int noMissingTotalValue = middleValue * numSize;
        if (numSize%2 == 0) {
            noMissingTotalValue += middleValue;
        }
        int missingValue = noMissingTotalValue - totalValue;
        if (missingValue == 0) {
            missingValue = maxValue + 1;
        }
        return missingValue;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {9,6,4,2,3,5,7,0,1};
    Solution solution;
    cout<<"solution is "<<solution.missingNumber(inputDemo)<<endl;
    return 0;
}
