/**
 * @brief   求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、
 *          switch、case等关键字及条件判断语句（A?B:C）。
 * 
 */
class Solution {
public:
    int Sum_Solution(int n) {
        int temp = n;
        temp && (temp += Sum_Solution(n - 1));
        return temp;
    }
};