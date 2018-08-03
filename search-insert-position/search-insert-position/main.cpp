//
//  main.cpp
//  search-insert-position
//
//  Created by tbago on 03/08/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        bool minThanPreValue = false;
        int index = 0;
        uint32_t i = 0;
        for (; i < nums.size(); i++) {
            int compareValue = nums[i];
            if (compareValue == target) {
                index = i;
                break;
            }
            else if (compareValue < target) {
                minThanPreValue = true;
            }
            else if (compareValue > target) {
                index = i;
                break;
            }
        }
        if (i == nums.size() && minThanPreValue == true) {
            index = (int)nums.size();
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputNums = {1,3,5,6};
    Solution solution;
    cout<<"search inset result "<<solution.searchInsert(inputNums, 2)<<endl;
    return 0;
}
