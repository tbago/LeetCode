//
//  main.cpp
//  path-sum
//
//  Created by tbago on 17/08/2018.
//  Copyright © 2018 tbago. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        m_sum = sum;
        return innerHasPathSum(root, 0);
    }
private:
    bool innerHasPathSum(TreeNode *node, int currentValue) {
        if (node == NULL) {
            return false;
        }
        if (node->val + currentValue == m_sum && node->left == NULL && node->right == NULL) {
            return true;
        }
        currentValue += node->val;
        bool leftValue = innerHasPathSum(node->left, currentValue);
        bool rightValue = innerHasPathSum(node->right, currentValue);
        return leftValue || rightValue;
    }
private:
    int m_sum;
};

int main(int argc, const char * argv[]) {
    TreeNode *inputTree = new TreeNode(5);
    inputTree->left = new TreeNode(4);
    inputTree->right = new TreeNode(8);
    inputTree->left->left = new TreeNode(11);
    inputTree->left->left->left = new TreeNode(7);
    inputTree->left->left->right = new TreeNode(2);
    inputTree->right->left = new TreeNode(13);
    inputTree->right->right = new TreeNode(4);
    inputTree->right->right->right = new TreeNode(1);

    Solution solution;
    std::cout<<"result is "<<solution.hasPathSum(inputTree, 23)<<std::endl;
    return 0;
}
