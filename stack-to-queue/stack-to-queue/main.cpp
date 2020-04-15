//
//  main.cpp
//  stack-to-queue
//
//  Created by tbago on 2020/4/15.
//  Copyright © 2020 tbago. All rights reserved.
//

#include <iostream>
#include <stack>

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        inputStack.push(value);
    }

    int deleteHead() {
        if (outputStack.size() == 0) {
            while (inputStack.size() > 0) {
                int value = inputStack.top();
                outputStack.push(value);
                inputStack.pop();
            }
        }
        if (outputStack.size() == 0) {
            return -1;  //no item
        }
        int value = outputStack.top();
        outputStack.pop();
        return value;
    }
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
