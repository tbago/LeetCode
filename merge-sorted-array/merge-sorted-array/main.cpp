//
//  main.cpp
//  merge-sorted-array
//
//  Created by tbago on 2018/8/8.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        
        int counter = m + n;
        int nums1Index = 0;
        int nums2Index = 0;
        vector<int> tempNums1;
        tempNums1.insert(tempNums1.begin(), nums1.begin(), nums1.begin() + m);
        
        for (uint32_t i = 0; i < counter; i++) {
            if (nums2Index >= n) {
                nums1[i] = tempNums1[nums1Index];
                nums1Index++;
            }
            else if (nums1Index >= m) {
                nums1[i] = nums2[nums2Index];
                nums2Index++;
            }
            else {
                int nums1Value = tempNums1[nums1Index];
                int nums2Value = nums2[nums2Index];
                if (nums1Value > nums2Value) {
                    nums1[i] = nums2Value;
                    nums2Index++;
                }
                else {
                    nums1[i] = nums1Value;
                    nums1Index++;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo1 = {4,0,0,0,0,0};
    vector<int> inputDemo2 = {1,2,3,5,6};
    Solution solution;
    solution.merge(inputDemo1, 1, inputDemo2, 5);
    cout<<"result is "<< inputDemo1.size()<<endl;
    return 0;
}
