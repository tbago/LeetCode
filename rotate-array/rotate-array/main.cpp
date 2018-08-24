//
//  main.cpp
//  rotate-array
//
//  Created by tbago on 2018/8/24.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (uint32_t i = 0; i < k; i++) {
            rotateOne(nums);
        }
    }
private:
    void rotateOne(vector<int> &nums) {
        int32_t lastValue = nums[nums.size()-1];
        for (int32_t i = (int32_t)nums.size()-1; i >= 0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = lastValue;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {1,2,3,4,5,6,7};
    Solution solution;
    solution.rotate(inputDemo, 3);
    cout<<"get solution"<<endl;
    return 0;
}
