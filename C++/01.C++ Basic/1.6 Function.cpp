#include<iostream>
using namespace std;
#include<string>

/*
    函数
    1.概述：将一段经常使用的代码封装起来，减少重复代码
    2.函数定义：
        1）返回值类型（不需要返回值时声明可以写void，可以不写或者只写一个return返回即可）
        2）函数名
        3）参数列表
        4）函数体语句
        5）return表达式
        返回值类型 函数名(形参列表)   // 传入的参数称为形式参数
        {
            函数体语句
            return表达式
        }
    3.函数调用
        函数名(实参列表)   // 调用函数时，实参的值会传递给形参
    4.值传递：函数调用时实参将数值传入给形参，值传递时，如果形参发生了改变，不会影响实参
    5.函数声明：可以提前告诉编译器函数的存在，可以利用函数的声明，再在后面定义函数的功能
        int max(int a, int b);
        声明可以写多次，但是定义只能写一次（虽然没啥用就是了）
    6.函数的分文件编写
        1）创建后缀名.h的文件   // 注意.h头文件中应该包含各种包
        2）创建后缀名.cpp的源文件   // .cpp源文件中只用include头文件并且书写函数定义即可
        3）在.h文件中写函数的声明
        4）在.cpp源文件中写函数的定义
*/
int add(int num1, int num2);   // 函数声明
int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum; 
}

int main()
{
    int num1 = 1, num2 = 2;   
    cout << add(num1, num2) << endl;   // num1和num2称为传入函数的实际参数
    system("pause");
    return 0;
}