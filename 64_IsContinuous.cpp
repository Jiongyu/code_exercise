/**
 * @file 64_IsContinuous.cpp
 * @author your name (you@domain.com)
 * @brief   LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,
 *          2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自
 *          己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿
 *          ！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....L
 *          L不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11
 *          ,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2
 *          和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模
 *          拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，
 *          否则就输出false。为了方便起见,你可以认为大小王是0
 * @version 0.1
 * @date 2020-07-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty()) return false;
        sort(numbers.begin(),numbers.end());
        int length = numbers.size();
        
        int ghost = 0;
        for(int i =0; i< length - 1; i++){
            if(numbers[i] != 0) break;
            else ++ghost;
        }

        int temp;
        for(int i = ghost; i < length - 1; i++){
            temp = numbers[i + 1] - numbers[i];
            if(temp == 0) return false;
            ghost -= (temp - 1);
            if(ghost < 0) return false;
        }
        return true;
    }
};