//
//  main.cpp
//  same-tree
//
//  Created by tbago on 2018/8/9.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode *pIndex = p;
        TreeNode *qIndex = q;    
        return compareTreeNode(pIndex, qIndex);
    }
private:
    bool compareTreeNode(TreeNode *pIndex, TreeNode *qIndex) {
        if (pIndex == NULL && qIndex == NULL) {
            return true;
        }
        else if (pIndex == NULL || qIndex == NULL) {
            return false;
        }
        else if (pIndex->val != qIndex->val) {
            return false;
        }
        
        bool ret = compareTreeNode(pIndex->left, qIndex->left);
        if (!ret) {
            return ret;
        }
        ret = compareTreeNode(pIndex->right, qIndex->right);
        if (!ret) {
            return ret;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *inputDemo1 = new TreeNode(1);
    inputDemo1->left = NULL;
    inputDemo1->right = new TreeNode(3);
    
    TreeNode *inputDemo2 = new TreeNode(1);
    inputDemo2->left = new TreeNode(2);
    inputDemo2->right = new TreeNode(3);
    
    Solution solution;
    cout<<"same tree result is "<<solution.isSameTree(inputDemo1, inputDemo2)<<endl;
    return 0;
}
