/**
 * @file 7_twoStackList.cpp
 * @author your name (you@domain.com)
 * @brief   用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 * @version 0.1
 * @date 2020-04-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int temp;
        if(stack2.empty()){
            while (! stack1.empty())
            {
                temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
        }
        temp = stack2.top();
        stack2.pop();
        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char const *argv[])
{
    Solution demo;
    for(int i = 0 ; i < 10; i++){
        demo.push(i);
    }
    for(int i = 0 ; i < 10; i++){
        cout << demo.pop() << " ";
    }

    return 0;
}
