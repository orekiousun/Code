#include<iostream>
using namespace std;
#include<queue>

/*
    queue（队列）容器 -- 先进先出
    队列容器允许从一端新增元素，从另一端移除元素
    队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
    队列中进数据称为 --- 入队    push
    队列中出数据称为 --- 出队    pop
    构造函数：
        queue<T> que;                         //queue采用模板类实现，queue对象的默认构造形式
        queue<T>(const queue &que);              //拷贝构造函数
    赋值操作：
        queue& operator=(const queue &que);   //重载等号操作符
    数据存取：
        push(elem);                           //往队尾添加元素
        pop();                                //从队头移除第一个元素
        back();                               //返回最后一个元素
        front();                              //返回第一个元素
    大小操作：
        empty();                              //判断堆栈是否为空
        size();                               //返回栈的大小 

*/
// 构造，赋值及数据存取
void test01()
{
    queue<int> q1;
    for (int i = 0; i < 10; i++)
    {
        q1.push(i);
    }
    cout << "q1.front() = " << q1.front() << endl;
    cout << "q1.back() = " << q1.back() << endl;
    queue<int> q2(q1);
    q2.pop();   // 去掉0
    cout << "q2.front() = " << q2.front() << endl;
    cout << "q2.back() = " << q2.back() << endl;
    queue<int> q3;
    q3 = q2; 
    q3.pop();   // 去掉1
    q3.pop();   // 去掉2
    cout << "q3.front() = " << q3.front() << endl;
    cout << "q3.back() = " << q3.back() << endl;
}

// 大小操作
void test02()
{
    queue<int> q1;
    for (int i = 0; i < 10; i++)
    {
        q1.push(i);
    }
    cout << "q1.size() = " << q1.size() << endl;
    while(!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
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