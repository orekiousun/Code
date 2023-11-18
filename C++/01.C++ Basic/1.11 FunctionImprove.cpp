#include <iostream>
using namespace std;

/*
    函数高级
    1.函数默认参数：在C++中，函数形参列表中的形参是可以有默认值的
        返回值类型 函数名 (参数 = 默认值){}
        如果值传进去，就会用传进去的值，如果值没有传，就用默认值
    注意事项：
        1）如果某个位置有了默认参数，那么从这个位置往后，从左往右都必须有默认值
        2）如果函数声明有了默认参数，则函数实现就不能有默认参数，即声明和实现只能有一个有默认参数
    2.函数占位参数：C++中函数形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
        返回值类型 函数名 (数据类型){}   // 只填一个数据类型即可占位
        占位参数还可以有默认参数 void func4(int a, int = 10)，有默认参数时，就可以不传入当前占位参数
    目前阶段暂时用不到
    3.函数重载：函数名可以相同，提高复用性
    函数重载的满足条件：
        ·同一作用域下
        ·函数名相同
        ·函数参数 类型不同 或者 个数不同 或者 顺序不同
        利用参数的不同产生调用时的区别，从而找到对应的函数
    注意：函数的返回值不可以作为函数重载的条件
    4.函数重载注意事项
        将引用作为形参传参时的注意事项
        当函数重载时碰到默认参数时：
            void func8(int a, int b = 10)
            void func8(int a)
            func8(10)不知道调用哪个参数
*/

int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

/*
    int func2(int a, int b = 20, int c)
    {
        return a + b + c;
    }   // 程序报错，如果某个位置有了默认参数，那么从这个位置往后，从左往右都必须有默认值
*/

// int func3(int a = 10, int b = 10);
/*
    int func3(int a = 10, int b)
    {
        return a + b;
    }   // 程序报错，如果函数声明有了默认参数，则函数实现就不能有默认参数
*/

// 占位函数
void func4(int a, int)   // int为占位用
{
    cout << "this is func4" << endl;
}

void func5(int a, int = 10)   // int为占位用
{
    cout << "this is func5" << endl;
}


// 函数重载
void func6()
{
    cout << "this is func6()" << endl;
}
void func6(int a)
{
    cout << "this is func6(int a)" << endl;
}   // 参数个数不同
void func6(double a)
{ 
    cout << "this is func6(double a)" << endl;
}   // 参数顺序不同
void func6(int a,double b)
{
    cout << "this is func6(int a, double b)" << endl;
} 
void func6(double a,int b)
{
    cout << "this is func6(double a, int b)" << endl;
}   // 参数顺序不同
void func7(int& a)
{
    cout << "this is func7(int& a)" << endl;
}
void func7(const int& a)
{
    cout << "this is func7(const int& a)" << endl;
}   // 参数类型不同


// 函数重载碰到默认参数
void func8(int a, int b = 10)
{
    cout << "func8(int a, int b)" << endl;
}
void func8(int a)
{
    cout << "func8(int a)" << endl;
}


int main() {
    cout << func(10) << endl;
    cout << func(10, 30) << endl;
    func4(10, 10);
    // func4(10);   // 程序报错，函数中用int占了位需要传入一个额外的参数func4(10, 10)
    func5(10);   // 当占位参数有默认值时，就可以不用传入值
    // 函数重载
    func6();
    func6(10);   // 函数重载成功
    func6(3.14);   // 函数重载成功
    func6(10, 3.14);   // 函数重载成功
    func6(3.14, 6);   // 函数重载成功
    // 函数重载注意事项
    int a = 10;
    const int b = 20;
    func7(a);   // 调用无const
    func7(b);   // 调用const
    func7(10);   // 调用const，直接写一个常量也可以进行传参，相当于 const int& a = 10; int& a = 10;不合法
    // func8(10);   // 程序报错，由于 两个func8均可以调用，编译器无法找到相关函数，出现二义性
    system("pause");
    return 0;
}