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
        if (k==0 || nums.size()<=1 || nums.size() == k) {
            return;
        }
        int vectorSize = (int)nums.size();
        reverseVector(nums, 0, k%vectorSize);
        reverseVector(nums, k%vectorSize+1, vectorSize-1);
        reverseVector(nums, 0, vectorSize-1);
    }
    void rotateV2(vector<int>& nums, int k) {
        for (uint32_t i = 0; i < k; i++) {
            rotateOne(nums);
        }
    }
private:
    void reverseVector(vector<int>& nums, int begin, int end) {
        int swapValue = 0;
        while (begin < end) {
            swapValue = nums[begin];
            nums[begin] = nums[end];
            nums[end] = swapValue;
            begin++;
            end--;
        }
    }
    void rotateOne(vector<int> &nums) {
        int32_t lastValue = nums[nums.size()-1];
        for (int32_t i = (int32_t)nums.size()-1; i >= 0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = lastValue;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {1,2};
    Solution solution;
    solution.rotate(inputDemo, 1);
    cout<<"get solution"<<endl;
    return 0;
}
