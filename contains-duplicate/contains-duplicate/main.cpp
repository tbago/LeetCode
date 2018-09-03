//
//  main.cpp
//  contains-duplicate
//
//  Created by tbago on 2018/9/3.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numsSet;
        for (uint32_t i = 0; i < nums.size(); i++) {
            numsSet.insert(nums[i]);
        }
        return numsSet.size() != nums.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
