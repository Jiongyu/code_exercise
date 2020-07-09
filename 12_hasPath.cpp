/**
 * @file 12_hasPath.cpp
 * @author your name (you@domain.com)
 * @brief   请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 *          路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 *          如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
 *          例如矩阵[a,b,c,e;s,f,c,s;a,d,e,e]
 *          矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
 *          因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
 * @version 0.1
 * @date 2020-04-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //回溯法
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {   
        vector<char>flag(rows * cols, 0);
        bool condition = false;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                condition = (condition || isPath(matrix, flag, str, i, j, rows, cols));
            }
        }
        return condition;
    }

private:
    bool isPath(char *matrix, vector<char>flag, char *str, int x, int y, int rows, int cols)
    {
        // 边界
        if( x < 0 || x >= rows || y < 0 || y >= cols)
            return false;
        
        if(matrix[x * cols + y] == *str && flag[x * cols + y] == 0)
        {
            flag[x * cols + y] = 1;

            if(*(str + 1) == 0)
                return true;
            
            // 迭代坐标位置左上右下四个位置
            bool condition =    isPath(matrix, flag, (str + 1), x, y - 1, rows, cols) ||
                                isPath(matrix, flag, (str + 1), x - 1, y, rows, cols) ||
                                isPath(matrix, flag, (str + 1), x, y + 1, rows, cols) ||
                                isPath(matrix, flag, (str + 1), x + 1, y, rows, cols) ;
            if( condition == false )
                flag[x * cols + y] = 0;
            return condition;
        }else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    char matrix[] = "abcesfcsadee";
    int rows = 3, cols = 4;
    char str1[] = "bcced";
    char str2[] = "abcb";

    bool condition = false;
    Solution demo;
    condition = demo.hasPath(matrix, rows, cols, str1);
    if(condition){
        std::cout << "find " << str1 << " path\n";
    }
    condition = demo.hasPath(matrix, rows, cols, str2);
    if(condition){
        std::cout << "find " << str2 << " path\n";
    }
    return 0;
}
