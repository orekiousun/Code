#include<iostream>
using namespace std;

/*
    指针
    1.概念：可以通过指针间接访问内存
        内存编号是从0开始记录，一般用十六进制数字表示
        可以利用指针变量保存地址，简单来说，指针就是一个地址 
    2.定义指针：数据类型 *指针变量;
        int* p;   // 定义指针
        p = &a;   // 让指针记录a的地址
        int* p = &a;   // 通过这种方式可以直接定义指针指向的地址，和前面两句代码实现的功能相同
    3.使用指针：可以通过解指针的方式找到指针指向的地址
        *p   // 指针前加一个*代表解引用，找到指针指向内存中的数据，即*p代表找到了p指针指向的内存中的数据
        注意：修改*p的值以后*p指向的内存空间的值（即a值）也会被修改
    4.指针所占内存空间
        在32位操作系统下占用4个字节空间，在64位下占用8个字节，无论任何类型占用的空间大小均为相同的
    5.空指针：指针变量指向内存中编号为0的空间，用于初始化指针变量
        int* p = NULL;
        注意：空指针指向的内存是不可以访问的
    6.野指针：指针变量指向非法的内存空间
        int* p = (int *)0x1100;   // 相当于没有提前申请地址，该地址无法操纵，没有访问权限
    总结：空指针和野指针均不是我们申请的空间，因此不要随意访问
    7.const修饰指针
        1）const修饰指针 -- 常量指针 -> 不可以改常量
            const int* p = &a;   // const后面接*，表示取*的操作（修改值）无法进行
            特点：指针的指向可以修改，但指针指向的值不可以修改，但是指向修改之后对应指针的值便会跟着修改
            即 *p = 20 不允许，p = &b 允许
        2）const修饰常量 -- 指针常量 -> 不可以改指针
            int* const p = &a;   // const后面接p，表示修改地址指向不可以操作
            特点：指针的指向不可以修改，但是指针指向的值可以修改
            即 *p = 20 允许，p = &b 不允许
        3）const既修饰指针，又修饰常量
            const int* const p = &a;
            特点：指针的指向和指针指向的值均不可以修改
            即 *p = 20，p = &b 均不允许
    8.指针和数组：利用指针访问数组中元素
        通过指针直接定义为数组：int* p = arr
        由于arr可以代表数组第一个元素的地址，所以该指针就直接指向了该数组第一个数据的地址
        又由于数组空间是连续的，所以进行p++就可以访问到数组后面的地址，从而取得值
    9.指针和函数：地址传递
        利用指针作函数参数时，可以修改实参的值，本质就是通过指针找到地址再修改地址中的值
    总结：值传递不能修改实参，地址传递可以修改实参
    10.指针配合数组和函数案例
        案例：封装一个函数，利用冒泡排序，实现对整型数组的升序排列
        注意：在函数定义时书写一个指针传入数组的首地址，函数中就直接可以利用p[i]索引的方式改变数组中的值，此时p[j]就直接表示数组中对应索引的值
    11.指针做函数返回值
        当把指针做函数返回值时，return后面的返回的一定是一个地址，而不是一个值
        返回值的操作等价于 数据类型* 函数名 = 返回值
*/

void swap(int * a, int * b)
{
    int temp = *a;   // 表示temp的值等于a的指针指向的地址中的值
    *a = *b;   // 表示将b指针指向的地址的值赋值给a指向地址的值
    *b = temp;   // 表示b指针指向地址的值变为temp，即原来a指针指向地址中的值
    // 这种方法没有交换a，b指针的定义，但交换了a，b指针中指向地址的值
    /*
    int * temp = a;
    a = b;
    b = temp;   // 这种用法时错误的，这样只交换了a，b指针的定义，没有交换a，b指针中存储的值
    */
}

void sort(int * p , int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if ( p[j] > p[j+1] )   // 初步推测这里p[i]就对用于*p++（++会一直加到对应的位数）
            {
                int temp = p[j];
                cout << "p[j] = " << p[j] << endl;
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}   // 函数中，可以直接利用中括号索引数据

int main()
{
    int a = 1;
    int * p;
    p = &a;   // p取a的地址
    // int * p = &a   // 通过这种方式可以直接使指针指向a的地址
    cout << "the position of a: " << &a << endl;   // 输出地址
    cout << "p = " << p << endl;   // 输出地址
    cout << "*p = " << *p << endl;   // 输出a值

    // 解引用
    *p = 2;   // 代表p指针指向的地址所存储的值为更新为2
    cout << "a = " << a << endl;   // 输出新的值
    cout << "*p = " << *p << endl;   // 输出新的值

    // 测试所占内存空间
    cout << "the size of p: "<< sizeof(p) << endl;
    cout << "the size of int *: "<< sizeof(int *) << endl;
    cout << "the size of float *: "<< sizeof(float *) << endl;
    cout << "the size of char *: "<< sizeof(char *) << endl;
    cout << "the size of long long *: "<< sizeof(long long *) << endl;

    // 空指针
    int * p2 = NULL;   // 定义空指针
    // *p = 100;   // 空指针不可以进行访问，这样写可以编译，但编译之后会报错

    // 野指针
    int * p3 = (int *)0x1100;
    // cout<< *p << endl;   // 没有访问权限，可以编译但会报错，避免尽量出现野指针 
    int b = 10, c = 20;

    // const修饰指针 -- 常量指针
    const int * p4 = &b;
    p4 = &c;   
    // 写 *p4 = 20 会报错
    // const修饰常量 -- 指针常量
    int * const p5 = &b;
    *p5 = 30;   
    // 写 p5 = &c 会报错
    cout << "b = " << b << ", " << "*p5 = " << *p5 << endl;
    // const既修饰指针，又修饰常量
    const int * const p6 = &b;
    // 写 p6 = &c, *p6 = &c 均会报错 

    // 指针和数组
    int arr[5] = {0, 1, 2, 3, 4};
    int * p7 = arr;   // arr就是数组的首地址，此时指针就直接指向了数组的首地址
    cout << "*p7 = " << *p7 << endl;   // *p7的值即为arr[0]的值
    cout << "the position of arr[0]: " << &arr[0] << endl;
    cout << "the position of p7: " << p7 << endl;
    p7++;
    cout << "*p7 = " << *p7 << endl;   // *p7的值即为arr[0]的值
    cout << "the position of arr[1]: " << &arr[1] << endl;
    cout << "the position of p7++: " << p7 << endl;

    // 利用指针书写函数进行地址传递
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(&a, &b);   // 这种调用方法同 int * a = &b; 只传递地址
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 封装一个函数，利用冒泡排序，实现对整型数组的升序排列
    int arr2[5] = {5 ,8, 6, 4, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    sort(arr2, 5);   // arr2数组名就代表数组的首地址，相当于 int * p = arr2 ，其中arr2代表数组首地址
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}