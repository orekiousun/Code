#include <iostream>
using namespace std;

/*
    引用
    1.引用的基本使用：给变量起别名
        数据类型 &别名 = 原名;
    2.引用的注意事项
        1）引用必须初始化
        2）引用在初始化之后，不可以发生改变
        3）直接cout引用本身其实就是打印了一个值而不是地址
    3.引用做函数参数
        函数传参时，可以利用引用让形参修改实参
        可以简化指针修改实参
        通过引用参数产生的效果同地址传递效果一致，引用的语法更清楚简单
    4.引用做函数返回值：通过引用的方式可以返回当前想要返回的的数据本体
        不能返回局部变量的引用
        函数的调用可以作为左值（等号左边的值）
        引用做函数返回值时，对应的return一定返回的是一个值，而不是地址
    5.引用的本质：在c++内部实现是一个指针常量
        int& ref = a; -> int* const ref = &a; 相当于创建了一个记录了a的地址的指针常量，这也是引用不可更改的原因
        ref = 20 -> *ref = 20; 相当于将ref保存的地址上的值改为了20，只要一用到ref就会自动解引用
    6.常量引用：主要是用于修饰形参，防止误操作
        在函数形参列表中，可以加const修饰形参，防止形参改变实参
    7.数组的引用
        int a[10];
        int (&b)[10] = a;
*/

// 值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 地址传递
void mySwap02(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//引用传递
void mySwap03(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}



// 引用做函数返回值
/*
    // 不能返回局部变量的引用
    int & test01
    {
        int a = 10;   // 存放在栈区
        return a;   // 语法错误，不能返回局部变量 
    }
*/
int& test02()
{
    static int w = 10;   // 变为静态变量，存在全局区，不放在栈区，在程序结束后由系统自动释放
    return w;   // 相当于返回了一个a的引用，返回了a的本体，如果不是静态变量，无法返回，因为函数结束后会被编译器释放
}

void showValue(int& val)
{
    val = 1000;   // 这里修改value值之后a值也会跟着一起改变，会引起误操作，所以一般选择定义一个常量引用
    cout << "val = " << val << endl;
}

void showValue2(const int& val)
{
    // val = 1000;   // a值变得无法修改
    cout << "val = " << val << endl;
}

void sort(int (&array)[10])   // 可以通过引用的方式传入数组
{
    int num = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < num; i++)
    {
        int min = i;
        for (int  j = i; j < num; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            mySwap03(array[min], array[i]);
            
        }
    }
}

int main() {
    int a = 10;
    int c = 20;
    int &b = a;
    // int &b;   // 引用必须要初始化
    // int &b = 10   // 引用必须引用一块合法的内存空间
    // &b = c;   // 引用在初始化之后，不可以发生改变
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // 引用做函数参数
    mySwap01(a, c);
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    mySwap02(&a, &c);
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    mySwap03(a, c);   // 相当于进行了一次引用传递的定义 int &a(形参) = a(实参)，利用引用传递，形参也会修饰实参 
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    // 引用做函数返回值
    // int &ref = test01();   // ref相当于上面a的引用，这样做会出现语法错误，因为返回的是一个局部变量
    int &ref = test02();   // 时&ref变为a的引用
    cout << "ref = " << ref << endl;
    // 将函数调用作为左值
    test02() = 1000; 
    cout << "ref = " << ref << endl;
    // 常量引用
    const int& ref2 = 10;
    // 加上const之后，编译器将代码修改为 int temp = 10; const int& ref2 = temp; 为其自动开辟了一个内存空间并保存了一个值，不允许修改
    // ref2 = 20;   // 程序报错，加入const之后变为只读，无法修改
    showValue(a);

    // 通过引用排序
    int array1[10] = {1, 3, 9, 2, 7, 5, 8, 0, 4, 6};
    sort(array1);   
    for (int i = 0; i < 10; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}