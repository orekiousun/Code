#include<iostream>
using namespace std;
#include<numeric>
#include<vector>
#include<algorithm>

/*
    常用算术生成算法
    算术生成算法属于小型算法，使用时包含的头文件为 `#include <numeric>
        accumulate         // 计算容器元素累计总和
        fill               // 向容器中添加元素
    1.accumulate
    功能描述：
        计算区间内 容器元素累计总和
    函数原型：
        accumulate(iterator beg, iterator end, value);
        // 计算容器元素累计总和
        // beg 开始迭代器
        // end 结束迭代器
        // value 起始累加值->最后结果会加上这个value
    2.fill
    功能描述：
        向容器中填充指定的元素
    函数原型：
        fill(iterator beg, iterator end, value);  `
        // 向容器中填充元素
        // beg 开始迭代器
        // end 结束迭代器
        // value 填充的值
*/

// accumulate
void test01()
{
    vector<int> v;
    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }
    int result = accumulate(v.begin(), v.end(), 0);
    cout << result << endl;
    result = accumulate(v.begin(), v.end(), 1000);
    cout << result << endl;
}

// fill
void myPrint(int v)
{
    cout << v << " ";
}
void test02()
{
    vector<int> v;
    v.resize(10);
    fill(++v.begin(), --v.end(), 1);
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    cout << "------------ test01 ------------" << endl;
    test01();
    cout << "------------ test02 ------------" << endl;
    test02();
    system("pause");
    return 0;
}