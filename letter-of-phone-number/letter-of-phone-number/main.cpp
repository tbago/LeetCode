//
//  main.cpp
//  letter-of-phone-number
//
//  Created by tbago on 2018/7/28.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        m_resultVector.clear();
        if (digits.length() == 0 || digits == "01" || digits == "10") {
            return m_resultVector;
        }
        m_digitsString = digits;
        m_numberLetterMap[0] = "";
        m_numberLetterMap[1] = "";
        m_numberLetterMap[2] = "abc";
        m_numberLetterMap[3] = "def";
        m_numberLetterMap[4] = "ghi";
        m_numberLetterMap[5] = "jkl";
        m_numberLetterMap[6] = "mno";
        m_numberLetterMap[7] = "pqrs";
        m_numberLetterMap[8] = "tuv";
        m_numberLetterMap[9] = "wxyz";

        pushStringResult(0, "");
        return m_resultVector;
    }
private:
    void pushStringResult(int digitsIndex, string stringResult) {
        if (stringResult.length() == m_digitsString.length()) {
            m_resultVector.push_back(stringResult);
            return;
        }
        int digitInLetterIndex = m_digitsString[digitsIndex] - '0';
        string numberLetter = m_numberLetterMap[digitInLetterIndex];
        for (int i = 0; i < numberLetter.length(); i++) {
            char charLetter = *(numberLetter.c_str() + i);
            string tempString = stringResult + charLetter;
            pushStringResult(digitsIndex + 1, tempString);
        }
    }
private:
    string m_digitsString;
    string m_numberLetterMap[10];
    vector<string> m_resultVector;
};

int main(int argc, const char * argv[]) {
    string digitsDemo = "23";
    Solution solution;
    vector<string> letterCombinationVector = solution.letterCombinations(digitsDemo);
    for (uint32_t i = 0; i < letterCombinationVector.size(); i++) {
        cout<<"result "<<i+1<<" : " << letterCombinationVector[i]<<endl;
    }
    return 0;
}
