/**
 * @file 53_GetNumberOfK.cpp
 * @author your name (you@domain.com)
 * @brief   统计一个数字在排序数组中出现的次数。
 * @version 0.1
 * @date 2020-07-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int lower = getLower(data,k);
        int upper = getUpper(data,k);
         
        return upper - lower + 1;
    }
     
    //获取k第一次出现的下标
    int getLower(vector<int> data,int k){
        int start = 0,end = data.size()-1;
        int mid = (start + end)/2;
         
        while(start <= end){
            if(data[mid] < k){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
        return start;
    }
    //获取k最后一次出现的下标
    int getUpper(vector<int> data,int k){
         int start = 0,end = data.size()-1;
        int mid = (start + end)/2;
         
        while(start <= end){
            if(data[mid] <= k){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
         
        return end;
    }
};

int main(int argc, char const *argv[])
{
    int ori_data[] = {1,2,45,67,22,46,-1,2,2,2,2,2,2};
    vector<int> data(ori_data, ori_data + sizeof(ori_data)/ sizeof(ori_data[0]));
    sort(data.begin(), data.end());
    Solution demo;
    cout << demo.GetNumberOfK(data, 2) << endl;
    return 0;
}