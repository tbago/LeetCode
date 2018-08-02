//
//  main.cpp
//  remove-duplicate-from-sorted-array
//
//  Created by tbago on 2018/8/2.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return (int)nums.size();
        }
        vector<int>::iterator compareIt = nums.begin();
        for (vector<int>::iterator it=nums.begin()+1; it != nums.end();) {
            if (*compareIt == *it) {
                it = nums.erase(it);
            }
            else {
                compareIt = it;
                it++;
            }
        }
        return (int)nums.size();
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputVector = {0,0,1,1,1,2,2,3,3,4};
    Solution solution;
    cout<<"remove duplicate result "<<solution.removeDuplicates(inputVector)<<endl;
    return 0;
}
