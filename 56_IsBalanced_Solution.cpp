/**
 * @file 56_IsBalanced_Solution.cpp
 * @author your name (you@domain.com)
 * @brief   输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 *          在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) return true;
        TreeDepth(pRoot);
        return isBalance;
    }

private:
    bool isBalance = true;

    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL || !isBalance)   return 0;
        else{
            int temp1 = TreeDepth(pRoot->left);
            int temp2 = TreeDepth(pRoot->right);
            if(abs(temp1 - temp2) > 1) isBalance = false;
            return (temp1 > temp2) ? (1 + temp1) : (1+ temp2);
        }
    }
};
