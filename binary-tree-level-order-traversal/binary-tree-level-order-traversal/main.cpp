//
//  main.cpp
//  binary-tree-level-order-traversal
//
//  Created by tbago on 2018/8/10.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define MAX_SUB_TREE_NODE 10000
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        resultVector.clear();
        innerLevelOrderBottom(root);
        return resultVector;
    }
private:
    void innerLevelOrderBottom(TreeNode *node) {
        int head = 0;
        int tail = 0;
        TreeNode *subNode[MAX_SUB_TREE_NODE] = {NULL};
        TreeNode *tempNode;
        if (node != NULL) {
            subNode[head] = node;
            tail++;
            vector<int> addVector;
            addVector.push_back(node->val);
            resultVector.insert(resultVector.begin(), addVector);
        } else {
            return;
        }
        while (head < tail) {
            tempNode = subNode[head];
            vector<int> addVector;
            if (tempNode->left != NULL) {
                addVector.push_back(tempNode->left->val);
                subNode[tail] = tempNode->left;
                tail++;
            }
            if (tempNode->right != NULL) {
                subNode[tail] = tempNode->right;
                addVector.push_back(tempNode->right->val);
                tail++;
            }
            head++;
            if (addVector.size() > 0) {
                resultVector.insert(resultVector.begin(), addVector);
            }
        }
    }
private:
    vector<vector<int>> resultVector;
};

int main(int argc, const char * argv[]) {
    TreeNode *inputTree = new TreeNode(3);
    inputTree->left = new TreeNode(9);
    inputTree->right = new TreeNode(20);
    inputTree->left->left = new TreeNode(15);
    inputTree->right->right = new TreeNode(7);
    
    Solution solution;
    vector<vector<int>> resultVector = solution.levelOrderBottom(inputTree);
    cout<<"get result"<<endl;
    return 0;
}
