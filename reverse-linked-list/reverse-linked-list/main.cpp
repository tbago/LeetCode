//
//  main.cpp
//  reverse-linked-list
//
//  Created by tbago on 2018/9/3.
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        innerReverseList(head);
        return reverseHead;
    }
private:
    void innerReverseList(ListNode *node) {
        if (node->next == NULL) {
            reverseHead = node;
            reverseNode = node;
        }
        else {
            innerReverseList(node->next);
            reverseNode->next = node;
            reverseNode = reverseNode->next;
        }
    }
private:
    ListNode *reverseHead;
    ListNode *reverseNode;
};

int main(int argc, const char * argv[]) {
    ListNode *inputDemo = new ListNode(1);
    inputDemo->next = new ListNode(2);
    inputDemo->next->next = new ListNode(3);
    inputDemo->next->next->next = new ListNode(4);
    inputDemo->next->next->next->next = new ListNode(5);
    
    Solution solution;
    ListNode *resultNode = solution.reverseList(inputDemo);
    std::cout<<"get sulution"<<std::endl;
    return 0;
}
