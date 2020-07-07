/**
 * @file 46_translateNum.cpp
 * @author your name (you@domain.com)
 * @brief   给定一个数字，我们按照如下规则把它翻译为字符串：
 *          0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，
 *          ……，25 翻译成 “z”。一个数字可能有多个翻译。
 *          请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 * @version 0.1
 * @date 2020-07-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
         if(s.empty()) 
            return -1;     
        int length = s.length();
        if(length < 2) 
            return 1;
        int dp[length + 1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= length; i++){
            if( ( s.substr(i-2, 2) < "26" ) && 
                ( s.substr(i-2, 2) >= "10" )  ){

                dp[i] = dp[i - 1] + dp[i - 2];
            }else{
                dp[i] = dp[i - 1];
            }
        }   
        return dp[length];
    }
};