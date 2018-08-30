//
//  main.cpp
//  isomorphic-strings
//
//  Created by tbago on 2018/8/29.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> charMap;
        string outString;
        for (uint32_t i = 0; i < s.length(); i++) {
            char originChar = s[i];
            map<char, char>::iterator it = charMap.find(originChar);
            if (it != charMap.end()) {
                outString += it->second;
            }
            else {
                char replaceChar = t[i];
                charMap[originChar] = replaceChar;
                outString += replaceChar;
            }
        }
        return outString == t;
    }
};

int main(int argc, const char * argv[]) {
    string inputDemo = "ac";
    string inputDemo2 = "aa";
    Solution solution;
    cout<<"solution is "<<solution.isIsomorphic(inputDemo, inputDemo2)<<endl;
    return 0;
}
