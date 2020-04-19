/**
 * @file 25_MirrorTree.cpp
 * @author your name (you@domain.com)
 * @brief   操作给定的二叉树，将其变换为源二叉树的镜像。
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return;       
        swap(pRoot);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
private:
    void swap(TreeNode* node){
        TreeNode *temp;
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};