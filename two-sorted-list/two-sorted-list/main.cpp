//
//  main.cpp
//  two-sorted-list
//
//  Created by tbago on 2018/8/2.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        else if (l2 == NULL) {
            return l1;
        }
        
        ListNode *resultListNode = NULL;
        ListNode *resultIndexNode = NULL;
        ListNode *l1IndexNode = l1;
        ListNode *l2IndexNode = l2;
        while (l1IndexNode != NULL || l2IndexNode != NULL) {
            ListNode *newNode = NULL;
            if (l1IndexNode == NULL) {
                newNode = new ListNode(l2IndexNode->val);
                l2IndexNode = l2IndexNode->next;
            }
            else if (l2IndexNode == NULL) {
                newNode = new ListNode(l1IndexNode->val);
                l1IndexNode = l1IndexNode->next;
            }
            else if (l1IndexNode->val <= l2IndexNode->val) {
                newNode = new ListNode(l1IndexNode->val);
                l1IndexNode = l1IndexNode->next;
            }
            else {
                newNode = new ListNode(l2IndexNode->val);
                l2IndexNode = l2IndexNode->next;
            }
            if (resultIndexNode == NULL) {
                resultListNode = newNode;
                resultIndexNode = newNode;
            }
            else {
                resultIndexNode->next = newNode;
                resultIndexNode = resultIndexNode->next;
            }
        }
        return resultListNode;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *listNode1 = new ListNode(1);
    listNode1->next = new ListNode(2);
    listNode1->next->next = new ListNode(4);
    ListNode *listNode2 = NULL;
    listNode2->next = new ListNode(3);
    listNode2->next->next = new ListNode(4);
    
    Solution solution;
    ListNode *resultListNode = solution.mergeTwoLists(listNode1, listNode2);
    cout<<"merge result is"<<endl;
    ListNode *indexNode = resultListNode;
    while(indexNode != NULL) {
        cout<<" "<<indexNode->val<<"->";
        indexNode = indexNode->next;
    }
    return 0;
}
