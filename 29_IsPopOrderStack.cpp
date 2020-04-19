/**
 * @file 29_IsPopOrderStack.cpp
 * @author your name (you@domain.com)
 * @brief   输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
 *          假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压
 *          栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序
 *          列的长度是相等的）
 * @version 0.1
 * @date 2020-04-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stack>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * @brief 【思路】借用一个辅助的栈，遍历压栈顺序，先讲第一个放入栈中，
     * 这里是1，然后判断栈顶元素是不是出栈顺序的第一个元素，这里是4，很显然1≠4，
     * 所以我们继续压栈，直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移
     * 动一位，直到不相等，这样循环等压栈顺序遍历完成，如果辅助栈还不为空，说明
     * 弹出序列不是该栈的弹出顺序。举例：入栈1,2,3,4,5,出栈4,5,3,2,1.首先1入
     * 辅助栈，此时栈顶1≠4，继续入栈2,此时栈顶2≠4，继续入栈3,此时栈顶3≠4，继续
     * 入栈4,此时栈顶4＝4，出栈4，弹出序列向后一位，此时为5，,辅助栈里面是1,2,3
     * 此时栈顶3≠5，继续入栈5,此时栈顶5=5，出栈5,弹出序列向后一位，此时为3，,辅
     * 助栈里面是1,2,3,依次执行，最后辅助栈为空。如果不为空说明弹出序列不是该栈的
     * 弹出顺序。
     * 
     * @param pushV 
     * @param popV 
     * @return true 
     * @return false 
     */

    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty()) return false;
        if(pushV.size() != popV.size()) return false;
        stack<int>temp;
        int j = 0;
        for(int i = 0 ; i < pushV.size() ; i++){
            temp.push(pushV[i]);
            if(pushV[i] == popV[j]){
                temp.pop();
                j+=1;
            }
        }
        for(; j < popV.size(); j++){
            if(popV[j] == temp.top()) temp.pop();
        }
        if(temp.empty()) return true;
        else return false;
    }
};

int main(int argc, char const *argv[])
{

    vector<int>pushList, popList;
    
    pushList.push_back(1);
    pushList.push_back(2);
    pushList.push_back(3);
    pushList.push_back(4);
    pushList.push_back(5);

    popList.push_back(4);
    popList.push_back(5);
    popList.push_back(3);
    popList.push_back(2);
    popList.push_back(1);
    
    Solution demo;
    bool flag = demo.IsPopOrder(pushList, popList);
    
    cout << flag << endl;
    return 0;
}
