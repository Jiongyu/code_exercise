/**
 * @file 54_KthNode.cpp
 * @author your name (you@domain.com)
 * @brief   给定一棵二叉搜索树，请找出其中的第k小的结点。
 *          例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
 * @version 0.1
 * @date 2020-07-11
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

    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot != NULL){
            TreeNode *node = KthNode(pRoot->left, k);
            if(node != NULL) return node;
            index ++;
            if(index == k) return pRoot;
            node = KthNode(pRoot->right, k);
            if(node != NULL) return node;
        }
        return NULL;
    }

private:
    int index = 0;
};