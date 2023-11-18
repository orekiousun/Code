// #include<bits\stdc++.h>   // 万能头
#include<iostream>
using namespace std;
#include<string>
//单行注释
/*多行注释*/
/*
    C++初识
    1.变量：方便管理内存空间，给一段内存空间取名，方便操纵这段内存
    创建语法：
        数据类型 变量名称 = 变量初始值;
        int a = 10;
    2.常量：用于记录程序中不可以更改的数据
        1）#define宏常量：
            #define 常量名 常量值
                #define day 7   // 表示一个全局常量，后面不可以跟;
        2）const修饰的变量
            const 数据类型 常量名 = 常量值
                const int a = 10;   // 用于修饰一个变量，表示其不可修改
    3.关键字：C++中预先保留的单词（标识符），即在定义变量或常量时不能用关键字
    4.标识符命名规则
        ·标识符不能是关键字
        ·标识符只能由字母数字下划线组成
        ·第一个字符必须为字母或下划线
        ·标识符中字母区分大小写
    5.命名法：通常类使用大驼峰命名法如：ThisClass
        通常变量，函数使用小驼峰命名法：thisFunc
*/
#define day 7
int main()
{
    // 输出测试
    cout << "Hello World test" << endl;
    cout << "Hello World" << endl;
    // 变量测试
    int a = 10;
    const int b = 100;
    cout << "the value of a is:" << a << endl;
    // 常量测试
    /*
        day = 14;
        // 会报错，不能修改
    */
    cout << "the const value of day is:" << day << endl;
    cout << "the const value of day is:" << b << endl;
    system("pause");
    return 0;
}