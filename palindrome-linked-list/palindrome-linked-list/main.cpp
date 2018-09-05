//
//  main.cpp
//  palindrome-linked-list
//
//  Created by tbago on 2018/9/3.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head== NULL || head->next == NULL) {
            return true;
        }
        stack<ListNode *> stack;
        while (head!= NULL) {
            if (stack.empty()) {
                stack.push(head);
            }
            else {
                if (stack.top()->val == head->val) {
                    stack.pop();
                }
                else {
                    stack.push(head);
                }
            }
            head = head->next;
        }
        return stack.size() == 0;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *inputDemo = new ListNode(1);
    inputDemo->next = new ListNode(3);
    inputDemo->next->next = new ListNode(4);
    inputDemo->next->next->next = new ListNode(4);
    inputDemo->next->next->next->next = new ListNode(1);
    Solution solution;
    cout<<"solution is "<<solution.isPalindrome(inputDemo)<<endl;
    return 0;
}
