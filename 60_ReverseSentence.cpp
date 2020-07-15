/**
 * @file 60_ReverseSentence.cpp
 * @author your name (you@domain.com)
 * @brief   Input:
            "I am a student."

            Output:
            "student. a am I"

 * @version 0.1
 * @date 2020-07-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    // 任何使用了额外空间的解法在面试时都会大打折扣，包括递归解法。
    string ReverseSentence(string str) {
        string data;
        if(str.empty()) return data;
        stack<string> tempStack;
        int length = str.size();
        int start = 0;
        string temp_str;
        int i = 0;
        while (i < length)
        {
            if(str.at(i) != ' '){
                temp_str += str[i];
            }else
            {
                tempStack.push(' ' + temp_str);
                temp_str.clear();
            }
            
            i += 1;
        }
        tempStack.push(temp_str);
        temp_str.clear();

        while ( !tempStack.empty() )
        {
            data += tempStack.top();
            tempStack.pop();
        }
        return data;  
    }

public:
    // 字符串旋转法
    string ReverseSentence_noAnotherSpace(string str) {
        if(str.empty()) return " ";
        int length = str.size();

        int i = 0, j = 0;
        while (j <= length)
        {
            if(j == length || str[j] == ' '){
                reverse(str, i, j - 1);
                i = j + 1;
            }
            j += 1;
        }
        reverse(str,0, length - 1);
        return str;
    }

private:
    void reverse(string &str, int i, int j){
        while (i < j)
        {
            swap(str, i++, j--);
        } 
    }

    void swap(string &str, int i, int j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
};

int main(int argc, char const *argv[])
{
    string data = "I am a student.";
    Solution demo;
    cout << demo.ReverseSentence(data) << endl;
    cout << demo.ReverseSentence_noAnotherSpace(data) << endl;

    return 0;
}
