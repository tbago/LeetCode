//
//  main.cpp
//  single-number
//
//  Created by tbago on 2018/8/22.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (uint32_t i = 0; i <nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {4,1,2,1,2};
    Solution solution;
    cout<<"solution is "<<solution.singleNumber(inputDemo)<<endl;
    return 0;
}
