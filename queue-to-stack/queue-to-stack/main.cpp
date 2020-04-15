//
//  main.cpp
//  queue-to-stack
//
//  Created by tbago on 2020/4/15.
//  Copyright © 2020 tbago. All rights reserved.
//

#include <iostream>
#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        inputQueue.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (inputQueue.size() == 0) {
            return -1;  //no element
        }
        if (inputQueue.size() == 1) {
            int value = inputQueue.front();
            inputQueue.pop();
            return value;
        }

        std::queue<int> tempQueue;
        while (inputQueue.size() > 1) {
            tempQueue.push(inputQueue.front());
            inputQueue.pop();
        }
        int value = inputQueue.front();
        inputQueue.pop();
        while (tempQueue.size() > 0) {
            inputQueue.push(tempQueue.front());
            tempQueue.pop();
        }
        return value;
    }

    /** Get the top element. */
    int top() {
        if (inputQueue.size() == 0) {
            return -1;
        }
        if (inputQueue.size() == 1) {
            return inputQueue.front();
        }

        std::queue<int> tempQueue;
        while (inputQueue.size() > 1) {
            tempQueue.push(inputQueue.front());
            inputQueue.pop();
        }
        int value = inputQueue.front();
        tempQueue.push(value);
        inputQueue.pop();
        while (tempQueue.size() > 0) {
            inputQueue.push(tempQueue.front());
            tempQueue.pop();
        }
        return value;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return inputQueue.empty();
    }
private:
    std::queue<int> inputQueue;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
