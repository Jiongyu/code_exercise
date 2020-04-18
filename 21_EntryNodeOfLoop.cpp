/**
 * @file 21_EntryNodeOfLoop.cpp
 * @author your name (you@domain.com)
 * @brief   给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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

    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        ListNode *fast = pHead;
        ListNode *low = pHead;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            low = low->next;
            if(fast == low) break;
        }
        
        if(!fast || !fast->next)return NULL;
        low = pHead;
        while (low != fast)
        {
            low = low->next;
            fast = fast->next;
        }
        return fast;
    }
};