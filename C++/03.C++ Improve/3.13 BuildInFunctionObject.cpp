#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

/*
    STL内建了一些函数对象
    1.分类
        算术仿函数
        关系仿函数
        逻辑仿函数
    2.用法
        这些仿函数所产生的对象，用法和一般函数完全相同
        使用内建函数对象，需要引入头文件 #include<functional>
    3.算术仿函数
        实现四则运算
        其中negate是一元运算，其他都是二元运算
    仿函数原型：
        template<class T> T plus<T>               //加法仿函数
        template<class T> T minus<T>              //减法仿函数
        template<class T> T multiplies<T>         //乘法仿函数
        template<class T> T divides<T>            //除法仿函数
        template<class T> T modulus<T>            //取模仿函数
        template<class T> T negate<T>             //取反仿函数
    4.关系仿函数
        实现关系对比
    仿函数原型：
        template<class T> bool equal_to<T>        //等于
        template<class T> bool not_equal_to<T>    //不等于
        template<class T> bool greater<T>         //大于
        template<class T> bool greater_equal<T>   //大于等于
        template<class T> bool less<T>            //小于
        template<class T> bool less_equal<T>      //小于等于
    5.逻辑仿函数
        实现逻辑运算
    函数原型：
        template<class T> bool logical_and<T>              //逻辑与
        template<class T> bool logical_or<T>                //逻辑或
        template<class T> bool logical_not<T>              //逻辑非
*/

//算术仿函数
void test01()
{
    // 一元仿函数
    negate<int> n;   // 取反
    cout << n(50) << endl;

    // 二元仿函数
    plus<int> p;
    cout << p(10, 20) << endl;
    modulus<int> m;
    cout << m(10, 3) << endl;
}

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;   
}

// 关系仿函数
void test02()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(70);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(30);
    v.push_back(10);
    printVector(v);
    sort(v.begin(), v.end());
    printVector(v);

    // greater<int>()内建函数匿名对象
    sort(v.begin(), v.end(), greater<int>());   // 利用内建仿函数实现
}

// 逻辑仿函数 
void test03()
{
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    vector<bool> v2;
    v2.resize(v.size());   // 目标容器需要提前开辟一段空间
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    cout << "------------ test01 ------------" << endl;
    test01();
    cout << "------------ test02 ------------" << endl;
    test02();
    cout << "------------ test03 ------------" << endl;
    test03();
    system("pause");
    return 0;
}