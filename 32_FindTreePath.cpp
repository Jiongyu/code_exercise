/**
 * @file 32_FindTreePath.cpp
 * @author your name (you@domain.com)
 * @brief   输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为
 *          输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结
 *          点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长
 *          度大的数组靠前)
 * @version 0.1
 * @date 2020-04-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <vector>

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL)    return ret;
        getPath(root, expectNumber);
        return ret;        
    }

private:
    void getPath(TreeNode* root,int expectNumber){
        temp.push_back(root->val);
        if(expectNumber - root->val == 0 && root->left == NULL && root->right == NULL){
            ret.push_back(temp);
        }else{
            if( root->left != NULL ){
                getPath(root->left, expectNumber - root->val);
            }
            if(root->right != NULL){
                getPath(root->right, expectNumber - root->val);
            }
        }
        temp.pop_back();
    }

private:
    vector<vector<int>>ret;
    vector<int>temp;
};