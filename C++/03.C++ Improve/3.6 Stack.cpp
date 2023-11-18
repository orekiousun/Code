#include<iostream>
using namespace std;
#include<stack>

/*
    stack（栈）容器 -- 先进后出
    栈中进入数据称为  --- 入栈  push
    栈中弹出数据称为  --- 出栈  pop
    栈不允许有遍历的行为：只有栈顶元素才能被看到，如果想看到后面的元素，需要把栈顶元素拿出去
    1.stack常用接口
    构造函数
        stack<T> stk;                         //stack采用模板类实现， stack对象的默认构造形式
        stack(const stack &stk);              //拷贝构造函数
    赋值操作：
        stack& operator=(const stack &stk);   //重载等号操作符
    数据存取：
        push(elem);                           //向栈顶添加元素
        pop();                                //从栈顶移除第一个元素
        top();                                //返回栈顶元素
    大小操作：
        empty();                              //判断堆栈是否为空
        size();                               //返回栈的大小
*/

// 构造，赋值及数据存取
void test01()
{
    stack<int> s1;
    for (int i = 0; i < 10; i++)
    {
        s1.push(i);
    }
    cout << "s1.top() = " << s1.top() << endl; 

    stack<int> s2(s1);
    s2.pop();
    cout << "s2.top() = " << s2.top() << endl;

    stack<int> s3;
    s3 = s2;
    cout << "s3.top() = " << s3.top() << endl;
}

// 大小操作
void test02()
{
    stack<int> s1;
    for (int i = 0; i < 10; i++)
    {
        s1.push(i);
    }
    cout << "s1.empty() = " << s1.empty() << endl;
    cout << "s1.size() = " << s1.size() << endl;
    stack<int> s2;
    cout << "s2.empty() = " << s2.empty() << endl;

    // 只要栈不为空，就查看栈顶元素并出栈
    while(!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
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