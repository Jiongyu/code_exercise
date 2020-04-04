/**
 * @file 13_movingCount.cpp
 * @author your name (you@domain.com)
 * @brief   地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
 *          每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐
 *          标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能
 *          够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方
 *          格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个
 *          格子？
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
    int movingCount(int threshold, int rows, int cols)
    {
        int num = 0;
        bool *flag = new bool[rows * cols];
        for(int i = 0; i < rows * cols; i++)
            flag[i] = false;

        num = getNum(threshold, flag, 0, 0, rows ,cols);
        return num;
    }

private:
    int getNum(int threshold, bool *flag, int x, int y, int rows, int cols)
    {
        // 边界
        if( x < 0 || x >= rows || y < 0 || y >= cols)
            return 0;

        if( ((x % 10) + (x / 10) + (y % 10) + (y / 10) <= threshold) && (flag[x * cols + y] == false))
        {
            flag[x * cols + y] = true;
            // 上下左右
            int num = 1 + getNum(threshold, flag, x, y - 1, rows, cols)
                        + getNum(threshold, flag, x - 1, y, rows, cols)
                        + getNum(threshold, flag, x, y + 1, rows, cols)
                        + getNum(threshold, flag, x + 1, y, rows, cols);
            return num;
        }else
            return 0;
    }
};

int main(int argc, char const *argv[])
{
    int threshold = 18;
    int rows = 50, cols = 50; 
    Solution demo;
    int num;
    num = demo.movingCount(threshold, rows, cols);
    std::cout << "threshold " << threshold << ": " << num << std::endl;
    return 0;
}
