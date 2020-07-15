/**
 * @file 57_FindNumsAppearOnce.cpp
 * @author your name (you@domain.com)
 * @brief   一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 * @version 0.1
 * @date 2020-07-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty()) return;
        sort(data.begin(), data.end());
        int length = data.size();
        int index = 0;
        while (index <= length - 1)
        {
            if(data[index] == data[index + 1])  index += 2;
            else{
                *num1 = data[index];
                index += 1;
                break;
            }
        }
        
        while (index <= length - 1)
        {
            if(data[index] == data[index + 1])  index += 2;
            else{
                *num2 = data[index];
                break;
            }
        }
        
    }
};

// g++ 57_FindNumsAppearOnce.cpp -o 57_FindNumsAppearOnce -std=c++11
int main(int argc, char const *argv[])
{
    // c++ 11
    vector<int>data = {2,4,3,6,3,2,5,5};
    Solution demo;
    int num1, num2;
    demo.FindNumsAppearOnce(data,&num1,&num2);
    cout << num1 << " " << num2 << endl;
    return 0;
}
