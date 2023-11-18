#include<iostream>
using namespace std;
#include<list>
#include<set>

/*
    set/multiset（集合）容器 - 所有元素都会在插入时自动被排序
    属于关联式容器，底层结构是用二叉树实现
    使用时仅需#include<set>
    set和multiset区别：
        set不允许容器中有重复的元素
        multiset允许容器中有重复的元素
    1.set构造和赋值
    构造：
        set<T> st;                       //默认构造函数：
        set(const set &st);              //拷贝构造函数
    赋值：
        set& operator=(const set &st);   //重载等号操作符
    2.set大小和交换
        size();                          //返回容器中元素的数目
        empty();                         //判断容器是否为空
        swap(st);                        //交换两个集合容器
    // set不允许重新指定大小
    3.set插入和删除
        insert(elem);                    //在容器中插入元素
        clear();                         //清除所有元素
        erase(pos);                      //删除pos迭代器所指的元素，返回下一个元素的迭代器
        erase(beg, end);                 //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
        erase(elem);                     //删除容器中值为elem的元素
    4.set查找和统计
        find(key);                       //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
        count(key);                      //统计key的元素个数
    5.set和multiset区别
        set不可以插入重复数据，而multiset可以
        set插入数据的同时会返回插入结果，表示插入是否成功
        multiset不会检测数据，因此可以插入重复数据
    6.pair对组创建
    成对出现的数据，利用对组可以返回两个数据
    创建方式：
        pair<type, type> p ( value1, value2 );
        pair<type, type> p = make_pair( value1, value2 );
    获取数据
        p.first p.second
    7.set容器排序
    利用仿函数，可以改变排序规则

*/
void printSet(const set<int> &s)
{
    for ( set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void printMuitiset(const multiset<int> &s)
{
    for ( multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// set构造和赋值
void test01()
{
    // 默认构造
    set<int>s1;
    s1.insert(20);   // 利用insert插入
    s1.insert(10);   
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);   // 发现输出结果自动排序，并且相同元素只能出现一次
    // set容器不允许插入重复的值

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);
}

// set大小和交换
void test02()
{
    // 大小
    set<int>s1;
    s1.insert(20);   // 利用insert插入
    s1.insert(10);   
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);   // 发现输出结果自动排序，并且相同元素只能出现一次
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s1.empty() = " << s1.empty() << endl;

    // 交换
    set<int> s2;
    s2.insert(1);
    s2.insert(7);
    s2.insert(3);
    s2.insert(6);
    s2.insert(4);
    cout << "交换前：" << endl;
    printSet(s1);
    printSet(s2);
    s1.swap(s2);
    cout << "交换后：" << endl;
    printSet(s1);
    printSet(s2);
}

// set插入和删除
void test03()
{
    // insert(elem);   
    set<int>s1;
    s1.insert(20);   // 利用insert插入
    s1.insert(10);   
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);   // 发现输出结果自动排序，并且相同元素只能出现一次

    // erase(pos);     
    s1.erase(s1.begin());
    printSet(s1);

    // erase(elem);  
    s1.erase(30);
    printSet(s1);

    // erase(beg, end); 
    set<int> s2;
    s2.insert(1);
    s2.insert(7);
    s2.insert(3);
    s2.insert(6);
    s2.insert(4);
    s2.erase(++s2.begin(), --(--s2.end()));
    printSet(s2);

    // clear();        
    s2.clear();
    printSet(s2);             
}

void test04()
{
    set<int>s1;
    s1.insert(20);   // 利用insert插入
    s1.insert(10);   
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    cout << "*s1.find(20) = " << *s1.find(20) << endl;
    cout << "s1.count(10) = " << s1.count(10) << endl;  
    s1.insert(10);
    s1.insert(10);
    s1.insert(10);
    cout << "s1.count(10) = " << s1.count(10) << endl;  
    // 结果只有可能是0/1，因为相同元素不能重复存在
}

// set和multiset区别
void test05()
{
    set<int>s1;
    s1.insert(20);   
    s1.insert(10);   
    s1.insert(40);
    s1.insert(30);
    s1.insert(10);
    printSet(s1);
    pair<set<int>::iterator, bool> ret = s1.insert(10);   // 返回值为pair类型
    cout << "ret.second = " << ret.second << endl;   // 返回值为0，说明插入失败

    multiset<int>ms1;   
    ms1.insert(20);   // 返回一个迭代器，不会返回是否插入成功
    // 一定能成功插入
    ms1.insert(10);
    ms1.insert(40);
    ms1.insert(30);
    ms1.insert(10);
    printMuitiset(ms1);
}

// pair对组创建
void test06()
{
    pair<string, int> p1("Lisa", 27);
    pair<string, int> p2 = make_pair("Ikura", 22);
    cout << "p1.first = " << p1.first << endl;
    cout << "p2.second = "<< p2.second << endl;
}

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
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
class MyCompare2
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.age < p2.age;
    }
};
void test07()
{
    // set中存放内置数据类型
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(50);
    s1.insert(30);
    printSet(s1);
    
    set<int, MyCompare> s2;   // <>号内只能指定类型，会按照类中的符号重载实现修改排序   
    s2.insert(10);
    s2.insert(20);
    s2.insert(40);
    s2.insert(50);
    s2.insert(30);
    for (set<int,MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    // printSet(s2);   // 报错，由于<>内指定的类型发生了改变

    // set中存放自定义数据类型
    // 自定义数据类型需要指定排序规则，不然无法正常插入和输出
    set<Person, MyCompare2> s3;
    Person p1("Lisa", 26);
    Person p2("Ikura", 22);
    Person p3("Aimer", 27);
    Person p4("Jusin", 28);
    Person p5("Taylor", 32);
    Person p6("Yama", 24);
    // 同时，如果年龄出现相同项，会直接被删除
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);
    s3.insert(p4);
    s3.insert(p5);
    s3.insert(p6);
    for (set<Person, MyCompare2>::iterator it = s3.begin(); it != s3.end(); it++)
    {
        cout << "name: " << it->name << " \tage: " << it->age << endl;
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
    cout << "------------ test05 ------------" << endl;
    test05(); 
    cout << "------------ test06 ------------" << endl;
    test06();
    cout << "------------ test07 ------------" << endl;
    test07();
    system("pause");
    return 0;
}