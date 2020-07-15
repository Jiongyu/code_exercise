/**
 * @file 62_maxInWindows.cpp
 * @author your name (you@domain.com)
 * @brief   给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 *          例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么
 *          一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对
 *          数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 *           {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}，
 *           {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 *           {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * 
 * @version 0.1
 * @date 2020-07-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> data;
        if(num.empty() || size <= 0) return data;
        int index = 0;
        int length = num.size();
        while ((index + size) <= length)
        {
            data.push_back(*(max_element(num.begin() + index, num.begin() + index + size)));
            index += 1;
        }
        return data;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution demo;

    return 0;
}
