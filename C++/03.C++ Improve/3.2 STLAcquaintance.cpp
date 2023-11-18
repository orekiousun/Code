#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>   // 标准算法头文件

/*
    1.STL的诞生
    软件界一直希望建立一种可重复利用的东西
    C++面向对象的三大特性封装、继承、多态以及泛型编程的思想，目的就是复用性的提升
    大多情况下，数据结构算法都未能有一套标准，导致被迫从事大量重复工作
    为了建立数据结构和算法的一套标准，诞生了STL
    
    2.STL的基本概念
    STL(Standard Template Library)标准模板库
    STL从广义上分为：容器(container)，算法（algorithm），迭代器（iterator）
    容器和算法之间通过迭代器无缝衔接
    STL几乎所有代码都采用了模板或者模板函数

    3.STL六大组件
    容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器
    1）容器：各种数据结构，如vector，list，deque，set，map等用于存放数据
    1）算法：各种常用算法，如sort，find，copy，for_each等
    1）迭代器：扮演了容器与算法之间的胶合剂
    1）仿函数：行为类似函数，可作为算法的某种策略
    1）适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
    1）空间配置器：负责空间的配置与管理

    4.STL中容器，算法，迭代器
    容器：置物之所也
    STL容器就是将运用最广泛的一些数据结构实现出来
    常用的数据类型：数组，链表，树，栈，队列，集合，映射表等
    这些容器分为序列式容器和关联式容器
        序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置
        关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

    算法（Algorithms）：问题值解法也
    有限的步骤，解决逻辑或数学上的问题
    算法分为：质变算法和非质变算法
    质变算法：是指运算过程中会更改区间内的元素的内容，如拷贝，替换，删除等
    非质变算法：是指运算过程中不会更改区间内的元素的内容，如查找，计数，遍历，寻找极值等

    迭代器：容器和算法之间的粘合剂
    提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式
    每个容器都有i记得专属的迭代器迭代器类似于指针，初学阶段可以理解为指针
    迭代器种类：
    输入迭代器     对数据的访问                                                  只读，支持++、==、!=
    输出迭代器     对数据的只写访问                                              只写，支持++
    前向迭代器     读写操作，并能向前推进迭代器                                   读写，支持++、==、!=
    双向迭代器     读写操作，并能向前和向后操作                                   读写，支持++、--
    随机访问迭代器 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器          读写，支持++、--、[n]、-n、<、<=、>、>=
    其中双向迭代器和随机访问迭代器最为常用
*/

// vector容器存放内置数据类型
void myPrint(int val)
{
    cout << val << " ";
}
void test01()
{
    vector<int> v;   // 创建一个vector容器
    v.push_back(1);   // vector容器提出的方法，尾插数据
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int>::iterator itBegin = v.begin();   // 起始迭代器，指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();   // 结束迭代器，指向容器中最后一个元素的下一个位置

    // 第一种遍历方式
    while(itBegin != itEnd)
    {
        cout << *itBegin << " ";
        itBegin++;
    }
    cout << endl;

    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";   // *it所代表数据的数据类型与尖括号内数据类型一致
        itBegin++;
    }
    cout << endl;
    
    // 第三种遍历方式 利用STL中提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);   // 标准算法
    cout << endl;
}

// vector容器存放自定义数据类型
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
};
void test02()
{
    vector<Person> v;
    Person p1("a", 10);
    Person p2("b", 11);
    Person p3("c", 12);
    Person p4("d", 13);
    Person p5("e", 14);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << (*it).name << " age：" << it->age << endl;   // *it即代表一个Person的数据类型，也可以利用箭头调出成员属性
    }
}
// 存放自定义数据类型的指针
void test03()
{
    vector<Person*> v;
    Person p1("a", 10);
    Person p2("b", 11);
    Person p3("c", 12);
    Person p4("d", 13);
    Person p5("e", 14);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << (*(*it)).name << " age：" << (*it)->age << endl;   // *it即代表一个Person的地址，可以利用箭头调出成员属性，也可以再次解引用利用.调用
    }
}

// vector容器中嵌套vector容器
void test04()
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i * 1);
        v2.push_back(i * 2);
        v3.push_back(i * 3);
        v4.push_back(i * 4);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator it_in = (*it).begin(); it_in != (*it).end() ; it_in++)
        {
            cout << *it_in << " ";
        }
        cout << endl;
    }
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