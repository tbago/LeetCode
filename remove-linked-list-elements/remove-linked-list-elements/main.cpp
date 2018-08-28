//
//  main.cpp
//  remove-linked-list-elements
//
//  Created by tbago on 2018/8/28.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *indexNode = head;
        ListNode *preNode = head;
        while(indexNode != NULL) {
            if (indexNode->val == val) {
                if (indexNode == head) {    ///<head node
                    head = head->next;
                    preNode = indexNode = head;
                }
                else {
                    preNode->next = indexNode->next;
                    indexNode = indexNode->next;
                }
            }
            else {
                preNode = indexNode;
                indexNode = indexNode->next;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *inputDemo = new ListNode(1);
    Solution solution;
    ListNode *resultNode = solution.removeElements(inputDemo, 1);
    std::cout<<"get solution"<<std::endl;
    return 0;
}
