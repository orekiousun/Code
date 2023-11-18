#include<iostream>
#include<fstream>   // 包含头文件
#include<string>
using namespace std;


/*
    文件操作：将数据持久化 需要包含头文件<fstream>
    文件类型分类：
        ·文本文件    文件以文本的ASCII码的形式存储在计算机中   
        ·二进制文件  文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们
    操作文件的三大类：
        ·ofstream：写操作 - o代表output
        ·ifstream：读操作 - i代表input
        ·fstream：读写操作
    1.文本文件
        1）写文件步骤如下：
            a.包含头文件：#include<fstream>
            b.创建流对象：ofstream ofs;
            c.打开文件：ofs.open("文件路径", 打开方式);
            d.写数据：ofs << "写入数据";
            e.关闭文件：ofs.close();
        文件打开方式可以利用|操作符配合使用，例如：ofs.open("文件路径", ios::in | ios::out);
        2）读文件步骤如下：
            a.包含头文件：#include<fstream>
            b.创建流对象：ifstream ifs;
            c.打开文件：ifs.open("文件路径", 打开方式);
            d.读数据：四种方式读取
                ·将数据存储在字符数组中，利用右移运算符一行一行读取数据
                ·将数据存储在数组中，利用ifstream中的getline函数一行一行读取数据
                ·将数据存储在字符串中，利用全局函数getline一行一行读取数据
                ·将数据存储在一个字符串中，利用get函数一个一个地读取数据
            e.关闭文件：ifs.close();
        文件打开方式：
        ios::in      为读文件而打开文件
        ios::out     为写文件而打开文件
        ios::ate     初始位置：文件尾
        ios::app     追加方式写文件
        ios::trunc   如果文件存在先删除，再创建
        ios::binary  二进制方式
    2.二进制文件
    以二进制方式对文件进行读写操作，打开方式指定为 ios::binary
        1）写文件：利用流调用成员函数write
        函数原型：ostream& write(const char* buf, int len);
        字符指针buffer指向内存中一段存储空间，len是读写的字节数
        2）读文件：二进制方式读文件主要利用流对象调用成员函数read
        函数原型：istream& read(char *buffer, int len);
        字符指针buffer指向内存中一段存储空间，len是读写的字节数

*/
// 文件读写
void test01()   // 写文件
{
    ofstream ofs;   // 创建流对象
    ofs.open("2.8 File.txt", ios::out);   // 打开文件
    // ofs << "name:Lisa" << endl;
    // ofs << "gender:female" << endl;
    // ofs << "age:18" << endl;
    ofs.close();
    cout << "write success" << endl;
}
void test02()   // 读文件
{
    ifstream ifs;   // 创建流对象
    ifs.open("2.8 File.txt", ios::in);   // 打开文件，并且判断是否打开成功
    if(!ifs.is_open())
    {
        cout << "file open fail" << endl;
        return;
    }
    // 读数据方式
    // 1.将数据存储在字符数组中，利用右移运算符一行一行读取数据
    char buf[1024] = {0};
    while (ifs >> buf)   // 一行一行的读，读到结尾会返回一个假标志，退出while循环
    {
        cout << buf << endl;
    }
    // 2.将数据存储在数组中，利用ifstream中的getline函数一行一行读取数据
    char buf2[1024] = {0};
    while (ifs.getline(buf, 1024))   
    {
        cout << buf2 << endl;
    }
    // 3.将数据存储在字符串中，利用全局函数getline一行一行读取数据
    string buf3;
    while (getline(ifs, buf3))
    {
        cout << buf3 << endl;
    }
    // 4.将数据存储在一个字符串中，利用get函数一个一个地读取数据
    char c;
    while ((c = ifs.get()) != EOF)   // EOF:end of file ，指还没有读取到文件尾时
    {
        cout << c;
    }
    ifs.close();
    cout << "read success" << endl;
}

// 二进制文件读写
class Person
{
public:
    char name[64];
    int age;
};
void test03()   // 写二进制文件
{
    ofstream ofs;   // 创建流对象
    ofs.open("2.8 person.txt", ios::out | ios::binary);   // 打开文件
    Person p = {"Lisa", 18};   // 准备好一个数据
    ofs.write((const char*)&p, sizeof(Person));   // 写数据
    ofs.close();   // 关闭文件
}
void test04()   // 读二进制文件
{
    ifstream ifs;   // 创建流对象
    ifs.open("2.8 person.txt", ios::in | ios::binary);   // 打开文件
    if(!ifs.is_open())   // 判断是否打开成功
    {
        cout << "file open fail" << endl;
        return;
    }
    Person p;   // 将数据读到对象p中
    ifs.read((char*)&p, sizeof(Person));   // 写数据
    ifs.close();
    cout << "name:" << p.name << " age:" << p.age << endl;
}

int main()
{
    cout << "------------ test01 ------------" << endl;
    test01();
    cout << "------------ test02 ------------" << endl;
    test02();
    cout << "------------ test03 ------------" << endl;
    test03();
    cout << "------------ test04 ------------" << endl;
    test04();
    system("pause");
    return 0;
}