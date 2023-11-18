#include<iostream>
using namespace std;
#include<string>

/*
    模板
        C++另一种编程思想称为模板，主要利用模板技术
        提供两种模板机制：
            函数模板
            类模板
    1.模板的概念
    建立通用的模具，大大提高复用性
    2. 函数模板
    作用：建立一个通用的函数，其返回值类型和形参类型可以不具体制定，用一个虚拟类型来代表
    创建语法：
        template<typename T>
        函数声明或定义
    template -- 声明创建模板
    typename -- 表明其后面的符号是一种数据类型，可用class替代  一般函数模板用typename，类模板用class，但是两种都用class也没有问题
    T -- 通用的数据类型，名称可以替换，通常为大写字母
    注意事项：
        自动类型推导必须推导出一致的数据类型
        模板必须确定出明确的T的数据类型，才可以使用
    3.普通函数与函数模板的区别
        普通函数调用时可以发生自动类型转换（隐式类型转换）
        函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
        如果利用显示指定类型的方式，可以发生隐式类型转换
    建议使用显示指定类的的方式调用函数模板，以此确定通用类型T
    4.普通函数与函数模板调用规则
        1）如果函数模板和普通函数都可以实现，优先调用普通函数
            如果普通函数只有声明，没有实现，依然选择调用普通函数，程序会报错
        2）可以通过空模板参数列表来强调调用的函数模板
        3）函数模板依然可以发生重载
        4）如果函数模板可以产生更好的匹配，优先调用函数模板
    实际开发中，既然出现了函数模板，就不要写普通函数了，容易出现二义性
    5.模板的局限性
        模板并不万能，某些特定数据需要用具体化方式做特殊实现
        具体化实现方式：
            template<> 返回值类型 重载模板函数名(类名 变量名, 类名 变量名, ...)
    学习模板并不是为了写模板，而是为了在STL能够运用系统提供的模板
    6.类模板
    建立一个通用类，类中的成员，数据类型不具体指定，用虚拟的数据类型制定
    template<typename T1, typename T2, ...>
    class 类名
    {
        ...
    };
    7.类模板和函数模板的区别
        1）类模板没有自动类型推导的使用方式
        2）类模板在模板参数列表中可以有默认参数
    8.类模板中成员函数创建时机
    普通类中的成员函数一开始就可以创建
    类模板中的成员函数再调用时才创建
    9.类模板对象做函数的参数
    类模板实例化出对象，向函数传参的方式
    三种传入方式：
        指定传入类型 -- 直接显示对象的数据类型
        参数模板化 -- 将对象中的参数变为模板进行传递
        整个类模板化 -- 将整个对象类型模板化进行传递 
    10.类模板与继承
    注意事项：
        当子类继承的父类是一个类模板时，子类在申明的时候，要指出父类中T的类型
        如果不指定，编译器无法为子类分配内存
        如果想灵活指定出父类中T的类型，子类也需变为类模板
    11.类模板成员函数类外实现
        template<class T1, class T2, ...>
        返回值类型 类名称<T1, T2, ...>::函数名{参数列表}
    12.类模板份文件编写
        解决的问题：类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
        解决方法1：main函数中直接包含.cpp源文件
        解决方法2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，.hpp是约定的名称，并不是强制(ps：写在头文件处)
    13.类模板与友元
        全局函数类内实现 - 直接在类内声明友元即可
        全局函数类外实现 - 需要提前让编译器知道全局函数的存在（非常复杂）
*/

// 模板的建立
void swapInt(int& a, int& b)   // 交换两个整型
{
    int temp = a;
    a = b;
    b = temp;
}
void swapDouble(double& a, double&b)
{
    double temp = a;
    a = b;
    b = temp;
}   // 可以发现swapInt函数和swapDouble函数非常相似
// 可以利用函数模板解决
template<typename T>    // 声明一个模板，告诉编译器T为一个通用数据类型，防止报错
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void func()
{
    cout << "func() use" << endl;
}
void test01()
{
    int a = 10, b = 20;
    swapInt(a, b);
    cout << "a = " << a << " b = " << b << endl;

    // 1. 自动类型推导
    mySwap(a ,b);
    cout << "swap agin" << endl;
    cout << "a = " << a << " b = " << b << endl;

    double c = 1.1, d = 2.2;
    swapDouble(c ,d);
    cout << "c = " << c << " d = " << d << endl;

    // 2.显示指定类型
    mySwap<double>(c, d);   // <>内指定的是T的数据类型
    cout << "swap agin" << endl;
    cout << "c = " << c << " d = " << d << endl;

    // 注意事项：
    // 自动类型推导必须推导出一致的数据类型
    // mySwap(a, c);   // 程序报错，T的数据类型不一致

    // 模板必须确定出明确的T的数据类型，才可以使用
    // func();   // 程序报错，func中没有指定T的类型
    func<int>();   // 可以利用显示指定类型指定T，但意义不大
}

// 普通函数与函数模板的区别
// 1.普通函数可以发生隐式类型转换
// 2.函数模板 用自动类型推导，不会发生隐式类型转换
// 3.函数模板 用显示指定类型，可以发生隐式类型转换
int myAdd01(int a, int b)
{
    return a + b;
}
template<typename T>
int myAdd02(T a, T b)
{
    return a + b;
}
void test02()
{
    int a = 0;
    int b = 20;
    char c = 'c';
    cout << "myAdd01(a, b) = " << myAdd01(a, b) << endl;
    // 普通函数可以发生隐式类型转换
    cout << "myAdd01(a, c) = " << myAdd01(a, c) << endl;   // 会进行一次自动类型转换，转换为对应的ASCII码

    cout << "myAdd02(a, b) = " << myAdd02(a, b) << endl;
    // cout << myAdd02(a, c) << endl;   // 报错，函数模板在自动类型推导时不可以发生隐式类型转换
    cout << "myAdd02(a, C) = " << myAdd02<int>(a, c) << endl;   // 显示指定类型会发生隐式类型转换
}

// 普通函数与函数模板的调用规则
void myPrint(int a, int b)
{
    cout << "common function use" << endl;
}
template<class T>
void myPrint(T a, T b)   
{
    cout << "template function use" << endl;
}
template<class T>
void myPrint(T a, T b, T c)   // 函数模板依然可以发生重载
{
    cout << "overloaded template function use" << endl;
}
void test03()
{
    int a = 10;
    int b  = 20;
    myPrint(a, b);   // 优先调用普通函数
    myPrint<>(a, b);   // 可以通过空模板参数列表来强调调用的函数模板
    myPrint(a, b, a);   // 函数模板依然可以发生重载，并且会优先选择产生更号匹配的模板
    char c1 = 'a', c2 = 'b';
    myPrint(c1, c2);   // 此时普通函数和模板函数都可以调用
    // 但是调用普通函数会进行隐式类型转换，而利用函数模板则不用，更匹配，所以会调用函数模板
}

template<class T>
bool myCompare(T& a, T& b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
class Person
{
public:
    string name;
    int age;
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};
template<> bool myCompare(Person& a, Person& b)
{
    if (a.age == b.age && a.name == b.name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test04()
{
    int a = 10;
    int b = 20;
    bool ret = myCompare(a, b);
    if (ret)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }
    Person p1("Lisa", 19);
    Person p2("Aimer", 24);
    // bool ret = myCompare(p1, p2);   // 程序会报错，编译器不知道Person如何对比
    // 解决方法：
    //    1.运算符重载
    //    2.提供具体化的Person函数重载
    bool ret2 = myCompare(p1, p2);
    if (ret2)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }
}

// 类模板
template<class NameType, class AgeType>
class Person2
{
public:
    NameType name;
    AgeType age;
    Person2(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }
    void showPerson()
    {
        cout << "name = " << this->name << " age = " << this->age << endl;
    }
};
void test05()
{
    Person2<string, int> p1("Lisa", 19);
    p1.showPerson();
}

// 类模板与函数模板的区别
template<class NameType, class AgeType = int>   // 类模板参数列表中可以有默认参数
class Person3
{
public:
    NameType name;
    AgeType age;
    Person3(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }
    void showPerson()
    {
        cout << "name = " << this->name << " age = " << this->age << endl;
    }
};
void test06()
{
    // Person2 p2("Aimer", 19);   // 程序报错，只能用显示指定类型
    Person2<string, int> p1("Aimer", 24);
    p1.showPerson();

    Person3<string> p3("YOASOBI", 17);    // 类模板参数列表中可以有默认参数，其中Person3的AgeType已被默认定义为int类型
    p3.showPerson();
    Person3<string, double> p4("Justin", 21.5);   // 也可以自己传入新的数据类型
    p4.showPerson();
}

// 类模板中成员函数的创建时机
class Person4
{
public:
    void showPerson4()
    {
        cout << "show Person4" << endl;
    }
};
class Person5
{
public:
    void showPerson5()
    {
        cout << "show Person5" << endl;
    }
};
template<class T>
class MyClass 
{
public:
    T obj;
    // 类模板中成员函数
    void func1()
    {
        obj.showPerson4();
    }
    void func2()
    {
        obj.showPerson5();
    }
};   // 可以编译成功，因为没有确定T的属性，没有去调用，因此成员函数也没有创建出来
// 只有在调用时，成员函数才会被创建出来
void test07()
{
    MyClass<Person4>m1;
    m1.func1();
    // m.func2();   // 报错
    MyClass<Person5>m2;
    m2.func2();
}

// 类模板的对象做函数的参数
template<class T1, class T2>
class Person6
{
public:
    T1 name;
    T2 age;
    Person6(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }
    void showPerson()
    {
        cout << "name: " << this->name << "\tage: " << age << endl;
    }
};
// 1.指定传入的类型
void printPerson(Person6<string, int>&p)
{
    p.showPerson();
}
template<class T1, class T2>
// 2.参数模板化
void printPerson2(Person6<T1, T2>&p)
{
    p.showPerson();
    cout << "the datatype of T1: " << typeid(T1).name() << endl;
    cout << "the datatype of T2: " << typeid(T2).name() << endl;
}
// 3.将整个类模板化
template<class T>
void printPerson3(T &p)
{
    p.showPerson();
    cout << "the datatype of T: " << typeid(T).name() << endl;
}
void test08()
{
    Person6<string, int>p1("Lisa", 24);
    printPerson(p1);
    Person6<string, int>p2("Aimer", 18);
    printPerson2(p2);
    Person6<string, int>p3("ikura", 17);
    printPerson3(p3);
}

// 类模板与继承
template<class T>
class Base
{
    T m;
};
class Son:public Base<int>   // 必须指定父类中模板T的类型
{

};
template<class T1, class T2>   // 想灵活指定T的类型，子类也变为类模板
class Son2:public Base<T2>
{
public:
    T1 obj; 
    Son2()
    {
        cout << "the datatype of T1: " << typeid(T1).name() << endl;
        cout << "the datatype of T2: " << typeid(T2).name() << endl;
    }
};
void test09()
{
    Son s1;
    Son2<int, char>S2;
}

// 类模板成员函数类外实现
template<class T1, class T2>
class Person7
{
public:
    T1 name;
    T2 age;
    Person7(T1 name, T2 age);
    void showPerson();
};
template<class T1, class T2>   // 需要重新定义模板
Person7<T1, T2>::Person7(T1 name, T2 age)   // 需要加入模板参数列表
{
    this->name = name;
        this->age = age;
}
template<class T1, class T2>
void Person7<T1, T2>::showPerson()
{
    cout << "name: " << this->name << "\tage: " << age << endl;
}
void test10()
{
    Person7<string, int>p1("YOASOBI", 17);
    p1.showPerson();
}

// 类模板与友元
//通过全局函数打印Person信息
template<class T1,class T2>
class Person8;
template<class T1,class T2>
void printPerson4(Person8<T1, T2>p)   // T1， T2与上面不同
{
    cout << "out of class -- name: " << p.name << "\tage: " << p.age << endl; 
}
template<class T1, class T2>
class Person8
{
    // 全局函数类内实现
    friend void printPerson(Person8<T1, T2>p)
    {
        cout << "name: " << p.name << "\tage: " << p.age << endl; 
    }   // 这是一个全局函数，只是定义和实现都写在了类里面（加上了friend）
    // 全局函数类外实现
    // 需要加一个空模板参数列表 如果全局函数类外实现，需要让编译器提前知道这个函数存在，所以把函数定义写在类定义前
    friend void printPerson4<>(Person8<T1, T2>p);
public:
    Person8(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }
private:
    T1 name;
    T2 age;
};
// 类外实现
void test11()
{
    Person8<string, int>p("yama", 18);
    printPerson(p);
    Person8<string, int>p2("milet", 20);
    printPerson4(p2);
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
    cout << "------------ test09 ------------" << endl;
    test09();
    cout << "------------ test10 ------------" << endl;
    test10();
    cout << "------------ test11 ------------" << endl;
    test11();
    system("pause");
    return 0;
}