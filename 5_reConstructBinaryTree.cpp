/**
 * @file reConstructBinaryTree.cpp
 * @author your name (you@domain.com)
 * @brief   输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
            假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
            例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列
            {4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * @version 0.1
 * @date 2020-04-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

//  Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {

        if(pre.empty() || vin.empty())
            return NULL;
        int count = 0;
        int len = vin.size();
        for(int i = 0; i < len; i++){
            if(pre[0] == vin[i]){
                count++;
            }
        }
        if(count != 1)
            return NULL;
        
        vector<int>pre_left, pre_right, vin_left, vin_right;
        int val = pre[0];
        struct TreeNode *root = new TreeNode(val);
        int pos;
        for(pos = 0; pos < len; pos ++){
            if(vin[pos] == val)
                break;
        }
        for(int i = 0 ;  i < len ; i++){
            if(i < pos){
                vin_left.push_back(vin[i]);
                pre_left.push_back(pre[i + 1]);
            }else if(i > pos){
                vin_right.push_back(vin[i]);
                pre_right.push_back(pre[i]);
            }
        }
        root->left = reConstructBinaryTree(pre_left, vin_left);
        root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
    }
};

// 前序遍历
void preOrderTraverse(struct TreeNode *tree)
{
    if(tree == NULL)
        return;
    std::cout << tree->val << " ";
    preOrderTraverse(tree->left);
    preOrderTraverse(tree->right);
}

// 中序遍历
void inOrderTraverse(struct TreeNode *tree)
{
    if(tree == NULL)
        return;
    inOrderTraverse(tree->left);
    std::cout << tree->val << " ";
    inOrderTraverse(tree->right);
}

// 后序遍历
void postOrderTraverse(struct TreeNode *tree)
{
    if(tree == NULL)
        return;
    postOrderTraverse(tree->left);
    postOrderTraverse(tree->right);
    std::cout << tree->val << " ";

}

int main(int argc, char const *argv[])
{
    vector<int>pre = {1,2,4,7,3,5,6,8};
    vector<int>vin = {4,7,2,1,5,3,8,6};
    struct TreeNode *tree = NULL;

    Solution demo;
    tree = demo.reConstructBinaryTree(pre, vin);

    std::cout << "\n前序遍历:\n";
    preOrderTraverse(tree);
    std::cout << "\n中序遍历:\n";
    inOrderTraverse(tree);
    std::cout << "\n后序遍历:\n";
    postOrderTraverse(tree);
    return 0;
}
