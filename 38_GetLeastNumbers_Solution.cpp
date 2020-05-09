/**
 * @file 38_GetLeastNumbers_Solution.cpp
 * @author your name (you@domain.com)
 * @brief   输入n个整数，找出其中最小的K个数。例如输入4,5,1,
 *          6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
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
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(input.empty() || k < 1)  return result;
        sort(input.begin(), input.end());
        int length = input.size();
        if (k > length) return result;
        for(int i = 0 ; i <= k - 1 ; i++)
            result.push_back(input[i]);
        return result;
    }
};