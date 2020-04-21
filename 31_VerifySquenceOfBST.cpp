/**
 * @file 31_VerifySquenceOfBST.cpp
 * @author your name (you@domain.com)
 * @brief   输入一个整数数组，判断该数组是不是某二叉搜索树的后
 *          序遍历的结果。如果是则输出Yes,否则输出No。假设输入
 *          的数组的任意两个数字都互不相同。
 * @version 0.1
 * @date 2020-04-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    /** 递归 **/
    bool VerifySquenceOfBST(vector<int> sequence) {

        if(sequence.empty()) return false;
        int index;
        int begin = 0;
        int end = sequence.size() - 1;
        vector<int>left_sq,right_sq;

        // 左子节点小于根节点
        for(index = begin; index < end; index ++){
            if(sequence[index] < sequence[end])
                left_sq.push_back(sequence[index]);
            else
                break;
        }

        // 右子节点大于根节点
        for (; index < end; index ++ ){
            if(sequence[index] > sequence[end])
                right_sq.push_back(sequence[index]);
            else
                return false;
        }
        
        // 判断左子树是否为后序遍历
        bool left = true;
        if(!left_sq.empty())   left = VerifySquenceOfBST(left_sq);
        
        // 判断右子树是否为后序遍历
        bool right = true;
        if(!right_sq.empty()) right = VerifySquenceOfBST(right_sq);
        
        return left && right;
    }

    // /** 迭代 **/
    // bool VerifySquenceOfBST(vector<int> sequence) {
    //     if(sequence.empty()) return false;
    //     int index = 0, length = sequence.size();
    //     while (-- length)
    //     {
    //         while (sequence[index++] < sequence[length]);
    //         while (sequence[index++] > sequence[length]);
    //         if(index < length) return false;
    //         index = 0; 
    //     }
    //     return true;
    // }

};