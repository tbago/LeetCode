//
//  main.cpp
//  binary-tree-level-order-traversal
//
//  Created by tbago on 2018/8/14.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultVector;
        if (root == NULL) {
            return resultVector;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            uint32_t queueSize = (uint32_t)queue.size();
            vector<int> tempVector;
            for (uint32_t i = 0; i < queueSize; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                tempVector.push_back(node->val);
                if (node->left != NULL) {
                    queue.push(node->left);
                }
                if (node->right != NULL) {
                    queue.push(node->right);
                }
            }
            resultVector.push_back(tempVector);
        }
        return resultVector;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
