/**
 * @file 39_The_median.cpp
 * @author your name (you@domain.com)
 * @brief   如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就
 *          是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位
 *          数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据
 *          流，使用GetMedian()方法获取当前读取数据的中位数。
 * @version 0.1
 * @date 2020-07-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void Insert(int num)
    {
        data.push_back(num);
    }

    double GetMedian()
    { 
        if(data.empty()) return 0;
        // 改成堆排序?
        sort(data.begin(), data.end());
        int length = data.size();
        if(length % 2 == 0){
            return  (data[length / 2] + data[length / 2 - 1]) / 2.0;
        }else{
            return data[length / 2];
        }
    }
    
private:
    vector<int>data;

};