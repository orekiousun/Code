#include<iostream>
using namespace std;
#include<queue>
#include<functional>
#include<ctime>

/*
    priority_queue（优先队列）容器 -- 先进先出
    具有队列的所有特性，在队列的基础上添加了一个内部的排序，本质是利用堆是实现的

    priority_queue<Type, Container, Functional>
    Type - 数据类型
    Container - 容器类型vector，deque等，不能用ilst这样的不支持随机访问的容器
    Functional - 自定义数据类型时的比较函数
    构造函数：
        priority_queue<Type, Container, Functional> que;    //默认构造形式
    数据存取：
        push(elem);                           //往队尾添加元素，并排序
        pop();                                //从队头移除第一个元素
        top();                                //返回第一个元素
        emplace(elem);                        //原地构造一个元素并插入队列
        // emplace接受新对象的时候，自己会调用其构造函数生成对象然后放在容器内，push是将数据造好之后在复制一遍放入队列中
        swap();                               //将优先队列的元素与具有相同类型和大小的另一个队列交换
    大小操作：
        empty();                              //判断堆栈是否为空
        size();                               //返回栈的大小 
*/


void test01()
{
    priority_queue<int> q;   // 创建大顶堆
    // 等同于priority_queue<int, vector<int>, less<int>> q;
    for (int i = 0; i < 5; i++)
    {
        q.push(rand() % 100);
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}



int main()
{
    srand((unsigned int)time(NULL));
    cout << "------------ test01 ------------" << endl;
    test01();
    system("pause");
    return 0;
}