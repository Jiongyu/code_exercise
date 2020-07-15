/**
 * @file 71_lowestCommonAncestor.cpp
 * @author your name (you@domain.com)
 * @brief   给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

            百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
            最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度
            尽可能大（一个节点也可以是它自己的祖先）。”

 * @date 2020-07-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root->val;
        int pVal = p->val;
        int qVal = q->val;
        if(pVal > rootVal && qVal > rootVal){
            return lowestCommonAncestor(root->right, p, q);
        }else if (pVal < rootVal && qVal < rootVal)
        {
           return lowestCommonAncestor(root->left, p, q);
        }else{
            return root;
        } 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
