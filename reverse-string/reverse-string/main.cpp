//
//  main.cpp
//  reverse-string
//
//  Created by tbago on 2018/9/7.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string resultString;
        for (string::reverse_iterator r_it = s.rbegin(); r_it!=s.rend(); r_it++) {
            resultString += *r_it;
        }
        return resultString;
    }
};

int main(int argc, const char * argv[]) {
    string inputDemo = "A man, a plan, a canal: Panama";
    Solution solution;
    cout<<"solution is "<<solution.reverseString(inputDemo)<<endl;
    return 0;
}
