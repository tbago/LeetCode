//
//  main.cpp
//  maximum-depth-of-binary-tree
//
//  Created by tbago on 2018/8/10.
//  Copyright © 2018年 tbago. All rights reserved.
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
    int maxDepth(TreeNode* root) {
        m_maxDepth = 0;
        innerGetMaxDepth(root, 0);
        return m_maxDepth;
    }
private:
    void innerGetMaxDepth(TreeNode *root, int currentDepth) {
        if (root == NULL) {
            return;
        }
        currentDepth++;
        if (currentDepth > m_maxDepth) {
            m_maxDepth = currentDepth;
        }
        innerGetMaxDepth(root->left, currentDepth);
        innerGetMaxDepth(root->right, currentDepth);
    }
private:
    int m_maxDepth;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
