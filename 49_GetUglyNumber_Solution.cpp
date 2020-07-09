/**
 * @file 49_GetUglyNumber_Solution.cpp
 * @author your name (you@domain.com)
 * @brief   把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，
 *          但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小
 *          到大的顺序的第N个丑数。
 * @version 0.1
 * @date 2020-07-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 0) return -1;

        int *uglyNumberList = new int[index];

        int *pMulti2 = uglyNumberList;
        int *pMulti3 = uglyNumberList;
        int *pMulti5 = uglyNumberList;

        uglyNumberList[0] = 1;
        int uglyNumberListIndex = 1;

        int minNumber;
        while (uglyNumberListIndex < index)
        {
            minNumber = min(*pMulti2 * 2 , *pMulti3 * 3, *pMulti5 * 5);
            uglyNumberList[uglyNumberListIndex] = minNumber;

            while (*pMulti2 * 2 <= uglyNumberList[uglyNumberListIndex])
            {
                pMulti2 ++;
            }
            while (*pMulti3 * 3 <= uglyNumberList[uglyNumberListIndex])
            {
                pMulti3 ++;
            }
            while (*pMulti5 * 5 <= uglyNumberList[uglyNumberListIndex])
            {
                pMulti5 ++;
            }
            
            uglyNumberListIndex ++;
        }
        pMulti2 = NULL, pMulti3 = NULL, pMulti5 = NULL;
        int uglyNumber = uglyNumberList[index - 1];
        delete[] uglyNumberList; 
        return uglyNumber;
    }


private:
    int min(int a, int b, int c){
        int min = a > b ? b : a;
        min = min > c ? c : min;
        return min;
    }
};



int main(int argc, char const *argv[])
{
    int index = 3;
    Solution demo;
    cout << demo.GetUglyNumber_Solution(index) << endl;
    return 0;
}
