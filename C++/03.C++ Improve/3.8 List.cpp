#include<iostream>
using namespace std;
#include<list>
#include<string>
#include<algorithm>

/*
    list（链表）容器 -- 链式存储 
    是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
    链表的组成：链表由一系列“结点”组成
    结点的组成：一个是存储数据元素的“数据域”，另一个是存储下一个结点地址的“指针域”
    
    list的优点：
        采用动态存储分配，不会造成内存浪费和溢出
        链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
    list的缺点：
        链表灵活，但是空间(指针域) 和 时间（遍历）额外耗费较大

    由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于“双向迭代器”
    STL中的链表是双向循环连表，最后一个结点会指向第一个结点的位置，第一个结点的前一个结点会记录最后一个结点的位置
    即链表的迭代器不支持随机访问，所以只能用内置提供的sort算法进行排序

    List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
    总结：STL中List和vector是两个最常被使用的容器，各有优缺点
    1.list构造函数
        list<T> lst;                       // list采用采用模板类实现,对象的默认构造形式：
        list(beg,end);                     // 构造函数将[beg, end)区间中的元素拷贝给本身
        list(n,elem);                      // 构造函数将n个elem拷贝给本身
        list(const list &lst);             // 拷贝构造函数
    2.list赋值和交换
        assign(beg, end);                  // 将[beg, end)区间中的数据拷贝赋值给本身
        assign(n, elem);                   // 将n个elem拷贝赋值给本身
        list& operator=(const list &lst);  //重载等号操作符
        swap(lst);                         //将lst与本身的元素互换
    3.list大小操作
        size();                            //返回容器中元素的个数
        empty();                           //判断容器是否为空
        resize(num);                       //重新指定容器的长度为num，若容器变长，则以默认值0填充新位置
        ​					                //如果容器变短，则末尾超出容器长度的元素被删除
        resize(num, elem);                 //重新指定容器的长度为num，若容器变长，则以elem值填充新位置
                                           //如果容器变短，则末尾超出容器长度的元素被删除
    4.list插入和删除
        push_back(elem);                   //在容器尾部加入一个元素
        pop_back();                        //删除容器中最后一个元素
        push_front(elem);                  //在容器开头插入一个元素
        pop_front();                       //从容器开头移除第一个元素
        insert(pos,elem);                  //在pos位置插elem元素的拷贝，返回新数据的位置
        insert(pos,n,elem);                //在pos位置插入n个elem数据，无返回值
        insert(pos,beg,end);               //在pos位置插入[beg,end)区间的数据，无返回值
        clear();                           //移除容器的所有数据
        erase(beg,end);                    //删除[beg,end)区间的数据，返回下一个数据的位置
        erase(pos);                        //删除pos位置的数据，返回下一个数据的位置
        remove(elem);                      //删除容器中所有与elem值匹配的元素
    5.list数据存取
        front();                           //返回第一个元素
        back();                            //返回最后一个元素
        链表不是连续空间，不能通过at和[]跳跃式访问，迭代器也是不支持随机访问的
    6.list反转和排序
        reverse();                         //反转链表
        sort();                            //链表排序
*/

void printList(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// list构造函数
void test01()
{
    list<int> l1;
    for (int i = 0; i < 10; i++)
    {
        l1.push_back(i);
    }
    printList(l1);

    list<int> l2(++l1.begin(), --l1.end());
    printList(l2);

    list<int> l3(l2);
    printList(l3);

    list<int> l4(4, 100);
    printList(l4);
}

// list 赋值和交换
void test02()
{
    list<int> l1;
    for (int i = 0; i < 10; i++)
    {
        l1.push_back(i);
    }
    printList(l1);

    list<int> l2;
    l2.assign(++l1.begin(), --l1.end());
    printList(l2);

    list<int> l3;
    l3 = l2;
    printList(l3);

    list<int> l4;
    l4.assign(4, 7);
    printList(l4);

    l1.swap(l4);
    printList(l1);
    printList(l4);
}

// list大小操作
void test03()
{
    list<int> l1;
    for (int i = 0; i < 10; i++)
    {
        l1.push_back(i);
    }
    printList(l1);
    cout << "l1.size() = " << l1.size() << endl;
    cout << "l1.empty() = " << l1.empty() << endl;

    l1.resize(12);
    printList(l1);
    l1.resize(15, 7);
    printList(l1);
}

// list插入和删除 
void test04()
{
    list<int> l1;
    // push_back(elem);  
    for (int i = 0; i < 10; i++)
    {
        l1.push_back(i);
    }       
    printList(l1);

    // push_front(elem);    
    l1.push_front(-1);
    printList(l1);

    // pop_back();   
    l1.pop_back();
    printList(l1);

    // pop_front();  
    l1.pop_front();
    printList(l1);

    // insert(pos,elem);  
    l1.insert(++(++l1.begin()), 0);
    printList(l1);

    // insert(pos,n,elem); 
    l1.insert(++(++l1.begin()), 3, 0);
    printList(l1);

    // insert(pos,beg,end); 
    list<int> l2;
    l2.push_back(77);
    l2.push_back(77);
    l1.insert(++(++(++l1.begin())), l2.begin(), l2.end());
    printList(l1);
    
    // erase(pos);   
    l1.erase(++(++l1.begin()));
    printList(l1);

    // erase(beg,end); 
    list<int>::iterator it = l1.begin();
    for (int i = 0; i < 4; i++)
    {
        it++;
    }
    l1.erase(++(++l1.begin()),it);
    printList(l1);

    // remove(elem);
    l1.remove(0);
    printList(l1);

    // clear();                          
    l1.clear();
    printList(l1);
}

// list数据存取
void test05()
{
    list<int> l1;
    for (int i = 0; i < 10; i++)
    {
        l1.push_back(i*2);
    }       
    printList(l1);
    // l1[0],l1.at(0)均无法访问
    cout << "l1.front() = " << l1.front() << endl;
    cout << "l1.back() = " << l1.back() << endl;
    // 验证迭代器不支持随机访问
    list<int>::iterator it = l1.end();
    // l1.end()为最后一个元素后的一个结点，会保存变量个数
    // it = it + 1;   // 报错，不支持随机访问
    it--;             // 只能一个一个加着走
    cout << "it-- = " << *it << endl;    
    it++;
    cout << "it++ = " << *it << endl; 
}


// list反转和排序
bool myCompare(int v1, int v2)   // 降序仿函数
{
    // 降序 就让第一个数 > 第二个数
    return v1 > v2;
}
void test06()
{
    list<int> l1;
    for (int i = 0; i < 10; i++)
    {
        l1.push_back(i);
    }      
    // reverse(); 
    printList(l1);
    l1.reverse();
    printList(l1);

    // sort();
    list<int> l2;
    l2.push_back(1);
    l2.push_back(6);
    l2.push_back(3);
    l2.push_back(2);
    l2.push_back(5);
    l2.push_back(4);
    l2.push_back(0);
    // sort(l2.begin(), l2.end());   
    // 报错，所有不支持随机访问的迭代器不可以用标准算法
    // 不支持随机访问的迭代器的容器内部会提供对应的一些算法
    l2.sort();   // 需要利用list容器的成员函数来排序
    printList(l2);
    // 利用仿函数降序
    l2.sort(myCompare);
    printList(l2);
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