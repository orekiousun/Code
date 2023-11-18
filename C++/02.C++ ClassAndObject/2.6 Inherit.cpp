#include<iostream>
using namespace std;
#include<string>

/*
    继承：面向对象的三大特性之一
    好处：可以减少重复的代码
    1.基本语法 
        class 子类名: 继承方式 父类
        {
            // 此处写类的定义（成员变量，成员函数等）
        }
        // 子类也称为派生类，父类也称为基类
        派生类中包含两大部分，一类是从基类继承过来的，一类是自己增加的成员
        从基类继承过来的表现其共性，而新增的成员体现其个性
    2.继承方式
        1）公共继承
            父类中的公共权限内容和保护权限内容在子类中也相应的变为公共权限内容和保护权限内容，无法继承私有权限内容
            公共权限->公共权限 保护权限->保护权限 私有权限->无法继承
        2）保护继承
            父类中的公共权限内容和保护权限内容在子类中均变为保护权限内容，无法继承私有权限内容
            公共权限，保护权限->保护权限 私有权限->无法继承
        3）私有继承
            父类中的公共权限内容和保护权限内容在子类中均变为私有权限内容，无法继承私有权限内容
            公共权限，保护权限->私有权限 私有权限->无法继承
    3.继承中的对象模型
        通过sizeof打印大小可以发现，父类中私有的成员属性也会被继承下去，但是被编译器隐藏了，因此访问不到
    4.继承中的构造和析构顺序：子类继承父类时，当创建子类对象时，也会调用父类的构造函数，需要探讨的是父类和子类的构造和析构顺序
        先进行父类构造，再进行子类构造，再执行子类的析构，再执行父类的析构，析构顺序与构造顺序相反
    5.继承中同名成员的处理方法
            访问子类同名成员：直接访问即可
            访问父类同名成员：需要加作用域
    函数的调用同理，但是如果子类中出现了与父类同名的成员函数，那么子类中的同名成员函数会隐藏掉父类中所有的同名的成员函数（包括被重载后的成员函数）
    只能通过加作用域调用父类中的成员函数
    6.继承中同名的静态成员的处理方法：静态成员和非静态成员出现同名的处理方式一致
        访问子类同名成员：直接访问即可
        访问父类同名成员：需要加作用域
    如果子类中出现了与父类同名的静态成员函数，那么子类中的同名静态成员函数会隐藏掉父类中所有的同名的静态成员函数（包括被重载后的静态成员函数）
    大多数时候同非静态，只是注意静态成员变量需要初始化，并且由于所有类共享一个静态成员，所以可以通过类名（作用域）直接访问
    7.多继承语法： C++允许一个类继承多个类
        class 子类: 继承方式 父类1, 继承方式 父类2 ...
    注意：多继承可能会引发父类中有同名成员出现，需要加作用域区分，实际开发中不建议使用多继承
    如果几个不同的父类中有相同的成员变量，则访问时会出现不明确的问题（会出现二义性），要加上作用
    8.菱形继承/钻石继承：两个派生类继承同一个基类，又有某个类同时继承两个派生类
        解决方法：利用虚继承解决菱形继承的问题，在继承时加上virtual关键字
        class Sheep:virtual public Animal{};
*/
// 基本语法
class BasePage
{
public:
    void header()
    {
        cout << "header()" << endl;
    }
    void footer()
    {
        cout << "footer()" << endl;
    }
    void left()
    {
        cout << "left()" << endl;
    }   
};
class Java: public BasePage
{
public:
    void content()
    {
        cout << "Java content" << endl;
    }
};
class Python: public BasePage
{
public:
    void content()
    {
        cout << "Python content" << endl;
    }
};
void test01()
{
    Java p1;
    p1.header();
    p1.footer();
    p1.left();
    p1.content();
    Python p2;
    p2.header();
    p2.footer();
    p2.left();
    p2.content();
}


// 继承方式
class Base1
{
public:
    int a;
protected:
    int b;
private:
    int c;
};
class Base1Son1:public Base1
{
public:
    void func()
    {
        a = 10;
        b = 10;   // 父类中保护权限的和公共权限的成员均可以访问
        // c = 10;   // 程序报错，无法访问
    }
};
class Base1Son2:protected Base1
{
public:
    void func()
    {
        a = 10;
        b = 10;
        // c = 200;   // 程序报错，无法访问
    }
};
class Base1Son3:private Base1
{
public:
    void func()
    {
        a = 10;
        b = 10;
        // c = 10;   // 程序报错，无法访问
    }
};
class GrandBase1Son2:public Base1Son2
{
public:
    void func()
    {
        a = 100;
        b = 100;   // 程序没有报错，说明Son2中的a，b从Base1中继承过来均为保护权限
    }
};
class GrandBase1Son3:public Base1Son3
{
public:
    void func()
    {
        // a = 100;
        // b = 100;   // 程序报错，无法访问
        // Son3中的a，b从Base1中继承过来均为私有权限
    }
};
void test02()
{
    Base1Son1 s1;
    s1.a = 100;
    // s1.b = 200;   // 程序报错，Son1从Base1中继承过来的a为公共权限，类外可以访问，但是b为保护权限，类外无法访问
    Base1Son2 s2;
    // s2.a = 100;
    // s2.b = 200;   // 程序报错，Son2从Base1中继承过来的a,b均为保护权限，类外无法访问
    Base1Son3 s3;
    // s3.a = 10;
    // s3.b = 10;   // 程序报错，Son2从Base1中继承过来的a,b均为私有权限，类外无法访问
    GrandBase1Son2 gs2;
    // gs2.a = 10;
    // gs2.b = 10;   // 程序报错，类外无法访问保护权限内容，说明Son2中的a，b从Base1中继承过来均为保护权限
}


//继承中的对象模型
class Base2
{
public:
    int a;
protected:
    int b;
private:
    int c;
};
class Base2Son1:public Base2
{
public:
    int d;
};
void test03()
{
    cout << "sizeof(Base2Son1) = " << sizeof(Base2Son1) << endl;
    // 输出结果为16，说明Base2Son1中有四个int类型的对象，说明a, b, c, d均为Base2Son1中的对象
    // 父类中私有的成员属性是被编译器隐藏了，因此访问不到，但是确实被继承下去
}
// 利用开发人员命令提示工具查看对象模型
// 跳转盘符 F:
// 跳转文件路径 cd  ...
// 查看命令 cl /dl reportSingleClassLayout类名 "文件名" 


// 继承中的构造和析构顺序
class Base3
{
public:
    Base3()
    {
        cout << "Base3() use" << endl;
    }
    ~Base3()
    {
        cout << "~Base3() use" << endl;
    }
};
class Base3Son1:public Base3
{
public:
    Base3Son1()
    {
        cout << "Base3Son1() use" << endl;
    }
    ~Base3Son1()
    {
        cout << "~Base3Son1() use" << endl;
    }
};
void test04()
{
    Base3Son1 s1;   
    // 通过打印结果可以发现，先创建父类对象，再创建子类对象，再执行子类的析构，再执行父类的析构
}


// 继承中同名成员的处理方法
class Base4
{
public:
    int a;
    Base4()
    {
        a = 100;
    }
    void func()
    {
        cout << "Base4::func() use" << endl;
    }
    void func(int a)
    {
        cout << "Base4::func(int a) use" << endl;
    }
};
class Base4Son1:public Base4
{
public:
    int a;   // 与父类同名
    Base4Son1()
    {
        a = 200;
    }
    void func()   // 与父类同名
    {
        cout << "Base4Son1::func() use" << endl;
    }
};
void test05()
{
    Base4Son1 s1;
    cout << "s1.a = " << s1.a << endl;   // 直接访问访问出的是自身的
    cout << "s1.Base4::a = " << s1.Base4::a << endl;   // 加作用域访问出来的是父类中的a
    s1.func();
    s1.Base4::func();
    s1.Base4::func(100);
}


// 继承中同名静态成员的处理方法
class Base5
{
public:
    static int a;
    static void func()
    {
        cout << "Base5::func() use" << endl;
    }
};
int Base5::a = 100;   // 注意静态成员一定要初始化
class Base5Son1:public Base5
{
public:
    static int a;
    static void func()
    {
        cout << "Base5Son1::func() use" << endl;
    }
};
int Base5Son1::a = 200;
void test06()
{
    // 通过对象访问：
    Base5Son1 s1;
    cout << "s1.a = " << s1.a << endl; 
    cout << "s1.Base5::a = " << s1.Base5::a << endl; 
    s1.func();
    s1.Base5::func();
    // 通过类名访问
    cout << "Base5Son1::a = " << Base5Son1::a << endl; 
    cout << "Base5::a = " << Base5::a << endl;   // 代表通过类名的方式访问
    cout << "Base5Son1::Base5::a = " << Base5Son1::Base5::a << endl;   // 通过类名的方式访问Base5Son1，再访问Base5作用域下的a
    Base5::func();
    Base5Son1::func();
    Base5Son1::Base5::func();
}


// 多继承（开发中不建议进行多继承）
class Base6
{
public:
    int a;
    Base6()
    {
        a = 100;
    }
};
class Base7
{
public:
    int a;
    Base7()
    {
        a = 200;
    }
};
class Base67Son1:public Base6, public Base7   // 多继承
{
public:
    int c;
    int d;
    Base67Son1()
    {
        c = 300;
        d = 400;
    }
};
void test07()
{
    Base67Son1 s1;
    cout << "sizeof(s1) = " << sizeof(s1) << endl;   // 多继承会面临子类占用空间较大的问题
    cout << "s1.Base6::a = " << s1.Base6::a << ", s1.Base6::a = " << s1.Base6::a << ", s1.c = " << s1.c << ", s1.d = " << s1.d << endl;
    // 如果几个不同的父类中有同名的成员变量，则访问时会出现不明确的问题（会出现二义性），要加上作用域
}


// 菱形继承
// 继承之前，加上关键字virtual变为虚继承
// animal类称为 虚基类
class Animal
{
public:
    int age;
};
class Sheep:virtual public Animal{};
class Camel:virtual public Animal{};
class Alpaca:public Sheep, public Camel{};
void test08()
{
    Alpaca p1;
    // p1.age = 18;   // 程序报错，同时从Camel和Sheep中继承age属性，具有二义性，不明确
    p1.Sheep::age = 18;
    p1.Camel::age = 28;
    // 当菱形继承时，两个父类有相同的数据，需要加以作用域区分
    // 使用虚继承后，发现年龄变为28岁，数据变得只有一个，并且可以利用 p1.age 访问
    // 当前类结构
    /*
    class Alpaca size(12)
        +---
    0   | +---(base class Sheep)
    0   | | (vbptr)   // 这个数据加上下面的偏移量8之后指向age
        | +---
    4   | +---(base class Camel)
    4   | | (vbptr)   // 这个数据加上下面的偏移量4之后指向age
        | +---
        +---
        +--- (virtual base Animal)
    8    | age
        +---
    Alpaca::$vbtable@Sheep@:
    0   | 0
    1   | 8 (Alpacad(Sheep+0)Animal)   // 记录了偏移量为8
    Alpaca::$vbtable@Camel@:
    0   | 0
    1   | 4 (Alpacad(Camel+0)Animal)   // 记录了偏移量为4
        // vbptr代表虚基类指针 virtual base pointer ，指向vbtable（虚基类表），该指针通过记录一个偏移量找到同一个age
    */ // 面试题可能常考
    cout << "p1.Sheep::age = " << p1.Sheep::age << endl;
    cout << "p1.Camel::age = " << p1.Camel::age << endl;
    cout << "p1.age = " << p1.age << endl;
    // 只有一份数据就行，菱形继承导致数据有两份，浪费资源
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