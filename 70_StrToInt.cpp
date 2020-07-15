/**
 * @file 70_StrToInt.cpp
 * @author your name (you@domain.com)
 * @brief   将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
 *          数值为0或者字符串不是一个合法的数值则返回0
            输入描述:
            输入一个字符串,包括数字字母符号,可以为空
            输出描述:
            如果是合法的数值表达则返回该数字，否则返回0
 * @version 0.1
 * @date 2020-07-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()) return 0;
        int length = str.length();
        int temp;
        int data = 0;
        int digit = 1;
        int i = length - 1;
        for(; i >= 1; --i){
            if(str[i] < '0' || str[i] > '9') return 0;
            temp  = str[i] - '0';
            // cout << temp << endl;
            temp *= digit;
            data += temp;
            digit *= 10;
        }
        temp  = str[i];
        if(temp >= '0' && temp <= '9'){
            temp  = str[i] - '0';
            // cout << temp << endl;
            temp *= digit;
            data += temp;
            return data;
        }else if (temp == '+')
        {
            return data;
        }else if (temp == '-')
        {
            return -data;
        }else
        {
            return 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution demo;
    string data = "123";
    cout << demo.StrToInt(data) << endl;
    return 0;
}
