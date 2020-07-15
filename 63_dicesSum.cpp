/**
 * @file 63_dicesSum.cpp
 * @author your name (you@domain.com)
 * @brief   扔 n 个骰子，向上面的数字之和为 S。给定 n，请列出所有可能的 S 值及其相应的概率。

            样例
            样例 1：

            输入：n = 1
            输出：[[1, 0.17], [2, 0.17], [3, 0.17], [4, 0.17], [5, 0.17], [6, 0.17]]
            解释：掷一次骰子，向上的数字和可能为1,2,3,4,5,6，出现的概率均为 0.17。
            样例 2：

            输入：n = 2
            输出：[[2,0.03],[3,0.06],[4,0.08],[5,0.11],[6,0.14],[7,0.17],[8,0.14],[9,0.11],
                [10,0.08],[11,0.06],[12,0.03]]
            解释：掷两次骰子，向上的数字和可能在[2,12]，出现的概率是不同的。
            注意事项
            你不需要关心结果的准确性，我们会帮你输出结果。
 * @version 0.1
 * @date 2020-07-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<pair<int, double>> results;
        int faces = 6;
        vector<vector<double>> f(n + 1, vector<double>(faces * n + 1));
        // 初始化一颗色子各点概率
        for (int i = 1; i <= faces; ++i) f[1][i] = 1.0 / faces;
        
        // 第ｉ个色子
        for (int i = 2; i <= n; ++i)
            // 第i个色子第j点数
            for (int j = i; j <= faces * i; ++j) {
                // 单个色子点数
                for (int k = 1; k <= faces; ++k)
                    if (j > k){
                        // f(n) = f(n - 6) + f(n - 5) + f(n - 4) + f(n - 3) + f(n - 2) + f(n - 1)
                        f[i][j] += f[i - 1][j - k];
                    }
                f[i][j] /= (double)faces;
            }

        for (int i = n; i <= faces * n; ++i)
            results.push_back(make_pair(i, f[n][i]));

        return results;
    }
};