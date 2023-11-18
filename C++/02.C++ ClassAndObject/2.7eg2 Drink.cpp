#include<iostream>
using namespace std;
#include<string>

// 多态案例2：制作饮品
/*
    制作饮品的大致流程为：煮水 - 冲泡 - 倒入杯中 - 加入辅料
    利用多态技术实现，提供抽象制作饮品基类，提供子类制作咖啡和茶叶 
    冲咖啡：煮水->冲泡咖啡->倒入杯中->加糖和牛奶
    冲茶叶：煮水->冲泡茶叶->倒入杯中->加柠檬
*/


class AbstractDrink
{
public:
    virtual void Boil() = 0;   // 煮水
    virtual void Brew() = 0;   // 冲泡
    virtual void Pour() = 0;   // 倒入杯中
    virtual void PutSomething() = 0;   // 加佐料
    void makeDrink()   // 整合
    {
        Boil();
        Brew();
        Pour();
        PutSomething();
    }
};
class Coffee:public AbstractDrink
{
    void Boil()
    {
        cout << "Boil water" << endl;
    }
    void Brew()
    {
        cout << "Brew coffee" << endl;
    }
    void Pour()
    {
        cout << "Pour in cup" << endl;
    }
    void PutSomething()
    {
        cout << "put in sugar and milk" << endl;
    }
};
class Tea:public AbstractDrink
{
    void Boil()
    {
        cout << "Boil water" << endl;
    }
    void Brew()
    {
        cout << "Brew tea" << endl;
    }
    void Pour()
    {
        cout << "Pour in cup" << endl;
    }
    void PutSomething()
    {
        cout << "put in lemon" << endl;
    }
};
void doWork(AbstractDrink* abs)
{
    abs->makeDrink();
    delete abs;   // 上面传参传入的是堆区的数据，需要手动释放
}
void test01()
{
    cout << "[ make coffee ]" << endl;
    doWork(new Coffee);   // AbstractDrink* abs = new Coffee
    cout << "[ make tea ]" << endl;
    doWork(new Tea);   // AbstractDrink* abs = new Tea

}
int main()
{
    cout << "------------ test01 ------------" << endl;
    test01();
    system("pause");
    return 0;
}