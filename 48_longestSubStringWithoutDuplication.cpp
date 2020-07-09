/**
 * @file 48_longestSubStringWithoutDuplication.cpp
 * @author your name (you@domain.com)
 * @brief   输入一个字符串（只包含 a~z 的字符），求其最长不含重复字符的子字符串的长度。
 *          例如对于 arabcacfr，最长不含重复字符的子字符串为 acfr，长度为 4。
 * @version 0.1
 * @date 2020-07-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubStringWithoutDuplication(string s){
        if(s.empty()) return -1;
        int length = s.length();
        int dp[length + 1];
        dp[0] = 1;
        int label = 0;
        string temp;
        for(int i = 1; i < length; i++){

            temp = s.substr(label,i);
            // cout << temp << endl;
            for(int j = label; j < i; j ++){
                // cout << s[j] << " " << s[i] << endl;
                if(s[j] == s[i]){
                    label = i;
                    break;
                }
            }

            // cout << label << endl;
            if(label != i)
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = 1; 
            // cout << dp[i] << endl << endl;
        }
        return *max_element(dp, dp+length);
    }
};

int main(int argc, char const *argv[])
{
    // string data = "arabcacfr";
    string data = "arabcacfrhksa";

    Solution demo;
    cout << demo.longestSubStringWithoutDuplication(data)<< endl;
    return 0;
}

