/**
 * @file 22_ReverseList.cpp
 * @author your name (you@domain.com)
 * @brief 输入一个链表，反转链表后，输出新链表的表头。
 * @version 0.1
 * @date 2020-04-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        stack<int>data;
        ListNode *temp = pHead;
        while (temp)
        {
            data.push(temp->val);
            temp = temp->next;
        }
        temp = pHead;
        while (temp)
        {
            temp->val = data.top();
            data.pop();
            temp = temp->next;
        }
        return pHead;
    }
};