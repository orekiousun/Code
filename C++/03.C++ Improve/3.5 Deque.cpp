#include<iostream>
using namespace std;
#include<string>
#include<deque>
#include<algorithm>

/*
    deque容器
    1.基本概念：
        双端数组，可以对头端进行插入删除操作
    deque与vector区别：
        vector对于头部的插入删除效率低，数据量越大，效率越低
        deque相对而言，对头部的插入删除速度会比vector快
        vector访问元素时的速度会比deque快,这和两者内部实现有关
        deque容器的迭代器也是支持随机访问的
    deque内部工作原理:
        deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据
        中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
    2.deque的构造函数
        deque<T> deqT;                        //默认构造形式
        deque(beg, end);                      //构造函数将[beg, end)区间中的元素拷贝给本身
        deque(n, elem);                       //构造函数将n个elem拷贝给本身
        deque(const deque &deq);              //拷贝构造函数
    3.deque的赋值操作
        deque& operator=(const deque &deq);   //重载等号操作符
        assign(beg, end);                     //将[beg, end)区间中的数据拷贝赋值给本身
        assign(n, elem);                      //将n个elem拷贝赋值给本身
    4.deque大小操作
        deque.empty();                        //判断容器是否为空
        deque.size();                         //返回容器中元素的个数
        deque.resize(num);                    //重新指定容器的长度为num,若容器变长，则以默认值填充新位置
        ​			                           //如果容器变短，则末尾超出容器长度的元素被删除
        deque.resize(num, elem);              //重新指定容器的长度为num,若容器变长，则以elem值填充新位置
        ​                                      //如果容器变短，则末尾超出容器长度的元素被删除
    5.插入和删除
    两端插入操作：
        push_back(elem);          //在容器尾部添加一个数据
        push_front(elem);         //在容器头部插入一个数据
        pop_back();               //删除容器最后一个数据
        pop_front();              //删除容器第一个数据
    指定位置操作：
        insert(pos,elem);         //在pos位置插入一个elem元素的拷贝，返回新数据的位置，其中pos为一个迭代器
        insert(pos,n,elem);       //在pos位置插入n个elem数据，无返回值
        insert(pos,beg,end);      //在pos位置插入[beg,end)区间的数据，无返回值
        clear();                  //清空容器的所有数据
        erase(beg,end);           //删除[beg,end)区间的数据，返回下一个数据的位置
        erase(pos);               //删除pos位置的数据，返回下一个数据的位置
    6.deque数据存取
        at(int idx);              //返回索引idx所指的数据
        operator[];               //返回索引idx所指的数据
        front();                  //返回容器中第一个数据元素
        back();                   //返回容器中最后一个数据元素
    7.排序操作
        sort(iterator beg, iterator end)  // 对beg和end区间内元素进行排序
                                          // 需要包含标准算法头文件 -- #include<algorithm>
        对于支持随机访问的迭代器，都可以利用sort算法直接对其进行排序，vector容器也可以利用sort排序

*/

void printDeque(const deque<int> &d)   // 加入const可以防止后面修改deque容器中内容，同时下面的迭代器改为const_iterator
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end() ; it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 构造函数
void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3(4, 100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);
}

// 赋值操作
void test02()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    
    deque<int> d2;
    d2 = d1;
    printDeque(d2);

    deque<int> d3;
    d3.assign(d2.begin(), d2.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(4, 100);
    printDeque(d4);
}

// 大小操作
void test03()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    cout << "d1.empty() = " << d1.empty() << endl;
    cout << "d1.size() = " << d1.size() << endl;
    d1.resize(12);
    printDeque(d1);
    d1.resize(15, 100);
    printDeque(d1);
}

// 插入和删除
void test04()
{
    deque<int> d1;
    // 头插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_back(40);
    d1.push_back(50);
    printDeque(d1);
    // 尾插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    // 头删
    d1.pop_back();
    printDeque(d1);
    // 尾删
    d1.pop_front();
    printDeque(d1);
    // insert(pos,elem);
    d1.insert(d1.begin(), 888);
    printDeque(d1);
    // insert(pos,n,elem); 
    d1.insert(d1.begin(), 2, 777);
    printDeque(d1);
    // insert(pos,beg,end); 
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.end(), d2.begin(), d2.end());
    printDeque(d1);    
    // erase(beg,end);    
    d2.erase(++d2.begin(), d2.end());
    printDeque(d2);         
    // erase(pos);    
    d1.erase(++(++d1.begin()));
    printDeque(d1);         
    // clear(); 
    d1.clear();
    printDeque(d1);  
}

// 数据存取
void test05()
{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(10);
    d1.push_back(2);
    d1.push_back(22);
    d1.push_back(7);
    d1.push_back(77);
    d1.push_front(5);
    d1.push_front(55);
    d1.push_front(555);
    printDeque(d1);
    cout << "d1.at(4) = " << d1.at(4) << endl;
    cout << "d1[4] = " << d1[6] << endl;
    cout << "d1.front() = " << d1.front() << endl;
    cout << "d1.back() = " << d1.back() << endl;
}

void test06()
{
    deque<int> d;
    d.push_front(8);
    d.push_front(4);
    d.push_front(6);
    d.push_front(2);
    d.push_front(5);
    d.push_front(3);
    d.push_front(0);
    d.push_front(1);
    d.push_front(7);
    d.push_front(9);
    printDeque(d);
    sort(d.begin(), d.end());
    printDeque(d);
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