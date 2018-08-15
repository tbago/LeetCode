//
//  main.cpp
//  symmetric-tree
//
//  Created by tbago on 2018/8/15.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return innerIsSymmetric(root);
    }
private:
    bool innerIsSymmetric(TreeNode *root) {
        stack<TreeNode *> stack;
        stack.push(root->left);
        stack.push(root->right);
        
        TreeNode *compareNode1 = NULL;
        TreeNode *compareNode2 = NULL;
        while (!stack.empty()) {
            compareNode1 = stack.top();
            stack.pop();
            compareNode2 = stack.top();
            stack.pop();
            if (compareNode1 == NULL && compareNode2 == NULL) {
                continue;
            }
            else if (compareNode1 == NULL || compareNode2 == NULL) {
                return false;
            }
            else if (compareNode1->val != compareNode2->val) {
                return false;
            }
            stack.push(compareNode1->left);
            stack.push(compareNode2->right);
            stack.push(compareNode1->right);
            stack.push(compareNode2->left);
        }
        return true;
    }
    bool innerIsSymmetricV2(TreeNode *leftTree, TreeNode *rightTree) {
        if (leftTree == NULL && rightTree == NULL) {
            return true;
        }
        else if (leftTree == NULL || rightTree == NULL) {
            return false;
        }
        else if (leftTree->val == rightTree->val) {
            return innerIsSymmetricV2(leftTree->left, rightTree->right) && innerIsSymmetricV2(leftTree->right, rightTree->left);
        }
        else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *inputTree = new TreeNode(1);
    inputTree->left = new TreeNode(2);
    inputTree->right = new TreeNode(2);
//    inputTree->left->left = new TreeNode(3);
    inputTree->left->right = new TreeNode(3);
//    inputTree->right->left = new TreeNode(4);
    inputTree->right->right = new TreeNode(3);
    Solution solution;
    std::cout<<"symmetric tree result is "<<solution.isSymmetric(inputTree)<<std::endl;
    return 0;
}
