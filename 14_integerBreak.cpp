/**
 * @file 14_integerBreak.cpp
 * @author your name (you@domain.com)
 * @brief   给定一个正整数 n，将其拆分为至少两个正整数的和，
 *          并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * @version 0.1
 * @date 2020-04-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>
#include <math.h>

class Solution {
public:
    // 动态规划
    int integerBreak(int n) {
        std::vector<int> dp (n+1, 1);
        for (int i = 3 ; i <= n ; i++ ){
            for(int j = 1; j < i ; j++ ){
                dp[i] = fmax(dp[i] , fmax(j * (i - j) , j * dp[i - j]));
            }
        }
        return dp[n];
    }

    // 贪心
    int integerBreak_(int n){
        
        if( n > 3){
            int integer = n / 3;
            int remainder = n % 3;

            if(remainder == 0)
                return pow(3 , integer);
            if( remainder == 1)
                return pow(3 , integer - 1) * 4;
            if(remainder == 2)
                return pow(3 , integer) * 2;  
        }
        else if(n == 2)  return 1;
        else if(n == 3)  return 2;
        else return 0;
    }
};

int main(int argc, char const *argv[])
{
    int number = 20;
    Solution demo;
    std::cout << "正整数：20\n";
    std::cout << "动态规划求解：\n";
    std::cout << demo.integerBreak(number) << std::endl;    
    std::cout << "贪心求解：\n";
    std::cout << demo.integerBreak_(number) << std::endl;    

    return 0;
}
