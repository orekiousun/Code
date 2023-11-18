#include<iostream>
using namespace std;
#include<string.h>
/*
    数据类型
    存在的意义：给变量分配合适的内存空间
    1.整型
        short      短整型    占用2字节                                        取值-2^15-2^15-1
        int        整型      占用4字节                                        取值-2^31-2^31-1
        long       长整型    Windows4字节，Linux4字节（32位），8字节（64位）   取值-2^31-2^31-1
        long long  长长整型  占用8字节                                        取值-2^63-2^63-1
    2.sizeof关键字：统计数据类型所占内存大小
        sizeof(数据类型/变量)
    3.实型（浮点型）
        float      单精度     占用4字节        7位有效数字
        double     双精度     占用8字节        15-16位有效数字
    科学计数法表示小数：
        float f2 = 3e-2;   // 表示3*10^-2
    4.字符型
        char ch = 'a';   // 只能用单引号将字符括起来，内部只能写一个字符，c/c++中字符类型只占用1字节的内存，存储ASCII码
    5.转义字符
        \a 警报      \b 退格      \f 换页
        \n 换行      \t 水平制表，跳到下一个tab位置，可整齐地输出数据     \\ 代表一根斜线"\""
    6.字符串类型
        C风格字符串：
            char 变量名[] = "字符串值";   // 相当于生成了一个字符数组，用双引号包含字符串
        C++风格字符串：
            string 变量名 = "字符串值";   // 需要包含头文件#include<string.h>
    7.bool类型，所占内存空间为1
        true -- 真（本质是1）
        false -- 假（本质是0）
    8.数据的输入：cin
*/

int main()
{
    // 整型测试
    short num1 = 10;
    int num2 = 10;
    long num3 = 10;
    long long num4 = 10;
    cout << "number:" << num1 <<" sizeof num:"<< sizeof(num1) << " size of short:" << sizeof(short) << endl;
    cout << "number:" << num2 <<" sizeof num:"<< sizeof(num2) << " size of short:" << sizeof(int) << endl;
    cout << "number:" << num3 <<" sizeof num:"<< sizeof(num3) << " size of short:" << sizeof(long) << endl;
    cout << "number:" << num4 <<" sizeof num:"<< sizeof(num4) << " size of short:" << sizeof(long long) << endl;
    // 浮点型测试
    float f1 = 12313.1415926f;   // 加上f后会变为单精度，不加的话会默认为该小数为双精度
    double d1 = 3.1415926;
    double d2 = 3.1415e-2;
    cout << "float number:" << f1 << " size of float:" << sizeof(float) << endl;
    cout << "double number:" << d1 << " size of double:" << sizeof(double) << endl;   // cout无法打印出多位有效数字，需要做额外配置，默认情况下会显示出6位有效数字
    cout << d2 << endl;
    // 字符型测试
    char ch = 'a';
    cout << "ch = " << ch << " sizeof char:" << sizeof(ch) << " ASCII:" << (int)ch << endl;   // 进行强制类型转换
    // 转义字符测试
    cout << "Hello World\n";
    cout << "\tHello World\\" << endl;
    cout << "aaa\tHello World\\"<< endl;   // 一个/t加上其前面的字符串会占用8个位置
    // 字符串测试
    char str[] = "Hello World";
    cout << "str:" << str << endl;
    string str2 = "Hello World";
    cout << "str2:" << str2 << endl;
    // bool类型测试
    bool flag = true;
    cout << flag << " size:" << sizeof(flag) << endl;
    bool flag2 = false;
    cout << flag2 << " size:" << sizeof(flag2) << endl;
    // 数据的输入
    int a;   // 整型
    cout << "input the int value of a:";
    cin >> a;
    cout << "the int value of a is:" << a << endl;
    float b;   // 浮点型
    cout << "input the float value of b:";
    cin >> b;
    cout << "the float value of b is:" << b << endl;
    char c;   // 字符型
    cout << "input the char value of c:";
    cin >> c;
    cout << "the char value of c is:" << c << endl;
    string d; // 字符类型
    cout << "input the string value of d:";
    cin >> d;
    cout << "the string value of d is:" << d << endl;
    bool e = false;  // bool类型（一定要赋予一个初值，不然无法定义新的值）
    cout << "input the bool value of e:";
    cin >> e;   // 此时地输入值只能为0或其他整数，0代表false，其余均为true
    cout << "the bool value of e is:" << e << endl;
    
    
}