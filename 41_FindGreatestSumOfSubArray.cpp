/**
 * @file 41_FindGreatestSumOfSubArray.cpp
 * @author your name (you@domain.com)
 * @brief   在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
 *          但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
 *          例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
 *          给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
 * @version 0.1
 * @date 2020-07-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

/** 
 * dp[n]代表以当前元素为截止点的连续子序列的最大和，如果dp[n-1]>0，dp[n]=dp[n]+dp[n-1]，
 * 因为当前数字加上一个正数一定会变大；如果dp[n-1]<0，dp[n]不变，因为当前数字加上一个负数一
 * 定会变小。使用一个变量max记录最大的dp值返回即可。
 */
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int length = array.size();
        for(int i = 1; i < length; i++){
            array[i] += array[i - 1] > 0 ? array[i - 1]: 0;
        }
        vector<int>::iterator maxData = max_element(array.begin(), array.end());
        return *maxData;
    }
};