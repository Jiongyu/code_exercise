/**
 * @file 51_InversePairs.cpp
 * @author your name (you@domain.com)
 * @brief   题目描述
            在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
            输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
            即输出P%1000000007

            输入描述:
            题目保证输入的数组中没有的相同的数字

            数据范围：
                对于%50的数据,size<=10^4
                对于%75的数据,size<=10^5
                对于%100的数据,size<=2*10^5
 * @version 0.1
 * @date 2020-07-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <numeric>
#include <iostream>
#include <memory>

using namespace std;

class Solution {
public:
    // 50% 通过， 运行时间过长
    int InversePairs_tooLong(vector<int> data) {
        if(data.empty()) return -1;
        int length = data.size();
        vector<int>dp(length, 0);
        for(int i = length - 1; i > 0; i--){
            for(int j = i - 1; j >= 0 ; j--){
                if(data[j] > data[i])
                    dp[i] += 1;
            }
        }
        return accumulate(dp.begin(), dp.end(), 0) % 1000000007;

    }
    
    int InversePairs(vector<int> data) {
        if(data.empty()) return -1;
        long long length = data.size();
        vector<int>copy(data);       
        long long count = InversePairsCore(data, copy, 0, length - 1);
        return count % 1000000007;
    }

private:
    // 归并排序算法
    long long InversePairsCore(vector<int> &data, vector<int>&copy, int start, int end){

        if(start == end){
            copy[start] = data[start];
            return 0;
        }

        int length = (end - start) / 2;
        long long left = InversePairsCore(copy, data, start, start + length);
        long long right = InversePairsCore(copy, data, start + length + 1, end);

        // 左半部末端
        int i = start + length;
        // 右半部末端
        int j = end;
        int indexCopy = end;
        long long count = 0;

        while (i >= start && j >= start + length + 1)
        {
            if(data[i] > data[j]){
                copy[indexCopy --] = data[i --];
                count += j - start - length;
            }else{
                copy[indexCopy --] = data[j --];
            }
        }

        for(; i >= start; --i){
            copy[indexCopy --] = data[i];
        }
        for(; j >= start + length + 1; --j){
            copy[indexCopy --] = data[j];
        }
        return count + left + right;
    }

};


int main(int argc, char const *argv[])
{
    int orginalData[] = {   364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,
                            601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,
                            486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,
                            882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,
                            697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,
                            3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,
                            811,267,575 };

    vector<int>data(orginalData, orginalData + sizeof(orginalData) / sizeof(orginalData[0]));

    Solution demo;
    cout << demo.InversePairs(data) << endl;      
    return 0;
}
