#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

/*
    谓词
    1.概念
        返回bool类型的仿函数称为 谓词
        如果operator()接受一个参数，那么叫做一元谓词
        如果operator()接受两个参数，那么叫做二元谓词
*/

// 一元谓词

class GreatorFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找容器中有没有大于5的数字
    // GreatorFive()匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreatorFive());   // 返回找到第一个的迭代器
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到大于5的数字为：" << *it << endl;
    }
}

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;   
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test02()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(60);
    v.push_back(70);
    sort(v.begin(), v.end());
    printVector(v);
    
    // 使用函数对象改变算法策略，降序排列
    // MyCompare()匿名函数对象
    sort(v.begin(), v.end(), MyCompare());
    printVector(v);
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