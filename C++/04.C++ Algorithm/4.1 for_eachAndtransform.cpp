#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
    算法主要是由头文件<algorithm> <functional> <numeric>组成。
    <algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
    <numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
    <functional>定义了一些模板类,用以声明函数对象
    常用遍历算法
        for_each      //遍历容器
        transform     //搬运容器到另一个容器中
    1.for_each
    功能描述：
        实现遍历容器
    函数原型
        for_each(iterator beg, iterator end, _func);
        // 遍历算法 遍历容器元素
        // beg 开始迭代器
        // end 结束迭代器
        // _func 函数或者函数对象
    2.transform
    功能描述：
        搬运容器到另一个容器中 -- 在搬运的过程中可以进行一些逻辑运算
    函数原型：  
        transform(iterator beg1, iterator end1, iterator beg2, _func);`
        //beg1 源容器开始迭代器
        //end1 源容器结束迭代器
        //beg2 目标容器开始迭代器
        //_func 函数或者函数对象

*/

// 普通函数
void print01(int val)
{
    cout << val << " ";
}
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
class Transform
{
public:
    int operator()(int v)
    {
        // 在搬运的过程中可以进行一些逻辑运算
        return v + 100;
    }
};
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print01);
    cout << endl;

    for_each(v.begin(), v.end(), print02());
    cout << endl;

    vector<int> vTarget;
    // 目标容器需要提前开辟空间
    vTarget.resize(10);

    transform(v.begin(), v.end(), vTarget.begin(), Transform());
    for_each(vTarget.begin(), vTarget.end(),print02());
    cout << endl;

}

int main()
{
    cout << "------------ test01 ------------" << endl;
    test01();

    system("pause");
    return 0;
}