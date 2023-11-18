#include<iostream>
using namespace std;

/*
    内存模式
    1.内存分区模型
    C++在执行时，将内存大方向分为4个区域
        ·代码区：存放函数的二进制代码，由操作系统进行管理
        ·全局区：存放全局变量和静态变量以及常量
        ·栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
        ·堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
    内存分区的意义：不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程

    2.程序运行前：程序编译后，生成了.exe可执行程序，未执行程序前分为两个区域
    代码区：
        存放CPU执行的机器指令
        代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
        代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令
    全局区：
        全局变量和静态变量存放在此
        全局区还包含了常量区，字符串常量和其他常量（包括全局常量）也存放在此
        该区域的数据在程序结束后由操作系统释放
    3.程序运行后：
    栈区：
        栈区的数据由编译器自动分配释放，存放函数的参数值，局部变量等
        注意：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放，函数执行完之后，局部变量会被释放
    堆区：
        由程序员分配数据，若程序员不释放，程序结束时由操作系统回收
        在C++中主要利用new在堆区开辟内存
    4.new操作符：利用new操作符在堆区开辟数据
        堆区开辟的数据，由程序员手动开辟，手动释放，释放利用delete
            new 数据类型
        利用new创建的数据，会返回该数据对应类型的指针，相当于返回了一个地址
*/

// 全局变量
int g_a = 10;
int g_b = 10;
// const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 10;

/*
    int * func01(int b)   // 形参数据也会放在栈区
    {
        b = 100;
        int a = 10;
        //return &a;   // 相当于 int * func() = &a;
        // 程序报错，无法返回局部变量的地址，函数执行完后栈区的数据会自动释放，能找到地址但是地址上没有值
        // 但是可以返回局部变量的值，编译器会拷贝该值放在一个使用者新定义的变量里面
    }
*/

int* func02()
{
    // 利用new关键字可以将数据开辟到堆区
    // 指针本质也是局部变量，放在栈上，但是指针保存的地址在堆区
    int *a = new int(10);   // new int(10)返回的是该数据类型的指针，本质上是一个地址编号，只能用指针存储 
    return a;   // 返回a后，能找到地址且地址在堆区，地址上有值
}

// 利用new创建数组
void func2()
{
    int *arr = new int[10];   // 10代表数组有10个元素
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;   // 给10个元素赋值100-109，可以利用arr[i]直接调用，与函数中调用指针数组相同
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //释放数组时要加一个中括号
    delete[] arr;   
}

int main()
{
    // 全局区：全局变量静态变量，常量

    // 局部变量->不在全局区
    int a = 10;   
    int b = 10;
    cout << "the position of local variable a: " << &a << endl;
    cout << "the position of local variable b: " << &b << endl; 

    // 全局变量->在全局区
    cout << "the position of global variable g_a: " << &g_a << endl;
    cout << "the position of global variable g_b: " << &g_b << endl;
    
    // 静态变量 在普通变量前加static，属于静态变量->在全局区
    static int s_a = 10;
    static int s_b = 10;
    cout << "the position of global variable s_a: " << &s_a << endl;
    cout << "the position of global variable s_b: " << &s_b << endl;
    // 可以发现全局变量和静态变量地址空间是连续的，但和局部变量不连续

    // 常量-字符串常量->在全局区
    cout << "the position of string: " << &"Hello World" << endl;   // 可以发现有一定距离，但总体离得不远
    // 常量-const修饰的变量->在全局区
    // const修饰全局变量--全局常量
    cout << "the position of const global variable c_g_a: " << &c_g_a << endl;
    cout << "the position of const global variable c_g_b: " << &c_g_b << endl;
    // 可以发现全局常量和全局变量，静态变量离得很近，在全局区

    // const修饰局部变量--局部常量->不在全局区
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "the position of const local variable c_g_a: " << &c_l_a << endl;
    cout << "the position of const local variable c_g_b: " << &c_l_b << endl;
    // 可以发现局部常量和局部变量离得很近，不在全局区

    // 栈
    // 接受func函数的返回值
    //int* p = func01();
    //cout << *p << endl;   // 程序报错

    // 在堆区开辟数据--new操作
    int* p = func02();
    cout << "*p = " << *p << endl;
    cout << "*p = " << *p << endl;   // 再次使用不会出现错误
    
    // 利用delete释放堆区的数据
    delete p;   // 实际上是将p指针指向内存中的值释放，无法继续输出
    func2();

    system("pause");
    return 0;
}