/**
 * @brief 从 1 到 n 整数中 1 出现的次数 
 * 
 */
class Solution
{
private:
    /* data */
public:
    int NumberOf1Between1AndN_Solution(int n){
        if(n < 1) return 0;
        int num = 0; 
        int temp;
        for(int i = 1; i <= n; i++){
            temp = i;
            while (temp != 0)
            {
                if(temp % 10 == 1){
                    num ++;
                }
                temp = temp / 10;
            }
        }
        return num; 
    }

};


