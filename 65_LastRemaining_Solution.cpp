/**
 * @file 65_LastRemaining_Solution.cpp
 * @author your name (you@domain.com)
 * @brief   每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
 *          HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,
 *          让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
 *          每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且
 *          不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到
 *          剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有
 *          限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从
 *          0到n-1)
 *          如果没有小朋友，请返回-1
 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    //环形链表,耗时太久，　十几毫秒
    int LastRemaining_Solution_(int n, int m)
    {
        if(n < 1) return -1;
        list<int>childenNumber;
        childenNumber.clear();
        for(int i = 0; i < n; ++i){
            childenNumber.push_back(i);
        }

        list<int>::iterator it = childenNumber.begin();
        while (childenNumber.size() > 1)
        {
            for(int i = 0 ; i < m - 1; i++){
                ++ it;
                if(it == childenNumber.end()) it = childenNumber.begin();
            }
            it = childenNumber.erase(it);
            if(it == childenNumber.end()) it = childenNumber.begin();
        }
        return childenNumber.front();
    }

    int LastRemaining_Solution(int n, int m)
    {
        if(n==0) return -1;
        int s=0;
        for(int i=2;i<=n;i++){
            s=(s+m)%i;
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution demo;
    int childenNumer = 5;
    int childenChoice = 3;
    cout << demo.LastRemaining_Solution(childenNumer, childenChoice) << endl;
    return 0;
}
