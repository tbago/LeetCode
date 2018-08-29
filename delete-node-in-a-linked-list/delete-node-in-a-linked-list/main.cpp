//
//  main.cpp
//  delete-node-in-a-linked-list
//
//  Created by tbago on 2018/8/29.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static ListNode *head;

///< 题目比较难读懂，原来node是代表链表中的某个节点，那很简单了，只要把下一个节点的值复制过来，然后删除下一个节点就完成了。
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode *tempNode = node->next;
        node->next = node->next->next;
        delete tempNode;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
