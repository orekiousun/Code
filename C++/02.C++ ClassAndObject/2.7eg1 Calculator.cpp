#include<iostream>
using namespace std;
#include<string>

// 多态案例1：计算器
// 分别利用普通写法和多态技术实现计算器
// 利用普通类实现计算器
/*
    多态的好处：
    1）组织结构清晰
    2）可读性强
    3）有利于前期后后期的维护，可以方便添加模块

*/
class Calculator
{
public:
    int getResult(string oper)
    {
        if(oper == "+") return Num1 + Num2;
        else if(oper == "-") return Num1 - Num2;
        else if(oper == "*") return Num1 * Num2;
        // 如果想扩展新的功能，需要修改源码
        // 在真实的开发中，提倡 开闭原则：对扩展进行开放，对修改进行关闭
        else return -1;
    }
    int Num1;
    int Num2;
};

// 利用多态实现计算器
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int Num1;
    int Num2;
};
class AddCalculator:public AbstractCalculator
{
    // 子类重写父类中虚函数
    int getResult()
    {
        return Num1 + Num2;
    }
};
class SubCalculator:public AbstractCalculator
{
    // 子类重写父类中虚函数
    int getResult()
    {
        return Num1 - Num2;
    }
};
class MulCalculator:public AbstractCalculator
{
    // 子类重写父类中虚函数
    int getResult()
    {
        return Num1 * Num2;
    }
};

void test01()
{
    // 创建一个计算器对象
    Calculator c;
    c.Num1 = 10;
    c.Num2 = 10;
    cout << c.Num1 << " + " << c.Num2 << " = " << c.getResult("+") << endl;
    cout << c.Num1 << " - " << c.Num2 << " = " << c.getResult("-") << endl;
    cout << c.Num1 << " * " << c.Num2 << " = " << c.getResult("*") << endl;
}
void test02()
{
    // 创建一个计算器对象
    AbstractCalculator *c = new AddCalculator;
    c->Num1 = 100;
    c->Num2 = 100;
    cout << c->Num1 << " + " << c->Num2 << " = " << c->getResult() << endl;
    // 用完后记得销毁
    delete c;   // 只是销毁了该指针中的数据，数据类型仍然为指针，在下面可以重定义
    c = new SubCalculator;
    c->Num1 = 100;
    c->Num2 = 10;
    cout << c->Num1 << " - " << c->Num2 << " = " << c->getResult() << endl;
    delete c;   // 只是销毁了该指针中的数据，数据类型仍然为1指针，在下面可以重定义
    c = new MulCalculator;
    c->Num1 = 10;
    c->Num2 = 5;
    cout << c->Num1 << " * " << c->Num2 << " = " << c->getResult() << endl;
    delete c;
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