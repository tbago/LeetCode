//
//  main.cpp
//  longest-common-prefix
//
//  Created by tbago on 2018/7/25.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ///< 第一次少了这个判断，崩溃了
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() ==1) {
            return strs[0];
        }
        
        string resultString = "";
        int minimizeLength = getMinimizeStringLength(strs);
        for (uint32_t i = 0; i < minimizeLength; i++) {
            string prefix = "";
            char firstCharValue = *(strs[0].c_str() + i);
            bool samePrefix = true;
            for (uint32_t j = 1; j < strs.size(); j++) {
                char charValue = *(strs[j].c_str() + i);
                if (charValue != firstCharValue) {
                    samePrefix =false;
                    break;
                }
            }
            if (!samePrefix) {
                break;
            }
            else {
                resultString += firstCharValue;
            }
        }
        return resultString;
    }
private:
    int getMinimizeStringLength(vector<string>& strs) {
        int minimizeLength = (int)strs[0].length();
        for (uint32_t i = 1; i < strs.size(); i++) {
            if (strs[i].length() < minimizeLength) {
                minimizeLength = (int)strs[i].length();
            }
        }
        return minimizeLength;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> demoVector;
//    demoVector.push_back("f");
//    demoVector.push_back("flow");
//    demoVector.push_back("flight");
    Solution solution;
    cout<<"solution is "<<solution.longestCommonPrefix(demoVector)<<endl;
    return 0;
}
