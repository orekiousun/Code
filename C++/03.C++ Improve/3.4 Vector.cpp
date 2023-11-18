#include<iostream>
using namespace std;
#include<string>
#include<vector>

/*
    vector容器
    1.vector基本概念
    功能：vector数据结构和数组非常相似，也称为单端数组
    不同：数组是静态空间，vector可以动态扩展
    动态扩展：并不是在原空间后接新空间，而是找一块更大的空间，将原数据拷贝新空间，释放原空间
    vector容器的迭代器是支持随机访问的迭代器
    2.vector构造函数
        vector<T> v;              		       //采用模板实现类实现，默认构造函数
        vector(v.begin(), v.end());            //将v[begin(), end())区间中的元素拷贝给本身
        vector(n, elem);                       //构造函数将n个elem拷贝给本身
        vector(const vector &vec);             //拷贝构造函数
        vector<int> height{1,8,6,2,5,4,8,3,7}; //快速为容器赋多个值
    3.赋值操作
        vector& operator=(const vector &vec);  //重载等号操作符
        assign(beg, end);                      //将[beg, end)区间中的数据拷贝赋值给本身，注意区间左闭右开
        assign(n, elem);                       //将n个elem拷贝赋值给本身
    4.vector容量和大小
        empty();                              //判断容器是否为空
        capacity();                           //容器的容量
        size();                               //返回容器中元素的个数
        resize(int num);                      //重新指定容器的长度为num，若容器变长，则以默认值0填充新位置。
  ​					                           //如果容器变短，则末尾超出容器长度的元素被删除
        resize(int num, elem);                //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
  ​				                               //如果容器变短，则末尾超出容器长度的元素被删除
    5.vector插入和删除
        push_back(ele);                                    //尾部插入元素ele
        pop_back();                                        //删除最后一个元素
        insert(const_iterator pos, ele);                   //迭代器指向位置pos插入元素ele
        insert(const_iterator pos, int count,ele);         //迭代器指向位置pos插入count个元素ele
        erase(const_iterator pos);                         //删除迭代器指向的元素
        erase(const_iterator start, const_iterator end);   //删除迭代器从start到end之间的元素
        clear();                                           //删除容器中所有元素
    6.vector数据存取
        at(int idx);                          //返回索引idx所指的数据
        operator[];                           //返回索引idx所指的数据
        front();                              //返回容器中第一个数据元素
        back();                               //返回容器中最后一个数据元素
    7.互换容器
        swap(vec);                            // 将vec与本身的元素互换
    8.预留空间
        reserve(int len);                     // 容器预留len个元素长度，预留位置不初始化，元素不可访问，不会有初始值，只是分配了内存
    9.快速访问vector内元素
        vector<int> nums(10, 0);
        for(int num : nums) {
            num = xxx;
        }
*/

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;   
}

// 构造函数
void test01()
{
    // 默认构造 无参构造
    vector<int> v1;   
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 通过区间的方式构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // 将n个elem拷贝给本身
    vector<int> v3(4, 1);
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

// 赋值操作
void test02()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int>v4;
    v4.assign(8, 8);
    printVector(v4);
}

// vector容量和大小
void test03()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    if (v1.empty())
    {
        cout << "v1为空"  << endl;
    }
    else
    {
        cout << "v1为不为空"  << endl;
        cout << "v1的容量为：" << v1.capacity() << endl;
        cout << "v1的大小为：" << v1.size() << endl;
    }
    v1.resize(15);        // 默认用0填充
    printVector(v1);
    v1.resize(18, 100);   // 指定用100填充
    printVector(v1);
    v1.resize(5);         // 变短会直接删除
    printVector(v1);
}

// vector插入和删除
void test04()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        // push_back(ele);                                    
        v1.push_back(i);
    }
    printVector(v1);

    // pop_back(); 
    v1.pop_back();
    printVector(v1);

    // insert(const_iterator pos, ele); 
    v1.insert(v1.begin(), 100);
    printVector(v1);

    // insert(const_iterator pos, int count,ele);
    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // erase(const_iterator pos); 
    v1.erase(v1.begin());
    printVector(v1);

    // erase(const_iterator start, const_iterator end);
    vector<int>::iterator it = ++(++(++v1.begin()));
    v1.erase(it, v1.end());
    printVector(v1);

    // clear(); 
    v1.clear();
    printVector(v1);
}

// vector数据存取
void test05()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    cout << "v1[3] = " << v1[8]<< endl;            // 利用中括号访问
    cout << "v1.at(3) = " << v1.at(3) << endl;     // 利用at访问
    cout << "v1.front() = " << v1.front() << endl;
    cout << "v1.back() = " << v1.back() << endl;
}

// 互换容器
void test06()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(9 - i);
    }
    cout << "交换前：" << endl;
    cout << "v1：";
    printVector(v1);
    cout << "v2：";
    printVector(v2);
    v1.swap(v2);
    cout << "交换后：" << endl;
    cout << "v1：";
    printVector(v1);
    cout << "v2：";
    printVector(v2);
    
    // 实际用途
    // 巧用swap可以收缩内存空间
    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
    }
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
    v.resize(3);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;   
    // 重新指定大小后容量不变，浪费内存
    // 利用swap收缩内存
    vector<int>(v).swap(v);
    // vector<int>(v)为匿名对象，利用v创建了一个新的匿名对象，会按照v所用的元素个数初始化容器容量和大小
    // 再将这个匿名对象和原对象交换，使原对象的大小和容量匹配
    // 该行执行完之后，编译器会回收匿名对象，所以原来那个空间很大的对象被编译器直接回收
    cout << "巧用swap后；" << endl;
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl; 
}

// 预留空间
void test07()
{
    vector<int> v1;
    int num = 0;  
    int* p = NULL;
    for (int i = 0; i < 100; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])   // 统计内存重新开辟次数
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "num = " << num << endl;

    // 提前预留好空间
    vector<int> v2;
    v2.reserve(100);
    num = 0;  
    p = NULL;
    for (int i = 0; i < 100; i++)
    {
        v2.push_back(i);
        if (p != &v2[0])   // 统计内存重新开辟次数
        {
            p = &v2[0];
            num++;
        }
    }
    cout << "num = " << num << endl;
    // 提前预留好空间发现只会重新开辟一次
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
    // cout << "------------ test08 ------------" << endl;
    // test08();
    system("pause");
    return 0;
}