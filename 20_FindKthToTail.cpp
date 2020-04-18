/**
 * @file 20_FindKthToTail.cpp
 * @author your name (you@domain.com)
 * @brief   输入一个链表，输出该链表中倒数第k个结点。
 * @version 0.1
 * @date 2020-04-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL)   return NULL;
        ListNode *temp = pListHead;
        for(int i = 0 ; i < k ; i ++)
            /*记得判断*/
            if(!temp) 
                return NULL;
            else 
                temp = temp->next;

        ListNode *pos_k = pListHead;
        while (temp)
        {
            temp = temp->next;
            pos_k = pos_k->next;
        }
        return pos_k;
    }
};