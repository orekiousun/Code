#include<iostream>
using namespace std;
#include<string>

/*
    对象的初始化和清理
    1.构造函数和析构函数
        一个对象或者变量没有初始状态，对其使用后果未知
        同样的使用完一个对象或变量，没有及时清理，也会造成一定安全问题
        ·构造函数：主要作用于在创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用
        ·析构函数：主要作用于在对象销毁前系统自动调用，执行一些清理工作
    如果不提供构造和析构函数，编译器会提供，编译器提供的构造和析构函数是空实现
    2.构造函数语法：类名(){}
        1）构造函数没有返回值也不写void
        2）函数名称与类名相同
        3）构造函数可以有参数，因此可以发生重载
        4）程序在调用时会自动调用构造，无须手动调用，而且只会调用一次
    3.析构函数语法：~类名(){}
        1）析构函数没有返回值也不写void
        2）函数名称与类名相同，在名称前面加上~
        3）析构函数不可以有参数，也不能发生重载
        4）程序在对象销毁前会自动调用析构，无须手动调用，而且只会调用一次
    4.构造函数的分类及调用
    两种分类方式：
        按参数分为：有参构造和无参构造（默认构造）
        按类型分为：普通构造和拷贝构造
    三种调用方式：
        括号法
        显示法
        隐式转换法
    5.拷贝构造函数的调用时机：
        ·使用一个已经创建完毕的对象来初始化一个新对象
        ·值传递的方式给函数传值
            void Copy(Person p)
            {

            }
            Person p;
            Copy(p);   // 会调用拷贝构造函数，实参在传给形参时进行了一次拷贝构造
        ·以值方式返回局部对象
            Person Copy()
            {
                Person p;
                return p;
            }
            Person p = Copy();   // 会调用拷贝构造函数，相当于函数外的p对函数内的p进行了一次拷贝
    6.构造函数调用规则
    默认情况下，c++编译器至少给一个类添加3个函数
        1）默认构造函数（无参，函数体为空）
        2）默认析构函数（无参，函数体为空）
        3）默认拷贝构造函数，对属性进行值拷贝
    构造函数调用规则如下：
        ·如果定义有参函数构造，c++不在提供无参构造，但是会提供默认的拷贝构造
        ·如果定义拷贝构造函数，c++不会再提供其他构造函数
    7.深拷贝与浅拷贝（重点）
        浅拷贝：简单的拷贝赋值操作（一般的等号赋值操作都是浅拷贝）
            浅拷贝带来的问题：堆区的内存重复被释放
        深拷贝：在堆区重新申请空间，进行拷贝操作
    8.初始化列表：对类中的属性进行初始化操作
        函数名(数据类型 值1, 数据类型 值2 ... ):属性1(值1), 属性2(值2) ... {}
    9.类对象作为类成员：C++类中的成员可以是另一个类的对象，我们称该成员为对象成员
        当其他类的对象作为本类中的成员时，创建本类的对象时需要先构建其他类的对象，并且先释放本类的对象，再释放其他类的对象
        析构的顺序与构造相反
    10.静态成员：在成员变量和成员函数前加上关键字static，称为静态成员
    分类：
        静态成员变量
            ·所有对象共享同一份数据
            ·在编译阶段分配内存
            ·类内声明，类外初始化
        静态成员函数：
            ·所有对象共享同一函数
            ·静态成员函数只能访问静态成员变量
*/

class Test
{
private:

public:
    Test()   // 构造函数，可以有参数，这里为1个无参构造函数
    {
        cout << "Test() use" << endl;
    }
    ~Test()   // 析构函数。不可以有参数，不能发生重载
    {
        cout << "~Test() use" << endl;
    }
};
void test01()
{
    Test p;   // 构造函数会自动调用
    // 由于p是一个局部变量，保存在栈上，函数运行结束后会自动销毁，所以析构函数也会调用
}


// 构造函数调用规则
class Person
{
private:
    int age;
public:
    Person()   // 无参构造函数，调用时不要加()
    {
        cout << "Person() use" << endl;
    }
    Person(int a)  // 有参构造函数
    {
        age = a;
        cout << "Person(int a) use" << endl;
    }
    Person(const Person& p)   // 拷贝构造函数，注意参数书写形式
    {
        age = p.age;   // 将传入的对象的所有属性拷贝到当前对象上
        cout << "Person(const Person& p) use" << endl;
    }
    ~Person()   // 析构构造函数
    {
        cout << "~Person() use" << endl;
    }
    int getAge()
    {
        return age;
    }
};
// 构造函数的调用方式
void test02()
{
    // 括号法
    Person p1;   // 默认构造函数的调用
    // 注意：调用默认构造函数时，不要加()，如果写 Person p1(); 编译器会认为这是一个函数声明，不会认为在创建对象
    Person p2(10);   // 有参构造函数的括号调用
    Person p3(p2);   // 拷贝构造函数的括号调用
    cout << "p2.age: " << p2.getAge() << endl;
    cout << "p3.age: " << p3.getAge() << endl;

    // 显示法
    Person p4;
    Person p5 = Person(10);   // 相当于在调用有参构造
    Person p6 = Person(p4);
    Person(10);   // 匿名对象 特点：当前行执行结束后，系统会立即回收匿名对象
    cout << "----------" << endl;   // 会发现程序会在该打印前就释放Person(10)
    // 不要利用拷贝构造函数初始化匿名对象
    // Person(p3);   // 程序报错，编译器会认为 Person p3 等价于 Person p3;

    // 隐式转换法
    Person p7 = 10;   // 相当于 Person p7 = Person(10);
    Person p8 = p7;   // 相当于 Person p8 = Person(p7);
}


// 深拷贝与浅拷贝（重点）
class Person2
{
public:
    int age;
    int* Height;   // 指针本质是一个地址，拷贝时拷贝的也是地址
    Person2()   // 无参构造函数，调用时不要加()
    {
        cout << "Person2() use" << endl;
    }
    Person2(int a, int height)  // 有参构造函数
    {
        age = a;
        Height = new int(height);
        cout << "Person2(int a) use" << endl;
    }
    Person2(const Person2& p)   // 拷贝构造函数，注意参数书写形式
    {
        age = p.age;   // 将传入的对象的所有属性拷贝到当前对象上
        // Height = p.Height;   // 浅拷贝
        Height = new int(*p.Height);   // 深拷贝，将p.Height解引用，并重新申请一块空间
        cout << "Person2(const Person2& p) use" << endl;
    }
    ~Person2()   // 析构构造函数
    {
        // 析构代码的用途一般将堆区开辟的数据释放
        if(Height != NULL)
        {
            delete Height;
            Height = NULL;   // 防止野指针的出现 
        } 
        cout << "~Person2() use" << endl;
    }   // 如果要用深拷贝，则无论是有参构造，拷贝函数还是析构函数都要做出相应的操作
};
void test03()
{
    Person2 p1(18, 160);
    cout << "p1.age: " << p1.age << ", *p1.Height: "<< *p1.Height << endl;
    Person2 p2(p1);   // 编译器的拷贝构造函数会做浅拷贝操作
    cout << "p2.age: " << p2.age << ", *p2.Height: "<< *p2.Height << endl;
    // 这里根据栈的释放原则，后进的先释放，则先释放p2，由于p2.Height中记录了一个和p1.Height相同的地址
    // 所以如果析构函数中有delete Height的操作的话，p2会先释放一次对应地址的内容，p1也会释放一次相同地址的内容，导致程序报错
    // 这是浅拷贝的弊端之一
    // 解决办法：进行深拷贝
}


// 初始化列表
class Person3
{
public:
    int a;
    int b;
    int c;
    // 传统初始化操作
    // Person3(int a_new, int b_new, int c_new)
    // {
    //     a = a_new;
    //     b = b_new;
    //     c = c_new;
    // }

    // 初始化列表操作
    Person3(int a_new, int b_new, int c_new):a(a_new), b(b_new), c(c_new)
    {
        // 和传统初始化函数原理相同，但是顺序要对应
    }
    
};
void test04()
{
    Person3 p1(1, 2, 3);
    cout << "a = " << p1.a << ", b = "<< p1.b << ", c = " << p1.c << endl; 
}


// 类对象作为类成员
class Phone
{
public:
    string name;
    Phone(string name_new)
    {
        cout << "Phone(string name_new) use" << endl;
        name = name_new;
    }
    ~Phone()
    {
        cout << "~Phone() use" << endl;
    }
};
class Person4
{
public:
    string name;
    Phone phone;
    Person4(string name_new, Phone phone_new):name(name_new), phone(phone_new)
    {
        cout << "Person4(string name_new, Phone phone_new) use" << endl;
    }
    ~Person4()
    {
        cout << "~Person4() use" << endl;
    }
};
void test05()
{
    Phone phone("Iphone 11");
    Person4 p("Lisa", phone);   
    cout << p.name << " use " << p.phone.name << endl;
}


// 静态成员函数/变量
class Person5
{
public:
    // 所有对象都共享同一份数据
    // 在编译阶段就分配了内存
    // 类内声明，类外初始化
    static int a_static;   // 类内声明
    int a;
    // 静态成员变量也是有访问权限的

    static void func()   // 静态成员函数
    {
        cout << "static void func() use" << endl;
        cout << "b_static: " << b_static << endl;
        // cout << "a: " << a << endl;   // 程序报错，静态成员函数无法访问非静态成员变量
        //由于静态函数是作用与全局的，函数不知道去改变哪一个对象上的非静态变量，所以会报错
    }
    // 静态成员函数同静态成员变量，有访问权限
private:
    static int b_static;
    static void func2()   // 静态成员函数
    {
        cout << "static void func2() use" << endl;
        cout << "b_static: " << b_static << endl;
    }
};
int Person5::a_static = 100;   // 类外初始化
int Person5::b_static = 300;   // 类外初始化
// 所有对象都共享同一份静态成员变量
void test06()
{
    Person5 p1;
    cout << "p1.a_static: " << p1.a_static << endl;
    Person5 p2;
    p2.a_static = 200;   // 由于是放在全局区的变量，所以利用p2修改a_static后，p1中的数据也为更改，验证了所有对象共享同一份数据
    cout << "p1.a_static: " << p1.a_static << endl;
}
// 静态成员变量不属于某个对象上，所有对象共享一份数据，因此静态成员变量有以下两种访问方式
void test07()
{
    // 1.通过对象进行访问
    Person5 p1;
    cout << "p1.a_static: " << p1.a_static << endl;
    p1.func();
    // 2.通过类名进行访问
    cout << "Person5::a_static: " << Person5::a_static << endl;
    Person5::func();
    // cout << "Person5::a_static: " << Person5::b_static << endl;   // 程序报错，私有所有作用域下成员变量在类外无法访问
    // Person5::func2() // 程序报错，私有所有作用域下成员函数在类外无法访问
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
    system("pause");
    return 0;
}