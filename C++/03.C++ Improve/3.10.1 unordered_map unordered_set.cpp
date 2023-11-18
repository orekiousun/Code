#include<iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include<string>

/*
    unordered_set
    无序 set 容器
    即 unordered_set 容器和 set 容器很像，唯一的区别就在于 set 容器会自行对存储的数据进行排序，而 unordered_set 容器不会
    unordered_set的几个特性
        ·不再以键值对的形式存储数据，而是直接存储数据的值
        ·容器内部存储的各个元素的值都互不相等，且不能被修改
        ·不会对内部存储的数据进行排序
    1.unordered_set的构造和赋值
        unordered_set<int> set1;                             // 创建空的unordered_set
        unordered_set<int> set2(set1);                       // 拷贝构造
        unordered_set<int> set3(set1.begin(), set1.end());   // 迭代器构造
        unordered_set<int> set4(arr,arr+5);                  // 使用数组作为其初值进行构造
        unordered_set<int> set6 {1,2,10,10};                 // 使用处置列表进行构造
    2.常用内置函数
        set1.empty();    // 判断是否为空
        set1.find(2);    // 查找，成功返回迭代器吗，失败返回空
        set1.count(2);   // 出现次数
    3.插入和删除元素
    插入：
        set1.insert(3);                          // 插入元素，返回pair<unordered_set<int>::iterator, bool>
        set1.insert({1,2,3});                    // 使用initializer_list插入元素（初始化列表）， 没有返回值
        set1.insert(set1.end(), 4);              // 指定插入位置，如果位置正确会减少插入时间，返回指向插入元素的迭代器
        set1.insert(set2.begin(), set2.end());   // 使用范围迭代器插入
        set1.emplace(3);                         // 使用转移构造函数添加新元素3，比insert效率高
    删除：
        set1.erase(1);                           // 删除操作，成功返回1，失败返回0
        set1.erase(set1.find(1));                // 删除操作，成功返回下一个pair的迭代器
        set1.erase(set1.begin(), set1.end());    // 删除set1的所有元素，返回指向end的迭代器
    清空:
        set1.clear();


    unordered_map
        ·是一种关联容器，存储基于键值和映射组成的元素，即key-value。允许基于键快速查找元素。在unordered_map中，键值唯一标识元素，映射的值是一个与该对象关联的内容的对象
        ·无序体现在内部存储结构为哈希表，以便通过键值快速访问元素
        ·查找效率更高，可以达到O(1)，但是对于元素子集的范围迭代效率较低
    1.unordered_map的构造和赋值
        unordered_map<int, string> umap;                                                  // 默认构造
        unordered_map<int, string> umap = unordered_map<int, string>({{1,"a"},{2,"b"}});  // 显式调用C++的构造函数
        unordered_map<int, string> umap2({{3,"c"},{4,"d"}});	                          // 隐式调用构造函数，更简洁
        unordered_map<string, string> umap{
            {"淘宝","https://www.taobao.com/"},
            {"京东","https://www.jd.com/"},
            {"天猫商城","https://jx.tmall.com/"} };
        unordered_map<int, string> umap4(umap3);                                          // 拷贝构造函数 
        unordered_map<int, string> umap5(umap1.begin(), umap1.end());                     // 迭代器构造
    2.常用内置函数
        first.empty();        // 判空
        third.size();         // 大小
        mymap1.find(key);     // 通过键值查找元素
        mymap1.count(key);    // 判断集合中键值key对应的元素的数量
    3.访问和修改元素
        first["GOOG"] = "Google";    // 通过[]访问并修改
        mymap.at("Saturn") += 127;   // 通过at访问并修改
    4.插入和删除元素
    插入：
        mymap.emplace ("NCC-1701", "J.T. Kirk");                       // 利用emplace插入
        myrecipe.insert(myshopping);                                   // 利用insert插入
        myrecipe.insert(mypantry.begin(), mypantry.end());             // 利用insert插入一个区间
        myrecipe.insert({{"sugar",0.8},{"salt",0.1},{"sugar",0.9}});   // 利用insert同时插入多个值
    删除：
        mymap3.erase(mymap3.begin());                         // 利用迭代器删除
        mymap3.erase("France");                               // 利用key删除
        mymap3.erase(mymap3.find("Germany"), mymap3.end());   // 删除区间
*/

void printUnorderedSet(const unordered_set<int> set)
{
    for (unordered_set<int>::const_iterator it = set.begin(); it != set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    unordered_set<int> s1{2, 5, 1, 3, 4, 2, 1};
    printUnorderedSet(s1);
    unordered_set<int> s2(s1);
    printUnorderedSet(s2);
    unordered_set<int> s3(s1.begin(), s1.end());
    printUnorderedSet(s3);

    cout << "s1.empty() = " << s1.empty() << endl;
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s1.count(2) = " << s1.count(2) << endl;
    cout << "*(s1.find(1)) = " << *(s1.find(1)) << endl;

    s1.insert(6);
    printUnorderedSet(s1);
    s1.emplace(7);
    printUnorderedSet(s1);
    s1.erase(s1.find(3));
    printUnorderedSet(s1);
}


void printUnorderedMap(const unordered_map<int, string> map)
{
    for (unordered_map<int, string>::const_iterator it = map.begin(); it != map.end(); it++)
    {
        cout << "key: " << (*it).first << "\tvalue: " << (*it).second << endl;
    }
}
void test02()
{
    unordered_map<int, string> m1{{1, "Lisa"}, {2, "YOASOBI"}, {3, "Yama"}};
    unordered_map<int, string> m2(m1);
    unordered_map<int, string> m3(m1.begin(), m1.end());

    cout << "m1: " << endl;
    printUnorderedMap(m1);
    cout << "m2: " << endl;
    printUnorderedMap(m2);
    cout << "m3: " << endl;
    printUnorderedMap(m3);

    cout << "m1.empty() = " << m1.empty() << endl;
    cout << "m1.size() = " << m1.size() << endl;
    cout << "(*(m1.find(2))).second = " << (*(m1.find(2))).second << endl;
    cout << "m1.count(2) = " << m1.count(2) << endl;
    cout << "m1[1] = " << m1[1] << endl;
    cout << "m1.at(3) = " << m1.at(3) << endl;

    pair<int, string> p1(2, "Ikura");
    pair<int, string> p2(2, "Ayase");
    pair<int, string> p3(4, "Aimer");
    m1.insert(p1);
    m1.insert(p2);   // 会发现p1,p2已经存在无法插入
    m1.emplace(2, "Ikura");
    m1.insert(p3);
    m1.emplace(5, "Reona");
    printUnorderedMap(m1);

    m1.erase(3);
    m1.erase(m1.begin());
    cout << "new Map: " << endl;
    printUnorderedMap(m1);
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