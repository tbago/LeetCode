//
//  main.cpp
//  revert_print
//
//  Created by tbago on 2020/4/14.
//  Copyright © 2020 tbago. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using std::vector;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> resultVector;
        if (head == NULL) {
            return resultVector;
        }

        ListNode *index = head;
        std::stack<ListNode *> stack;
        while (index != NULL) {
            stack.push(index);
            index = index->next;
        }

        while (!stack.empty()) {
            ListNode *node = stack.top();
            resultVector.push_back(node->val);
            stack.pop();
        }
        return resultVector;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *header = new ListNode(3);
    ListNode *item = new ListNode(2);
    ListNode *item2 = new ListNode(1);
    header->next = item;
    item->next = item2;
    Solution solution;
    vector<int> resultVector = solution.reversePrint(header);
    return 0;
}
