/**
 * @file 9_rectCover.cpp
 * @author your name (you@domain.com)
 * @brief   我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 *          请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * @version 0.1
 * @date 2020-04-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>

class Solution {
public:
    int rectCover(int number) {       
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
};

int main(int argc, char const *argv[])
{
    Solution demo;
    std::cout << "10 number rect : " << demo.rectCover(10) << std::endl;    
    return 0;
}
