#include<iostream>
#include<string.h>
using namespace std;

/*
    运算
    1.算术运算符：用于处理四则运算
        运算符   术语      示例         结果
        +        正号      +3           3
        -        负号      -3           3
        +        加        10+5         15
        -        减        10-5         5
        *        乘        10*5         50
        /        除        10/5         2     两个整型数相除，除不尽会直接取整，若是两个浮点类型数相除，则会保留小数项，除数不能为0
        %        取模      10%3         1     取模运算时除数也不能为0，两个小数是不可以做取模运算的
        ++       前置递增  a=2;b=++a;   a=3;b=3;   a先++再计算表达式，相当于a=a+1;b=a;
        ++       后置递增  a=2;b=a++;   a=3;b=2;   a先计算表达式再++，相当于b=a;a=a+1;
        --       前置递增  a=2;b=--a;   a=2;b=1;
        --       后置递减  a=2;b=a--;   a=2;b=2;   一般不建议这么写，还是一步一步写出来比较清晰
    2.赋值运算符
        运算符   术语       示例        结果
        =        赋值       a=2;b=3;    a=2;b=3;
        +=       加等于     a=0;a+=2;   a=2;   表示a=a+2;
        -=       减等于     a=5;a-=3;   a=2;
        *=       乘等于     a=2;a*=2;   a=4;
        /=       除等于     a=4;a/=2;   a=2;
        %=       模等于     a=3;a%=2;   a=1;   建议还是使用a=a+2这种形式，更清晰
    3.比较运算符
        运算符   术语       示例        结果
        ==       相等于     4==3        0   表示比较需要用双等号
        !=       不等于     4!=3        1
        <        小于       4<3         0
        >        大于       4>3         1
        <=       小于等于   4<=3        0
        >=       大于等于   4>=3         1   
    4.逻辑运算符
        运算符   术语       示例        结果
        !        非         !a         a的值取反
        &&       与         a&&b       a,b均为真才为真   // 表示且
        ||       或         a||b       a,b均为假才为假   // 表示或
*/
int main()
{

    system("pause");
    return 0;
}