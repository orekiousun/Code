#include<iostream>
using namespace std;
#include<string>
/*
    函数对象
    1.概念：-- 通常叫仿函数，比一般的函数更灵活
        重载 函数调用操作符 的类，其对象常称为 函数对象
        **函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**
    本质：函数对象(仿函数)是一个**类**，不是一个函数
    2.函数对象使用
    特点：        
        函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
        函数对象超出普通函数的概念，函数对象可以有自己的状态
        函数对象可以作为参数传递

*/

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }
    void operator()(string str)   // 重载()成员名+()即可调用该重载
    {
        cout << str << endl;
        this->count++;   // 可以记录该函数调用的次数
    }
    int count;   // 自己的状态
};

void doPrint(MyPrint &m, string str)
{
    m(str);
}

void test01()
{
    MyAdd myAdd;
    // 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
        
    cout << myAdd(10, 10) << endl;

    // 函数对象超出普通函数的概念，函数对象可以有自己的状态
    MyPrint myPrint;
    myPrint("Hello World"); 
    cout << "调用的次数：" << myPrint.count << endl;

    // 函数对象可以作为参数传递
    doPrint(myPrint, "Hello C++");
}

int main()
{
     cout << "------------ test01 ------------" << endl;
    test01();
    system("pause");
    return 0;
}