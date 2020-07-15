/**
 * @file 69_multiply.cpp
 * @author your name (you@domain.com)
 * @brief   给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
 *          其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
 *          不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，
 *          B[n-1] = A[0] * A[1] * ... * A[n-2];）
 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> data(A.size(), 0);
        if(A.empty()) return data;
        data[0] = 1;
        for(int i = 1; i <A.size(); ++i){
            data[i] = data[i - 1] * A[i - 1];
        }
        int temp = 1;
        for(int j = A.size() - 2; j >=0; --j){
            temp *= A[j + 1];
            data[j] *= temp;
        }
        return data;
    }
};