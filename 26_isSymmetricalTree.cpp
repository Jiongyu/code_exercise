/**
 * @file 26_isSymmetricalTree.cpp
 * @author your name (you@domain.com)
 * @brief   请实现一个函数，用来判断一颗二叉树是不是对称的。
 *          注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 * @version 0.1
 * @date 2020-04-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)   return true;
        return(isSymmetrical(pRoot->left,pRoot->right));
    }
private:
    bool isSymmetrical(TreeNode* t1, TreeNode *t2){
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        if(t1->val != t2->val) return false;
        return( isSymmetrical(t1->left, t2->right) && isSymmetrical(t1->right, t2->left));
    }
};