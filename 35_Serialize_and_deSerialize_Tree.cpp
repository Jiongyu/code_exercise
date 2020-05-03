/**
 * @file 35_Serialize_and_deSerialize_Tree.cpp  
 * @author your name (you@domain.com)
 * @brief   请实现两个函数，分别用来序列化和反序列化二叉树
 * 
 * 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式
 * 保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化
 * 可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化
 * 的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！
 *  表示一个结点值的结束（value!）。
 * 二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，
 * 重构二叉树。
 * 例如，我们可以把一个只有根节点为1的二叉树序列化为"1,"，然后通过自
 * 己的函数来解析回这个二叉树
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include <string.h>

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
    char* Serialize(TreeNode *root) {    
        if(!root) return "#";
        string s_data = to_string(root->val);
        s_data.push_back(',');
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);
        char *ret = new char[strlen(left) + strlen(right) + s_data.size() ];
        strcpy(ret, s_data.c_str());
        strcat(ret, left);
        strcat(ret, right);
        return ret;
    }

    TreeNode *decode(char *&str)
    {
        if(*str == '#'){
            str++;
            return NULL;
        }    
        int number = 0;
        while (*str != ',')
        {
            number = number * 10 + (*(str++) - '0');
        }
        str ++;
        TreeNode *root = new TreeNode(number);
        root->left = decode(str);
        root->right = decode(str);
        return root;
    }

    TreeNode* Deserialize(char *str) {
        return(decode(str));        
    }
};