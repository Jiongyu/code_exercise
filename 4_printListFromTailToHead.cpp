/**
 * @file printListFromTailToHead.cpp
 * @author your name (you@domain.com)
 * @brief 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
 * @version 0.1
 * @date 2020-04-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
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
    // 递归
    vector<int> result;
    vector<int> printListFromTailToHeadRecursive(ListNode* head) {
        if(head != NULL){
            printListFromTailToHeadRecursive(head->next);
            result.push_back(head->val);
        }
        return result;
    }
    
    // 非递归 栈原理
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int>consquence;
        stack<int>listData;
        while (head != NULL)
        {
            listData.push(head->val);
            head = head->next;
        }
        int len = listData.size();
        for (int i =0; i < len; i++){
            consquence.push_back(listData.top());
            listData.pop();
        }
        return consquence;
    }
};

int main(int argc, char const *argv[])
{
    struct ListNode list1(1),list2(2),list3(3),list4(4);
    list1.next = &list2;
    list2.next = &list3;
    list3.next = &list4;
    list4.next = NULL;

    Solution demo;
    vector<int>result;
    result = demo.printListFromTailToHeadRecursive(&list1);
    vector<int>::iterator iter;
    cout << "\nprintListFromTailToHeadRecursive:\n";
    for(iter = result.begin(); iter != result.end(); iter++){
        cout << *iter << " ";
    }

    result = demo.printListFromTailToHead(&list1);
    cout << "\nprintListFromTailToHead:\n";
    for(iter = result.begin(); iter != result.end(); iter++){
        cout << *iter << " ";
    }
    return 0;
}
