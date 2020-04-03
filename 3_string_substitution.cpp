/**
 * @file string_substitution.cpp
 * @author your name (you@domain.com)
 * @brief   请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 *          例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 * @version 0.1
 * @date 2020-04-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL)
            return;
        int countOfBlack = 0;
        int originalLength = 0;
        for(int i = 0; str[i] != '\0'; i++){
            originalLength ++;
            if(str[i] == ' '){
                ++ countOfBlack;
            }
        }
        int len = originalLength + 2 * countOfBlack;
        // cout << len <<endl;
        // cout << originalLength <<endl;

        char *pStr1 = str + originalLength;
        char *pStr2 = str + len;
        // cout << (void *)pStr1 <<endl;
        // cout << (void *)pStr2 <<endl;

        while (pStr1 < pStr2)
        {
            if(*pStr1 == ' '){
                *pStr2-- ='0';
                *pStr2-- ='2';
                *pStr2-- ='%';
            }else
            {
                *pStr2-- = *pStr1;
            }
            --pStr1;
        }

        // pStr2 = str + len - 1;
        // cout << pStr2 <<endl;

    }
};

int main(int argc, char const *argv[])
{
    char str[] = "hello world .!";
    Solution demo;
    demo.replaceSpace(str, sizeof(str));
    cout << str << endl;
    return 0;
}
