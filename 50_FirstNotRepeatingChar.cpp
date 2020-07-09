/**
 * @file 50_FirstNotRepeatingChar.cpp
 * @author your name (you@domain.com)
 * @brief   在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只
 *          出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 *          从0开始计数）
 * @version 0.1
 * @date 2020-07-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        int ascll_length = 128;
        vector<int> ascll(ascll_length,0);
        int length = str.length();
        int number = 0;
        for(int i = 0; i < length; i++){
            number = stoi( to_string(str.at(i) - '\0') );
            ascll[number] += 1;
            cout << str.at(i) << " " << number << endl;
        }
        for(int i = 0; i < length; i++){
            if( ascll[ stoi( to_string(str.at(i) - '\0')) ] ==  1){
                return i;
            }
        }    
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string data("NXWtnzyoHoBhUJaPauJaAitLWNMlkKwDYbbigdMMaYfkVPhGZcrEwp");
    Solution demo;
    cout << endl << demo.FirstNotRepeatingChar(data)<< endl;
    return 0;
}
