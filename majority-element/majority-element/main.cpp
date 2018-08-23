//
//  main.cpp
//  majority-element
//
//  Created by tbago on 2018/8/23.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int counter = 0;
        for (uint32_t i = 0; i < nums.size(); i++) {
            if (counter == 0) {
                result = nums[i];
                counter++;
            }
            else {
                int compareValue = nums[i];
                if (compareValue == result) {
                    counter++;
                }
                else {
                    counter--;
                }
            }
        }
        return result;
    }
    int majorityElementV2(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        uint32_t checkCounter = (uint32_t)nums.size()/2;
        for (uint32_t i = 0; i < nums.size()/2+1; i++) {
            int compareValue = nums[i];
            int compareCounter = 0;
            for (uint32_t j = i + 1; j < nums.size(); j++) {
                if (compareValue == nums[j]) {
                    compareCounter++;
                }
                if (compareCounter >= checkCounter) {
                    return compareValue;
                }
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {2,2,1,1,1,2,2};
    Solution solution;
    cout<<"solution is "<<solution.majorityElement(inputDemo)<<endl;
    return 0;
}
