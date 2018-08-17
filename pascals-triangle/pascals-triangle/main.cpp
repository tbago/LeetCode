//
//  main.cpp
//  pascals-triangle
//
//  Created by tbago on 17/08/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> resultVector;
        for (uint32_t i = 0; i < numRows; i++) {
            vector<int> rowVector;
            if (i == 0) {
                rowVector.push_back(1);
            }
            else if (i == 1) {
                rowVector.push_back(1);
                rowVector.push_back(1);
            }
            else {
                rowVector.push_back(1);
                vector<int> preRowVector = resultVector[resultVector.size() - 1];
                for (uint32_t i = 0; i < preRowVector.size() - 1; i++) {
                    int value = preRowVector[i] + preRowVector[i+1];
                    rowVector.push_back(value);
                }
                rowVector.push_back(1);
            }
            resultVector.push_back(rowVector);
        }
        return resultVector;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<vector<int>> resultVector = solution.generate(5);
    cout<<"get result"<<endl;
    return 0;
}
