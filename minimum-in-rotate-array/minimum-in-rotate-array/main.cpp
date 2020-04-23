//
//  main.cpp
//  minimum-in-rotate-array
//
//  Created by tbago on 2020/4/23.
//  Copyright © 2020 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0) {
            return -1;
        }
        else if (numbers.size() == 1) {
            return numbers[0];
        }
        int startIndex = 0;
        int endIndex = (int)numbers.size() - 1;
        ///< 首先去除头尾重复的元素
        for (int32_t i = startIndex+1; i < numbers.size(); i++) {
            if (numbers[startIndex] == numbers[i]) {
                startIndex = i;
            }
            else {
                break;
            }
        }
        if (startIndex == endIndex) {
            return numbers[startIndex];
        }
        for (int32_t j = endIndex-1; j >= 0; j--) {
            if (numbers[endIndex] == numbers[j]) {
                endIndex = j;
            }
            else {
                break;
            }
        }

        int midIndex = startIndex;
        while (numbers[startIndex] >= numbers[endIndex]) {
            if (endIndex - startIndex == 1) {
                midIndex = endIndex;
                break;
            }
            int middleIndex = (startIndex + endIndex)/2;
            if (numbers[middleIndex] <= numbers[endIndex]){
                endIndex = middleIndex;
            }
            else if (numbers[middleIndex] >= numbers[startIndex]) {
                startIndex = middleIndex;
            }
        }
        return numbers[midIndex];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> testVector = {1,1};
    Solution solution;
    std::cout<<"result is "<< solution.minArray(testVector)<<std::endl;
    return 0;
}
