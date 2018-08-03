//
//  main.cpp
//  implement-strstr
//
//  Created by tbago on 03/08/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) {
            return 0;
        }
        int resultIndex = -1;
        int needleStringLength = (int)needle.length();
        for (uint32_t i = 0; i < haystack.length(); i++) {
            char startChar = *(haystack.c_str() + i);
            char needleChar = *needle.c_str();
            int remainLength = (int)haystack.length() - i;
            if (startChar == needleChar && needleStringLength == 1) {
                resultIndex = i;
                break;
            }
            else if (startChar == needleChar && remainLength >= needleStringLength) {
                bool sameString = true;
                for (uint32_t j = 0; j < needle.length(); j++) {
                    char haystackChar = *(haystack.c_str() + j + i);
                    char needleChar = *(needle.c_str() + j);
                    if (haystackChar != needleChar) {
                        sameString = false;
                        break;
                    }
                }
                if (sameString) {
                    resultIndex = i;
                    break;
                }
            }
        }
        return resultIndex;
    } 
};

int main(int argc, const char * argv[]) {
    string haystack = "mississippi";
    string needle = "issi";
    Solution solution;
    cout<<"haystack = "<<haystack<<", needle = "<<needle<<endl;
    cout<<"result = "<<solution.strStr(haystack, needle)<<endl;
    return 0;
}
