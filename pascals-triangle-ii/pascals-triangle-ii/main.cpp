//
//  main.cpp
//  pascals-triangle-ii
//
//  Created by tbago on 2018/8/20.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> resultVector;
        for (uint32_t i = 0; i < rowIndex + 1; i++) {
            resultVector.push_back(0);
        }
        for (uint32_t i = 0; i < rowIndex + 1; i++) {
            if (i == 0) {
                resultVector[i] = 1;
            }
            else {
                for (int j = rowIndex; j >= 1; --j) {
                    resultVector[j] = resultVector[j] + resultVector[j-1];
                }
            }
        }
        return resultVector;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> resultVecotr = solution.getRow(4);
    cout<<"get solution"<<endl;
    return 0;
}
