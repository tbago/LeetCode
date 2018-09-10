//
//  main.cpp
//  ransom-note
//
//  Created by tbago on 2018/9/10.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (string::iterator it = ransomNote.begin(); it != ransomNote.end(); it++) {
            size_t position = magazine.find(*it);
            if (position == string::npos) {
                return false;
            }
            else {
                magazine = magazine.replace(position, 1, "");
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string ransomNode = "aa";
    string magazine = "ab";
    Solution solution;
    cout<<"soltuion is "<<solution.canConstruct(ransomNode, magazine)<<endl;
    return 0;
}
