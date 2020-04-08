/**
 * @file 17_deleteDuplication.cpp
 * @author your name (you@domain.com)
 * @brief   在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
 *          重复的结点不保留，返回链表头指针。 
 *          例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 * @version 0.1
 * @date 2020-04-08
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL) return pHead;

        ListNode *head = new ListNode(0);
        head->next = pHead;
        ListNode *pre = head, *last = head->next;
        while (last != NULL)
        {
            if(last->next != NULL && last->val == last->next->val)
            {
                while (last->next != NULL && last->val == last->next->val)
                {
                    last = last->next;
                }
                pre->next = last->next;
                last = last->next;
            }else
            {
                pre = pre->next;
                last = last->next;
            }
        }
        return head->next;
    }
};


int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    ListNode *temp1 = new ListNode(2);
    ListNode *temp2 = new ListNode(3);
    ListNode *temp3 = new ListNode(3);
    ListNode *temp4 = new ListNode(4);
    ListNode *temp5 = new ListNode(4);
    ListNode *temp6 = new ListNode(5);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp6;
    temp6->next = NULL;

    Solution demo;
    ListNode *test = NULL;
    test = demo.deleteDuplication(head);

    while (test != NULL)
    {
        std::cout << test->val << " ";
        test = test->next;
    }
    return 0;
}
