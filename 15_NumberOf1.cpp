/**
 * @file 15_NumberOf1.cpp
 * @author your name (you@domain.com)
 * @brief   输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 * @version 0.1
 * @date 2020-04-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while (n != 0)
         {
            count ++;
            n = n & ( n - 1);
         }
         return count;
     }
};

int main(int argc, char const *argv[])
{
    int number1 = 1, number2 = -5, number3 = 1000;
    std::cout << "整数二进制含有１的个数为：\n";
    Solution demo;
    std::cout <<  number1 << " : " << demo.NumberOf1(number1) << std::endl;
    std::cout <<  number2 << " : " << demo.NumberOf1(number2) << std::endl;
    std::cout <<  number3 << " : " << demo.NumberOf1(number3) << std::endl;
    return 0;
}
