/**
 * @file 19_reOrderArray.cpp
 * @author your name (you@domain.com)
 * @brief   输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 *          使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后
 *          半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变.
 * @version 0.1
 * @date 2020-04-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> result;
        int num=array.size();
        for(int i=0;i<num;i++)
            {
            if(array[i]%2==1)
                result.push_back(array[i]);
        }
        for(int i=0;i<num;i++)
            {
            if(array[i]%2==0)
                result.push_back(array[i]);
        }
        array=result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int>data;
    for(int i = 0 ; i < 10; i++)
        data.push_back(i);
    Solution demo;
    demo.reOrderArray(data);
    vector<int>::iterator it;
    for(it = data.begin(); it != data.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}


