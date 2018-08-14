//
//  main.cpp
//  binary-tree-level-order-traversal
//
//  Created by tbago on 2018/8/10.
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> resultVector;
        if (root == NULL) {
            return resultVector;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        while(!queue.empty()) {
            vector<int> tempVector;
            uint32_t queueSize = (uint32_t)queue.size();
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
            resultVector.insert(resultVector.begin(), tempVector);
        }
        return resultVector;
    }
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
