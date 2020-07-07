/**
 * @file 45_numDecodings.cpp
 * @author your name (you@domain.com)
 * @brief   一条包含字母 A-Z 的消息通过以下方式进行了编码：
            'A' -> 1
            'B' -> 2
            ...
            'Z' -> 26
            给定一个只包含数字的非空字符串，请计算解码方法的总数。

            示例 1:

            输入: "12"
            输出: 2
            解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
            示例 2:

            输入: "226"
            输出: 3
            解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

 * @version 0.1
 * @date 2020-07-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

// -std=c++11
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int pre = 1, curr = 1; // dp[0] = dp[1] = 1;
        int length = s.length();
        int temp;
        for(int i = 1; i < length; i++){
            temp = curr;
            if(s[i] == '0'){
                if(s[i - 1] == '1' || s[i- 1] == '2' ){
                    curr = pre;
                }else{
                    return 0;
                }
            }else if ( s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '1'  && s[i] <= '6' )
            {
                curr = pre + curr;  
            }
            pre = temp;
        }
        return curr;
    }
};



// class Solution {
// public:
//     int numDecodings(string s) {
//         if(s.empty()) 
//             return -1;     
//         int length = s.length();
//         if(stoi(s) == 0) return 0;
//         if(length < 2) 
//             return 1;
//         int dp[length + 1];
//         dp[0] = 1;
//         dp[1] = 1;
//         for(int i = 2; i <= length; i++){
//             if( ( s.substr(i-2, 2) <= "26" ) && 
//                 ( s.substr(i-2, 2) > "10" )  ){

//                 dp[i] = dp[i - 1] + dp[i - 2];
//             }else{
//                 dp[i] = dp[i - 1];
//             }
//         }   
//         return dp[length];
//     }
// };