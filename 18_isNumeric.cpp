/**
 * @file 18_isNumeric.cpp
 * @author your name (you@domain.com)
 * @brief   请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 *          例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
 *          但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 * @version 0.1
 * @date 2020-04-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <string>

class Solution {
public:
    bool isNumeric(const char* string)
    {
        if(string == NULL)  return false;

        if(*string == '+' || *string == '-')
            string ++;
        if(*string == '\0') return false;
        int dot = 0 , num = 0 , nume = 0;
        while (*string != '\0')
        {
            if(*string >= '0' && *string <= '9'){
                string ++;
                num = 1;
            }else if (*string == '.'){
                if(dot > 0 || nume > 0) return false;
                string ++;
                dot = 1;
            }else if(*string == 'E' || *string == 'e'){
                if(num == 0 || nume > 0)return false;
                string ++;
                nume ++;
                if(*string == '+' || *string == '-')
                    string ++;
                if(*string == '\0') return false;

            }else   return false;
        }
        return true;
    }

};

int main(int argc, char const *argv[])
{
    Solution demo;
    std::string data[20] = {"+100","5e2","-123","3.1416","-1E-16","12e","1a3.14","1.2.3","+-5","12e+4.3"};
    int i = 0;
    while (data[i] != "")
    {
        printf("%-8s is number : ",data[i].c_str());
        printf("%5s\n", demo.isNumeric(data[i].c_str()) ? "true" : "false");
        i ++;        
    }
    return 0;
}
