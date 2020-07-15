/**
 * @file 66_maxProfit.cpp
 * @author your name (you@domain.com)
 * @brief   给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

            如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

            注意：你不能在买入股票前卖出股票。

 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return -1;
        int minIndex = prices[0];
        int maxProfits = 0;
        for(int i= 1; i < prices.size(); ++i){
            minIndex = min(minIndex,prices[i]);
            maxProfits = max(maxProfits, prices[i] -minIndex);
        }
        return maxProfits;       
    }
};