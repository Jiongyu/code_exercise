/**
 * @file 33_ComplexListClone.cpp
 * @author your name (you@domain.com)
 * @brief   输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
 *          另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷
 *          贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序
 *          会直接返回空）
 * @version 0.1
 * @date 2020-05-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)   return NULL;
        RandomListNode* currentNode = pHead;

        //1、在每个节点后插入复制自己的节点
        while (currentNode != NULL)
        {
            RandomListNode *cloneNode = new RandomListNode(currentNode->label);
            RandomListNode *nextNode = currentNode->next;
            currentNode->next = cloneNode;
            cloneNode->next = nextNode;
            currentNode = nextNode;
        }
        
        // 2、第二步，对复制节点的 random 链接进行赋值。
        currentNode = pHead;
        while (currentNode != NULL)
        {
            currentNode->next->random = currentNode->random == NULL ? NULL : currentNode->random->next;
            currentNode = currentNode->next->next;
        }
        
        //3、拆分链表，将链表拆分为原链表和复制后的链表
        currentNode = pHead;
        RandomListNode *pCloneNode = pHead->next;
        while (currentNode != NULL)
        {
            RandomListNode *cloneNode = currentNode->next;
            currentNode->next = cloneNode->next;
            cloneNode->next = cloneNode->next == NULL ? NULL : cloneNode->next->next;
            currentNode = currentNode->next;
        }
        return pCloneNode;        
    }
};
