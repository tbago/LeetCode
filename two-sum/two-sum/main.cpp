//
//  main.cpp
//  two-sum
//
//  Created by tbago on 23/07/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> resultVector;

        for (uint32_t index = 0; index < nums.size() - 1; index++) {
            for (uint32_t i = index+1; i < nums.size(); i++) {
                if (nums[index] + nums[i] == target) {
                    resultVector.push_back(index);
                    resultVector.push_back(i);
                    break;
                }
            }
            if (resultVector.size() > 0) {
                break;
            }
        }
        return resultVector;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputVector;
    inputVector.push_back(2);
    inputVector.push_back(7);
    inputVector.push_back(11);
    inputVector.push_back(15);

    Solution solution;
    int target = 9;
    vector<int> resultVector = solution.twoSum(inputVector, target);
    cout<<"target is "<<target<<endl;
    if (resultVector.size() == 2) {
        cout<<"find right resolution:"<<inputVector[resultVector[0]]<<" "<<inputVector[resultVector[1]]<<endl;
    }
    else {
        cout<<"cannot find resolution"<<endl;
    }
    return 0;
}
