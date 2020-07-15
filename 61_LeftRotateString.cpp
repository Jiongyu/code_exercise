/**
 * @file 61_LeftRotateString.cpp
 * @author your name (you@domain.com)
 * @brief   汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
 *          就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你
 *          把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输
 *          出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 * @version 0.1
 * @date 2020-07-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <algorithm>    // std::reverse
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.begin() + str.size() - n, str.end());
        return str;
    }
}