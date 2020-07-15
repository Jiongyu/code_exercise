/**
 * @file 55_TreeDepth.cpp
 * @author your name (you@domain.com)
 * @brief   输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
 *          形成树的一条路径，最长路径的长度为树的深度。
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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)   return 0;
        else{
            int temp1 = TreeDepth(pRoot->left);
            int temp2 = TreeDepth(pRoot->right);
            return (temp1 > temp2) ? (1 + temp1) : (1+ temp2);
        }
    }
};