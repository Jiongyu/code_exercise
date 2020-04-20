/**
 * @file 30_PrintFromTopToBottom.cpp
 * @author your name (you@domain.com)
 * @brief   
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
    /**
     * @brief   从上往下打印出二叉树的每个节点，同层节点从左至右打印。
     * 
     * @param root 
     * @return vector<int> 
     */
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

    /**
     * @brief   从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
     * 
     * @param pRoot 
     * @return vector<vector<int> > 
     */
    vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>>data;
            if(pRoot == NULL) return data;
            queue<TreeNode*>treeQueue;
            treeQueue.push(pRoot);
            while (! treeQueue.empty())
            {
                int begin = 0 , end = treeQueue.size();
                vector<int>temp;
                while (begin < end)
                {
                    TreeNode *front = treeQueue.front();    
                    treeQueue.pop();
                    temp.push_back(front->val);
                    if(front->left)
                        treeQueue.push(front->left);
                    if(front->right)
                        treeQueue.push(front->right);
                    begin ++;
                }
                data.push_back(temp);
            }
            return data;
    }

    /**
     * @brief   请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
     *          第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
     * @param pRoot 
     * @return vector<vector<int> > 
     */
    vector<vector<int> > PrintFontStyle(TreeNode* pRoot) { 
        vector<vector<int>>data;
        if(pRoot == NULL) return data;
        queue<TreeNode*>treeQueue;
        treeQueue.push(pRoot);
        int reverse = 1;
        while (! treeQueue.empty())
        {
            int begin = 0 , end = treeQueue.size();
            vector<int>temp;
            while (begin < end)
            {
                TreeNode *front = treeQueue.front();    
                treeQueue.pop();
                temp.push_back(front->val);

                if(front->left)
                    treeQueue.push(front->left);
                if(front->right)
                    treeQueue.push(front->right);
                begin ++;
            }
            // 反转容器数据
            if(reverse % 2 == 0){
                vector<int> arrayRever;
                arrayRever.reserve(temp.size());
                vector<int>::reverse_iterator riter;
                for (riter=temp.rbegin();riter!=temp.rend();riter++)
                {
                    arrayRever.push_back(*riter);
                }
                temp = arrayRever;
            }
            data.push_back(temp);
            reverse ++;
        }
        return data;
    }
};