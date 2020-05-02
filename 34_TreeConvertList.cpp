/**
 * @file 34_TreeConvertList.cpp
 * @author your name (you@domain.com)
 * @brief   输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 *          要求不能创建任何新的结点，只能调整树中结点指针的指向。
 * @version 0.1
 * @date 2020-05-02
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
    // 中序遍历
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		if(pRootOfTree == nullptr) return nullptr;
		TreeNode * pre = nullptr;
		convertHelper(pRootOfTree, pre);
		TreeNode *res = pRootOfTree;
		while (res->left)
		{
			res = res->left;
		}
		return res;
    }
	// 所以如果有需求想改变指针所指的对象（换句话说，就是要改变指针里面存的地址），
	// 就要使用指针引用。
	void convertHelper(TreeNode *cur, TreeNode *&pre)
	{
		if(cur == nullptr) return;
		convertHelper(cur->left, pre);
		
		// 相邻节点前驱后继赋值
		cur->left = pre;
		if(pre)	pre->right = cur;
		pre = cur;

		convertHelper(cur->right, pre);
	}
};