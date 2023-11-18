#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>
#include<functional>

/*
    常用拷贝和替换算法
        copy                 // 容器内指定范围的元素拷贝到另一容器中
        replace              // 将容器内指定范围的旧元素修改为新元素
        replace_if           // 容器内指定范围满足条件的元素替换为新元素
        swap                 // 互换两个容器的元素
    1.copy  --  实际开发中建议用等号赋值
    功能描述：
        容器内指定范围的元素拷贝到另一容器中
    函数原型：
        copy(iterator beg, iterator end, iterator dest);  `
        // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
        // beg  开始迭代器
        // end  结束迭代器
        // dest 目标起始迭代器
    2.replace
    功能描述：  
        将容器内指定范围的旧元素修改为新元素
    函数原型：
        replace(iterator beg, iterator end, oldvalue, newvalue);  `
        // 将区间内旧元素 替换成 新元素
        // beg 开始迭代器
        // end 结束迭代器
        // oldvalue 旧元素
        // newvalue 新元素
    3.replace_if
    功能描述:  
        将区间内满足条件的元素，替换成指定元素
    函数原型：
        replace_if(iterator beg, iterator end, _pred, newvalue);  
        // 按条件替换元素，满足条件的替换成指定元素
        // beg 开始迭代器
        // end 结束迭代器
        // _pred 谓词
        // newvalue 替换的新元素
    4.swap
    功能描述：
        互换两个容器的元素
    函数原型：
        swap(container c1, container c2);
        // 互换两个容器的元素
        // c1容器1
        // c2容器2
*/
void myPrint(int v)
{
    cout << v << " ";
}

// copy
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    vector<int> v2;
    v2.resize(10);
    copy(v.begin(),  v.end(), v2.begin());
    for_each(v2.begin(), v2.end(), myPrint);
    cout << endl;
}

// replace
void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(30);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(20);
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    replace(v.begin(), v.end(), 10, 77);
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

// replace_if
class ReplaceIf
{
public:
    bool operator()(int v)
    {
        return v > 5;
    }
};
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    replace_if(v.begin(), v.end(), ReplaceIf(), 77);
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

// swap
void test04()
{
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 10);
    }
    for_each(v1.begin(), v1.end(), myPrint);
    cout << endl;
    for_each(v2.begin(), v2.end(), myPrint);
    cout << endl;
    swap(v1, v2);
    for_each(v1.begin(), v1.end(), myPrint);
    cout << endl;
    for_each(v2.begin(), v2.end(), myPrint);
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
    cout << "------------ test04 ------------" << endl;
    test04();
    system("pause");
    return 0;
}