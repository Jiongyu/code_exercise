/**
 * @file 10_jumpFloor.cpp
 * @author your name (you@domain.com)
 * @brief   一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 *          求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 * @version 0.1
 * @date 2020-04-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <math.h>
class Solution {
public:

    /**
     * @brief   一只青蛙一次可以跳上1级台阶，也可以跳上2级。
     *          求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
     * @param number 
     * @return int 
     */
    int jumpFloor(int number) {
        if(number > 2){
            int a_1 = 1;
            int a_2 = 2;
            int a_3;
            int i;
            for(i = 3; i <= number; i++)
            {
                a_3 = a_2 + a_1;
                a_1 = a_2;
                a_2 = a_3;
            }
            return a_3;
        }else if (number == 2)
            return 2;
        else if (number == 1)
            return 1;
        else
            return 0; 
    }

    /**
     * @brief   一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
     *          求该青蛙跳上一个n级的台阶总共有多少种跳法。
     * @param number 
     * @return int 
     */
    int jumpFloorII(int number){
        // 等比数列
        return (pow(2, number - 1));
    }
};

