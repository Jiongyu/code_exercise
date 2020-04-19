/**
 * @file 24_HasSubtree.cpp
 * @author your name (you@domain.com)
 * @brief   输入两棵二叉树A，B，判断B是不是A的子结构。
 *          （ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        return( isSubtreeWithRoot(pRoot1,pRoot2) ||  \
                isSubtreeWithRoot(pRoot1->left, pRoot2) || \
                isSubtreeWithRoot(pRoot1->right, pRoot2));
    }

    bool isSubtreeWithRoot(TreeNode* node1, TreeNode* node2){
        if(node2 == NULL) return true;
        if(node1 == NULL) return false;
        if(node2->val != node1->val)    return false;
        return( isSubtreeWithRoot(node1->left,node2->left) && \
                isSubtreeWithRoot(node1->right, node2->right)); 
    }
};