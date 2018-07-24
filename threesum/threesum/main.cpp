//
//  main.cpp
//  threesum
//
//  Created by tbago on 2018/7/24.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sortInputNumber(nums);
        vector<vector<int>> resultVector;
        for (uint32_t i = 0; i < nums.size(); i++) {
            uint32_t left = i + 1;
            uint32_t right = (uint32_t)nums.size() -1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> threeNum;
                    threeNum.push_back(nums[i]);
                    threeNum.push_back(nums[left]);
                    threeNum.push_back(nums[right]);
                    insertResultVector(resultVector, threeNum);
                }
                if (sum <= 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return resultVector;
    }
private:
    void sortInputNumber(vector<int> & inputNumbers) {
        for (uint32_t i = 0; i < inputNumbers.size(); i++) {
            for (uint32_t j = i+1; j < inputNumbers.size(); j++) {
                if (inputNumbers[i] > inputNumbers[j]) {
                    int swapValue = inputNumbers[i];
                    inputNumbers[i] = inputNumbers[j];
                    inputNumbers[j] = swapValue;
                }
            }
        }
    }
    
    void insertResultVector(vector<vector<int>> &resultVector, vector<int> &threeNum) {
        bool sameResult = false;
        for (uint32_t i = 0; i < resultVector.size(); i++) {
            if (resultVector[i][0] == threeNum[0]
                && resultVector[i][1] == threeNum[1]
                && resultVector[i][2] == threeNum[2]) {
                sameResult = true;
                break;
            }
        }
        
        if (!sameResult) {
            resultVector.push_back(threeNum);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputNumbers;
    inputNumbers.push_back(0);
    inputNumbers.push_back(0);
    inputNumbers.push_back(1);
    inputNumbers.push_back(2);
    inputNumbers.push_back(-1);
    inputNumbers.push_back(-4);
    inputNumbers.push_back(10);
    inputNumbers.push_back(-10);
    Solution solution;
    vector<vector<int>> result = solution.threeSum(inputNumbers);
    if (result.size() > 0) {
        for (uint32_t i = 0; i <result.size(); i++) {
            cout<<"resolution "<<i+1<<": "<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<endl;
        }
    }
    else {
        cout<<"not valid result"<<endl;
    }
    return 0;
}
