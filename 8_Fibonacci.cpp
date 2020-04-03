
/**
 * @file 8_Fibonacci.cpp
 * @author your name (you@domain.com)
 * @brief   大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
            n<=39
 * @version 0.1
 * @date 2020-04-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <ctime>

class Solution {
public:
    // 运行时间长
    int FibonacciRecursive(int n) { 
        if(n == 0)
            return 0;
            
        if(n > 2)
            return(FibonacciRecursive(n-1) + FibonacciRecursive(n-2));
        else if (n == 2)
            return 1;
        else if (n == 1)
            return 1;
    }

    // 运行时间短
    int Fibonacci(int n) { 
        if(n == 0)
            return 0;

        if(n == 1)
            return 1;

        if(n > 2){
            int a_1 = 0;
            int a_2 = 1;
            int a_3 = 0;
            int i;
            for(i = 2; i <= n; i++){
                a_3 = a_1 + a_2;
                a_1 = a_2;
                a_2 = a_3;
            }
            return a_3;
        }
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "Fibonacci:\n";
    Solution demo;
    clock_t startTime, endTime;

    startTime = clock();
    std::cout << "39: " << demo.Fibonacci(39) << std::endl;
    std::cout << "40: " << demo.Fibonacci(40) << std::endl;
    std::cout << "3: " << demo.Fibonacci(3) << std::endl;
    std::cout << "4: " << demo.Fibonacci(4) << std::endl;
    endTime = clock();
    std::cout << "Fibonacci run time(ns) :" << endTime - startTime << std::endl;

    startTime = clock();
    std::cout << "39: " << demo.FibonacciRecursive(39) << std::endl;
    std::cout << "40: " << demo.FibonacciRecursive(40) << std::endl;
    std::cout << "3: " << demo.FibonacciRecursive(3) << std::endl;
    std::cout << "4: " << demo.FibonacciRecursive(4) << std::endl;
    endTime = clock();
    std::cout << "FibonacciRecursive run time(ns) :" << endTime - startTime << std::endl;
    return 0;
}

