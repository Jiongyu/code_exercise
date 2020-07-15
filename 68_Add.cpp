/**
 * @brief 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 */

class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum,temp;
        do
        {
            sum  = num1 ^ num2;
            temp = (num1 & num2) << 1;
            num1 = sum;
            num2 = temp;
        } while (num2 != 0);
        return sum;
        
    }
};