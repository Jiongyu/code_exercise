/**
 * @file 44_PrintMinNumber.cpp
 * @author your name (you@domain.com)
 * @brief   输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的
 *          所有数字中最小的一个。例如输入数组 {3，32，321}，则打印出这三个数字能
 *          排成的最小数字为 321323。
 * @version 0.1
 * @date 2020-07-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

// 编译  g++ 44_PrintMinNumber.cpp -o 44_PrintMinNumber -std=c++11

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string PrintMinNumber(vector<int> list){

        if(list.empty()) return "#";
        int length = list.size();
        sort(list.begin(), list.end(), comp);
        string res;
        for(int i = 0; i < length; i++){
            res += to_string(list[i]);
        }
        return res;    
    }
private:
    static bool comp(int a , int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};

int main(int argc, char const *argv[])
{
    vector<int>data = {1,22,12,56,34};
    Solution demo;
    cout << demo.PrintMinNumber(data) << endl;
    return 0;
}
