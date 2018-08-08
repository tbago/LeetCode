//
//  main.cpp
//  remove-duplicates-sorted-list
//
//  Created by tbago on 2018/8/8.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *resultNode = head;
        while (head->next != NULL) {
            if (head->val == head->next->val) {
                head->next = head->next->next;
            }
            else {
                head = head->next;
            }
        }
        return resultNode;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    node1->next = new ListNode(1);
    node1->next->next = new ListNode(2);
    Solution solution;
    ListNode *resultNode = solution.deleteDuplicates(node1);
    std::cout<<"complate"<<std::endl;
    return 0;
}
