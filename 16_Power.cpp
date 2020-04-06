/**
 * @file 16_Power.cpp
 * @author your name (you@domain.com)
 * @brief   给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
            保证base和exponent不同时为0
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
    double Power(double base, int exponent) {
        if(base == 0)  return 0;
        if(exponent == 0)   return 1;

        double result = 1;
        int flag = 1;
        if(exponent < 0) 
        {
            exponent = -exponent;
            flag = 0;   
        }
        for (int i = 1; i <= exponent; i++){
            result *= base;
        }

        return flag ? result : (1.0 / result );
    }
};

int main(int argc, char const *argv[])
{
    double base1 = 5, exponent1 = 3, exponent2 = -3;
    Solution demo;
    std::cout << base1 << "^" << exponent1 <<": ";
    std::cout << demo.Power(base1, exponent1) << std::endl;
    std::cout << base1 << "^" << exponent2 <<": ";
    std::cout << demo.Power(base1, exponent2) << std::endl;
    return 0;
}
