/**
 * @file 47_getMost.cpp
 * @author your name (you@domain.com)
 * @brief   小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，
 *          游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼
 *          物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格
 *          子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。给定一个6*6的矩阵board，
 *          其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值
 *          大于100小于1000。
 * @version 0.1
 * @date 2020-07-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
using namespace std;

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        if(board.empty()) return -1;
        int row = board.size();
        int colum = board[0].size();

        int dp[row][colum];
        if(board[0][0] < 1000 && board[0][0] > 100)
            dp[0][0] = board[0][0];
        else 
            dp[0][0] = 0;

        for(int i = 1;  i < row; i++){
            if(board[i][0] < 1000 && board[i][0] > 100)
                dp[i][0] =  dp[i - 1][0] + board[i][0];
            else
                dp[i][0] = 0; 
        }
        for(int j = 1; j < colum; j++){
            if(board[0][j] < 1000 && board[0][j] > 100)
                dp[0][j] = dp[0][j - 1] + board[0][j];
            else 
                dp[0][j] = 0;
        }

        int temp;
        for(int i = 1; i < row; i++){
            for(int j = 1; j < colum; j++){
                if(board[i][j] > 100 && board[i][j] < 1000)
                    temp =  board[i][j];
                else
                    temp = 0;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + temp;
            }
        }
        return dp[row - 1][colum - 1];
    }
};