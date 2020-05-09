/**
 * @file 37_MoreThanHalfNum_Solution.cpp
 * @author your name (you@domain.com)
 * @brief   数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 *          例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在
 *          数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则
 *          输出0。
 * @version 0.1
 * @date 2020-05-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        sort(numbers.begin(), numbers.end());
        int middle = numbers[numbers.size() / 2];
        int count = 0;
        int length = numbers.size();
        for(int i = 0; i < length; i++){
            if(numbers[i] == middle) count ++;
        }
        return (count > length / 2) ? middle : 0;
    }   
};