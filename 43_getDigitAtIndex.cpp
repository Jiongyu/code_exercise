/**
 * @brief 数字以 0123456789101112131415... 的格式序列化到一个字符串中，求这个字符串的第 index 位。 
 */

#include <iostream>

class Solution
{

public:

    int digitAtIndex(int n) {
         long long i = 1, s = 9, base = 1;//i表示是几位数，s表示位数共有多少个，base表示位数的起始值。
         while(n > i * s) {   // 9, 90, 900, 9000, 90000, i * s表示位数总共占多少位。
             n -= i * s;         // 1000 - 9 - 90 * 2 - 900 * 3 ,当i= 3 时不符合条件，说明是在三位数里面。
             i ++;                
             s *= 10;
             base *= 10;
         }
         int number = base + (n + i - 1) / i - 1; //求位数的第几个数， 1000 - 9 - 180 = n , n / 3 + base - 1（考虑0故减1）, 向上取整 n + i - 1。
         int r = n % i ? n % i : i;              // 除不尽就是第几位，除尽力了就是最后一位。
         for (int j = 0; j < i - r; j ++) number /= 10; //求数的第i - r位，取出第i - r位。

         return number % 10;
    }

    /**
     * @brief 获取数字所在位置
     * 
     * @param index 
     * @return int 
     */
    int getDigitAtIndex(int index){
        if(index < 0) return -1;
        unsigned int digit = 1;
        unsigned long int start = 1;
        unsigned long int count = 9;
        while (index > count)
        {
            index -= count;
            digit += 1;
            start *= 10;
            count = digit * start * 9;
        }
        // 确定所求数位所在的数字
        unsigned long int number = start +  (index - 1) / digit;
        //确定所求数位在 num 的哪一数位
        int number_position  = ( index - 1 ) % digit;
        
        count = 9 * (digit - 1) * (start - 1) + number * digit + number_position;
        return count;
    }


};


int main(int argc, char const *argv[])
{
    Solution demo;
    std::cout << demo.getDigitAtIndex(150000) <<std::endl;
    std::cout << demo.digitAtIndex(150000) <<std::endl;
    return 0;
}