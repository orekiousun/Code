#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    常用集合算法
        set_intersection          // 求两个容器的交集
        set_union                 // 求两个容器的并集
        set_difference            // 求两个容器的差集
    1.set_intersection
    功能描述：
        求两个容器的交集
    函数原型：
        set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
        // 求两个集合的交集
        // 注意:两个集合必须是有序序列
        // beg1 容器1开始迭代器
        // end1 容器1结束迭代器
        // beg2 容器2开始迭代器
        // end2 容器2结束迭代器
        // dest 目标容器开始迭代器
        // 返回末尾迭代器
    2.set_union
    功能描述：
        求两个集合的并集
    函数原型：
        set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
        // 求两个集合的并集
        // 注意:两个集合必须是有序序列
        // beg1 容器1开始迭代器
        // end1 容器1结束迭代器
        // beg2 容器2开始迭代器
        // end2 容器2结束迭代器
        // dest 目标容器开始迭代器
        // 返回末尾迭代器
    3.set_difference
    功能描述：
        求两个集合的差集
    函数原型：
        set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
        // 求两个集合的差集
        // 注意:两个集合必须是有序序列
        // beg1 容器1开始迭代器
        // end1 容器1结束迭代器
        // beg2 容器2开始迭代器
        // end2 容器2结束迭代器
        // dest 目标容器开始迭代器
        // 返回末尾迭代器
*/
// set_intersection
void myPrint(int v)
{
    cout << v << " ";
}
void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    
    vector<int> target;
    target.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    // 返回一个到最后的迭代器
    for_each(target.begin(), itEnd, myPrint);
    cout << endl;
}

// set_union
void test02()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> target;
    target.resize(v1.size() + v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    for_each(target.begin(), itEnd, myPrint);
    cout << endl;
}

// set_difference
void test03()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> target;
    target.resize(max(v1.size(), v2.size()));
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    for_each(target.begin(), itEnd, myPrint);
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