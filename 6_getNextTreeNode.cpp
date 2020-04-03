/**
 * @file getNextTreeNode.cpp
 * @author your name (you@domain.com)
 * @brief   给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 *          注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 * @version 0.1
 * @date 2020-04-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;  // 指向父节点
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return  NULL;

        // 根节点右孩子存在
        if(pNode->right != NULL){
            TreeLinkNode* rightNode = pNode->right;
            while (rightNode->left != NULL)
            {
                rightNode = rightNode->left;
            }
            return rightNode;
        }
        
        // 节点不是根节点
        while(pNode->next != NULL)
        {
            TreeLinkNode *parentNode = pNode->next;
            if (parentNode->left == pNode){
                return parentNode;            
            } 
            pNode = parentNode;
        }
        return NULL;
    }
};

// 中序遍历
void inOrderTraverse(struct TreeLinkNode *tree)
{
    if(tree == NULL)
        return;
    inOrderTraverse(tree->left);
    std::cout << tree->val << " ";
    inOrderTraverse(tree->right);
}


int main(int argc, char const *argv[])
{
    struct TreeLinkNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7);
    
    node1.val = 1;
    node1.left = &node2;
    node1.right = &node3;
    node1.next = NULL;

    node2.val = 2;
    node2.left = &node4;
    node2.right = &node5;
    node2.next = &node1;

    node3.val = 3;
    node3.left = &node6;
    node3.right = &node7;
    node3.next = &node1;

    node4.val = 4;
    node4.left = NULL;
    node4.right = NULL;
    node4.next = &node2;

    node5.val = 5;
    node5.left = NULL;
    node5.right = NULL;
    node5.next = &node2;

    node6.val = 6;
    node6.left = NULL;
    node6.right = NULL;
    node6.next = &node3;

    node7.val = 7;
    node7.left = NULL;
    node7.right = NULL;
    node7.next = &node3;


    std::cout << "\n中序遍历：\n";
    inOrderTraverse(&node1);
    std::cout << "\nnode3 中序下一节点：\n";
    Solution demo;
    struct TreeLinkNode *node;
    node = demo.GetNext(&node3);
    std::cout << node->val<<std::endl;
    return 0;
}
