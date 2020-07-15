/**
 * @file 58_FindNumbersWithSum.cpp
 * @author your name (you@domain.com)
 * @brief   题目描述
            输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
            如果有多对数字的和等于S，输出两个数的乘积最小的。

            输出描述:
            对应每个测试案例，输出两个数，小的先输出。
 * @version 0.1
 * @date 2020-07-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>data;
        if(array.empty()) return data;
        int indexStart = 0;
        int indexEnd = array.size() - 1;
        while (indexStart < indexEnd )
        {
            if(array[indexStart] + array[indexEnd] > sum){
                indexEnd -= 1;
            }else if (array[indexStart] + array[indexEnd] < sum)
            {
                indexStart += 1;
            }else{
                data.push_back(array[indexStart]);
                data.push_back(array[indexEnd]);
                return data;
            }
        }
        return data;   
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}