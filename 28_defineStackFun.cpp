/**
 * @file 28_defineStackFun.cpp
 * @author your name (you@domain.com)
 * @brief   定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
            注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。
 * @version 0.1
 * @date 2020-04-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */



#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        stackData.push(value);
        if(stackMin.empty()) stackMin.push(value);
        if(value < stackMin.top()) stackMin.push(value);
    }
    void pop() {
        if(stackData.empty()) return;
        if(stackData.top() == stackMin.top())  stackMin.pop();
        stackData.pop();
    }
    int top() {
        return stackData.top();
    }
    int min() {
        return stackMin.top();
    }
private:
    stack<int> stackData,stackMin;
};