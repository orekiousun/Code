#include<iostream>
using namespace std;
#include<map>
/*
    map图容器
        map中所有元素都是pair
        pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
        所有元素都会根据元素的键值自动排序
    map/multimap属于关联式容器，底层结构是用二叉树实现
    优点：可以根据key值快速找到value值
    map和multimap的区别
        map不允许容器中有重复key值元素
        multimap允许容器中有重复key值元素
    1.map构造和赋值
    构造
        map<T1, T2> mp;                  //map默认构造函数:
        map(const map &mp);              //拷贝构造函数
    赋值
        map& operator=(const map &mp);   //重载等号操作符
    2.map大小和交换
        size();                          //返回容器中元素的数目
        empty();                         //判断容器是否为空
        swap(st);                        //交换两个集合容器
    3.map插入和删除
        insert(elem);                    //在容器中插入元素
        clear();                         //清除所有元素
        erase(pos);                      //删除pos迭代器所指的元素，返回下一个元素的迭代器
        erase(beg, end);                 //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
        erase(key);                      //删除容器中key值为key的元素
    4.map查找和统计
        find(key);                       //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
        count(key);                      //统计key的元素个数
    5.map排序
        利用仿函数，可以改变排序规则

*/
void printMap(const map<int, int> &m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key: " << it->first << "\tvalue: " << it->second << endl;
    }
    cout << "----- 分隔符 -----" << endl;
}
// map构造和赋值
void test01()
{
    map<int, int> m1;   // 注意模板类要写两个数据类型
    m1.insert(pair<int, int>(3, 30));   // 创建匿名对组，注意对组书写形式
    m1.insert(pair<int, int>(1, 10));   
    m1.insert(pair<int, int>(2, 20));   
    m1.insert(pair<int, int>(2, 20));   
    // 会按照key排序
    printMap(m1);

    map<int, int> m2(m1);
    printMap(m2);

    map<int, int> m3;
    m3 = m1;
    printMap(m3);
}

// map大小和交换
void test02()
{
    map<int, int> m1;   
    m1.insert(pair<int, int>(3, 30));   
    m1.insert(pair<int, int>(1, 10));   
    m1.insert(pair<int, int>(2, 20));   
    m1.insert(pair<int, int>(2, 20));   
    cout << "m1.size() = " << m1.size() << endl;
    cout << "m1.empty() = " << m1.empty() << endl;
    
    map<int, int> m2;
    m2.insert(pair<int, int>(4,400));
    m2.insert(pair<int, int>(2,200));
    m2.insert(pair<int, int>(1,100));
    m2.insert(pair<int, int>(3,300));
    cout << "交换前：" << endl;
    printMap(m1);
    printMap(m2);
    cout << "交换后：" << endl;
    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}

// map插入和删除
void test03()
{
    map<int, int> m1;   
    // 四种插入方式
    m1.insert(pair<int, int>(3, 30));   
    m1.insert(make_pair(1, 10));   
    m1.insert(map<int , int>::value_type(2, 20));   // 比较麻烦，不建议使用
    m1[4] = 40;   // 不建议用于插入，可以利用key访问value
    cout << m1[5] << endl;   // 会发现虽然没有插入key5，但一旦通过[]访问到5，就会自动赋值value0进去，产生一个新的键值对

    m1.erase(m1.begin());
    printMap(m1);
    m1.erase(2);
    printMap(m1);
    m1.insert(pair<int, int>(3, 30));   
    m1.insert(pair<int, int>(1, 10));   
    m1.insert(pair<int, int>(2, 20));   
    m1.insert(pair<int, int>(2, 20)); 
    m1.erase(m1.begin(), --(--m1.end()));
    printMap(m1);
    m1.clear();
    printMap(m1);
}

// 查找和统计
void test04()
{
    
    map<int, int> m1;   
    m1.insert(pair<int, int>(3, 30));   
    m1.insert(pair<int, int>(1, 10));   
    m1.insert(pair<int, int>(2, 20));   
    m1.insert(pair<int, int>(2, 20)); 
    cout << "m1.find(1) = " << (*m1.find(1)).second << endl;
    cout << "m1.find(5) = " << (*m1.find(5)).second << endl;   // 不存在5的键值，返回的默认值为0
    // 由于map不允许插入重复的key，所以count的返回值只能为1或0
    cout << "m1.count(5) = " << m1.count(5) << endl;
    cout << "m1.count(1) = " << m1.count(1) << endl;
}

class Mycompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void test05()
{
    map<int, int, Mycompare>m;
    m.insert(pair<int, int>(1, 60));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(3, 30));

    for (map<int, int, Mycompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key: " << it->first << "\tvalue: " << it->second << endl;
    }
    
}

void test06()
{
    
}

void test07()
{
    
}

void test08()
{
    
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
    cout << "------------ test08 ------------" << endl;
    test08();
    system("pause");
    return 0;
}