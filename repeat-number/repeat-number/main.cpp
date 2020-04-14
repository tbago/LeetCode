//
//  main.cpp
//  repeat-number
//
//  Created by tbago on 2020/4/9.
//  Copyright © 2020 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;  // not found
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i) {
                continue;
            }
            if (nums[i] == nums[nums[i]]) {
                return nums[i];
            }
            else {
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> array = {2, 3, 1, 0, 2, 5, 3};
    Solution solution;
    int value = solution.findRepeatNumber(array);
    std::cout << value;
    return 0;
}
