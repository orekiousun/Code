#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>

/*
    常用查找算法：
        find                    //查找元素
        find_if                 //按条件查找元素
        adjacent_find           //查找相邻重复元素
        binary_search           //二分查找法
        count                   //统计元素个数
        count_if                //按条件统计元素个数
    1.find  --  自定义数据类型需要重载等号(注意重载参数传参形式const Person &p)
    功能描述：
        查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
    函数原型：
        find(iterator beg, iterator end, value);
        // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
        // beg 开始迭代器
        // end 结束迭代器
        // value 查找的元素
    2.find_if
    功能描述：
        按条件查找元素
    函数原型：
    find_if(iterator beg, iterator end, _Pred);  `
        // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
        // beg 开始迭代器
        // end 结束迭代器
        // _Pred 函数或者谓词（返回bool类型的仿函数）
    3.adjacent_find
    功能描述：
        查找相邻重复元素
    函数原型：
        adjacent_find(iterator beg, iterator end);  `
        // 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
        // beg 开始迭代器
        // end 结束迭代器
    4.binary_search
    功能描述：
        查找指定元素是否存在
    函数原型：
        bool binary_search(iterator beg, iterator end, value);  `
        // 查找指定的元素，查到 返回true  否则false
        // 注意: 在**无序序列中不可用**
        // beg 开始迭代器
        // end 结束迭代器
        // value 查找的元素
    5.count  --  自定义数据类型需要重载等号
    功能描述：
        统计元素个数
    函数原型：
        count(iterator beg, iterator end, value);
        // 统计元素出现次数
        // beg 开始迭代器
        // end 结束迭代器
        // value 统计的元素
    6.count_if
    功能描述：
        按条件统计元素个数
    函数原型：
    count_if(iterator beg, iterator end, _Pred);
        // 按条件统计元素出现次数
        // beg 开始迭代器
        // end 结束迭代器
        // _Pred 谓词
*/

class Person
{
public:
    string name;
    int age;
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator==(const Person &p)
    {
        if (this->name == p.name && this->age == p.age)
        {
            return true;
        }
        else
        {
            return false;
        }   // 需要重载等号符
    }
};
// find
void test01()
{
    // 查找内置数据类型
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if(it == v.end())
        cout << "data not found" << endl;
    else    
        cout << *it << endl;


    // 查找自定义数据类型 -- 利用自建的数据类型需要重载等号==运算符
    vector<Person> v2;
    Person p1("Saber" ,1);
    Person p2("Rider" ,2);
    Person p3("Archer" ,3);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    Person pp("Rider" ,2);
    vector<Person>::iterator it2 = find(v2.begin(), v2.end(), pp);
    if(it2 == v2.end())
        cout << "data not found" << endl;
    else    
        cout << (*it2).name << "\t" << (*it2).age << endl;
}

// find_if
class FindIf
{
public:
    bool operator()(int v)
    {
        return v > 7;
    }
};
class FindIf2
{
public:
    bool operator()(Person &p)
    {
        return p.age > 2;
    }
};
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), FindIf());
    if(it == v.end())
        cout << "data not found" << endl;
    else    
        cout << *it << endl;

    vector<Person> v2;
    Person p1("Saber" ,1);
    Person p2("Rider" ,2);
    Person p3("Archer" ,3);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    vector<Person>::iterator it2 = find_if(v2.begin(), v2.end(), FindIf2());
    if(it2 == v2.end())
        cout << "data not found" << endl;
    else    
        cout << (*it2).name << "\t" << (*it2).age << endl;
}

// adjacent_find
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    v.push_back(9);
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if(it == v.end())
        cout << "data not found" << endl;
    else    
        cout << *it << endl;
}

// binary_search
void test04()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    bool res = binary_search(v.begin(), v.end(), 5);
    if (res)
        cout << "data found success" << endl;
    else
        cout << "data not found" << endl;
}

// count
void test05()
{
    // 统计内置数据类型
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int ct = count(v.begin(), v.end(), 5);
    cout << ct << endl;

    // 统计自定义数据类型
    vector<Person> v2;
    Person p1("Saber" ,1);
    Person p2("Rider" ,2);
    Person p3("Archer" ,3);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p2);
    v2.push_back(p2);
    v2.push_back(p2);
    Person pp("Rider" ,2);
    int ct2 = count(v2.begin(), v2.end(), pp);
    cout << ct2 << endl;
}

// count_if
class CountIf
{
public:
    bool operator()(int v)
    {
        return v > 7;
    }
};
class CountIf2
{
public:
    bool operator()(Person &p)
    {
        return p.age == 2;
    }
};
void test06()
{
     // 统计内置数据类型
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int ct = count_if(v.begin(), v.end(), CountIf());
    cout << ct << endl;

    // 统计自定义数据类型
    vector<Person> v2;
    Person p1("Saber" ,1);
    Person p2("Rider" ,2);
    Person p3("Archer" ,3);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p2);
    v2.push_back(p2);
    v2.push_back(p2);
    int ct2 = count_if(v2.begin(), v2.end(), CountIf2());
    cout << ct2 << endl;
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
    cout << "------------ test05 ------------" << endl;
    test05();
    cout << "------------ test06 ------------" << endl;
    test06();
    system("pause");
    return 0;
}