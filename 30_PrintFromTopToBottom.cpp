/**
 * @file 30_PrintFromTopToBottom.cpp
 * @author your name (you@domain.com)
 * @brief   从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * @version 0.1
 * @date 2020-04-20
 * 
 * @copyright Copyright (c) 2020
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
            vector<int>data;
            if(root == NULL) return data;
            queue<TreeNode*>treeQueue;
            TreeNode *front;
            treeQueue.push(root);
            while (! treeQueue.empty())
            {
                front = treeQueue.front();
                data.push_back(front->val);
                treeQueue.pop();

                if(front->left)
                    treeQueue.push(front->left);
                if(front->right)
                    treeQueue.push(front->right);
            }
            return data;
    }
};