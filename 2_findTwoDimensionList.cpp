/**在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
**/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        if(rows == 0)
            return false;
        
        int cols = array.begin()->size();
        if(cols == 0)
            return false;

        //左下
        int row = rows - 1;
        int col = 0;
        while (row >= 0 && col < cols)
        {
            if(array[row][col] < target){
                col ++;
            }else if (array[row][col] > target)
            {
                row --;
            }else
            {
                return true;
            }           
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int> > temp_1;
    vector<int>temp_2;

    int data = 0;
    for (int i = 1; i <= 25; i++)
    {   
        if(i % 5 != 0){
            temp_2.push_back(i);
        }else
        {            
            temp_1.push_back(temp_2);
            temp_2.clear();
        }
    }

    Solution demo;
    bool finded;
    finded = demo.Find(30, temp_1);
    if(finded) std::cout<<"finded 30.\n";
    finded = demo.Find(22, temp_1);
    if(finded) std::cout<<"finded 20.\n";

    return 0;
}
