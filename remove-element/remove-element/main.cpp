//
//  main.cpp
//  remove-element
//
//  Created by tbago on 2018/7/26.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(vector<int>::iterator it = nums.begin(); it != nums.end();) {
            if (*it == val) {
                it = nums.erase(it);
            }
            else {
                it++;
            }
        }
        return (int)nums.size();
    }
};

int main(int argc, const char * argv[]) {
    vector<int> demoVector;
    demoVector.push_back(0);
    demoVector.push_back(1);
    demoVector.push_back(2);
    demoVector.push_back(2);
    demoVector.push_back(3);
    demoVector.push_back(0);
    demoVector.push_back(4);
    demoVector.push_back(2);
    Solution solution;
    cout<<"remain count: "<<solution.removeElement(demoVector, 2)<<endl;
    return 0;
}
