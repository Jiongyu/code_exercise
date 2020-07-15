/**
 * @file 52_FindFirstCommonNode.cpp
 * @author your name (you@domain.com)
 * @brief   输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，
 *          所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
 * @version 0.1
 * @date 2020-07-09
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL) return NULL;
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        int flag1 = 0, flag2 = 0;
        while (p1 != p2)
        {
            if(p1 == NULL){ 
                p1 = pHead2;
                flag1 += 1;
            }else p1 = p1->next;

            if(p2 == NULL){
                p2 = pHead1;
                flag2 += 1;
            }else p2 = p2->next;
            if(flag1 == 2 || flag2 == 2)    return NULL;
        }
        return p1;
    }
};