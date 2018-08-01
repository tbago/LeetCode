//
//  main.cpp
//  unique-morse-code-words
//
//  Created by tbago on 2018/8/1.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseResultVector;
        for (uint32_t i = 0; i < words.size(); i++) {
            bool sameResult = false;
            string morseResult = convertWordToMorse(words[i]);
            for (uint32_t j = 0; j < morseResultVector.size(); j++) {
                string morseValue = morseResultVector[j];
                if (morseValue == morseResult) {
                    sameResult = true;
                    break;
                }
            }
            if (!sameResult) {
                morseResultVector.push_back(morseResult);
            }
        }
        return (int)morseResultVector.size();
    }
    
    string convertWordToMorse(string word) {
        static vector<string> morseVector = {".-","-...","-.-.","-..",".",
                                            "..-.","--.","....","..",".---",
                                            "-.-",".-..","--","-.","---",
                                            ".--.","--.-",".-.","...","-",
                                            "..-","...-",".--","-..-","-.--",
                                            "--.."};
        
        const char *charIndex = word.c_str();
        string resultString = "";
        for (uint32_t i = 0; i < word.length(); i++) {
            uint32_t index = *(charIndex + i) - 'a';
            resultString.append(morseVector[index]);
        }
        return resultString;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
