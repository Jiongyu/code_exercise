
/**
 * @file 23_Merge.cpp
 * @author your name (you@domain.com)
 * @brief   输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    // 迭代
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL && pHead2 == NULL) return NULL;
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode *head = NULL;
        ListNode *current = NULL;
        while ( pHead1 != NULL && pHead2 != NULL )
        {
            if(pHead1->val <= pHead2->val){
                if(head == NULL)    head = current = pHead1;
                else{
                    current->next = pHead1;
                    current = current->next;
                }
                pHead1 = pHead1->next;
            }else{
                if(head == NULL) head = current = pHead2;
                else{
                    current->next = pHead2;
                    current = current->next;
                }
                pHead2 = pHead2->next;
            }
            
        } 
        if(pHead1 != NULL) current->next = pHead1;
        if(pHead2 != NULL) current->next = pHead2;      
        return head;
    }

    // 递归
    ListNode* MergeRecursive(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        if(pHead1->val <= pHead2->val){
            pHead1->next = MergeRecursive(pHead1->next, pHead2);
            return pHead1;
        }else{
            pHead2->next = MergeRecursive(pHead1, pHead2->next);
            return pHead2;
        }
    }
};