#include<iostream>
using namespace std;
#include<string>

/*
    运算符重载：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
    编译器只知道内置的数据类型如何进行运算
        运算符重载本质上是写了一个函数，但是在调用时可以用加号替代
        运算符重载也可以发生函数重载
        内置的数据类型的表达式的运算符是无法重载的，并且不要滥用运算符重载
    1.加号运算符重载：实现两个自定义数据类型的相加的运算
        成员函数重载：数据类型 operator+(形参列表);
        全局函数重载：数据类型 operator+(形参列表);
    2.左移运算符重载
        通常不会利用成员函数重载<<，因为无法实现cout在左侧，即cout << p;
        只能利用全局函数重载左移运算符
    3.递增运算符重载
        前置：MyInteger& operator++();   // 前置递增返回引用
        后置：MyInteger operator++(int);   // 后置递增返回值
    4.赋值运算符重载
        C++其实还会给类添加一个默认赋值操作函数 operator= 对属性进行拷贝操作
        可以自定义赋值运算符进行深拷贝操作
    5.关系运算符重载：返回bool类型即可
    6.函数调用运算符重载
        ·函数调用运算符()也可以重载
        ·由于重载后使用方式非常像函数的调用，因此称为仿函数
        ·仿函数没有固定的写法，非常灵活
    7.匿名函数对象：通过一个类型加小括号可以创建一个匿名对象，当前行执行完之后立即释放
        MyPrint()("Hello World");   // 匿名函数对象

*/
class Person1
{
    friend Person1 operator+(Person1 &p1, Person1 &p2);
    friend void test01();
    friend ostream& operator<<(ostream &cout,  Person1 p);
    // 利用友元可以访问私有内容
private:
    int a;
    int b;
    // 通过成员函数重载+
    // Person1 operator+(Person1 &p);
    // 通常不会利用成员函数重载<<，因为无法实现cout在左侧
};
/*Person1 Person1::operator+(Person1 &p)
{
    Person1 temp;
    temp.a = this->a + p.a;
    temp.b = this->b + p.b;
    return temp;
}*/
Person1 operator+(Person1 &p1, Person1 &p2)
{
    Person1 temp;
    temp.a = p1.a + p2.a;
    temp.b = p1.b + p2.b;
    return temp;
}
/* 只能利用全局函数重载左移运算符
void operator<<(ostream &cout,  Person1 p)   // cout为ostream数据类型，为输出流对象，又由于cout全局只有一个，只能用引用的方式来引入函数中
{
    cout << "p.a = " << p.a << ", " << "p.b = " << p.b << endl;
}*/

// 左移运算符重载
ostream& operator<<(ostream &cout,  Person1 p)   // cout为ostream数据类型，为输出流对象，又由于cout全局只有一个，只能用引用的方式来引入函数中
{
    cout << "p.a = " << p.a << ", " << "p.b = " << p.b;
    return cout;
}   // 利用引用返回cout本身，也可以将cout改为其他名字，因为引用的本身就是起别名
void test01()
{
    // 加号重载
    Person1 p1;
    p1.a = 10;
    p1.b = 10;
    cout << "p1.a = " << p1.a << ", " << "p1.b = " << p1.b << endl;
    Person1 p2;
    p2.a = 20;
    p2.b = 20;
    cout << "p2.a = " << p2.a << ", " << "p2.b = " << p2.b << endl;
    Person1 p3 = p1 + p2;
    // 本质为 p3 = p1.operator+(p2) 或 p3 = operator+(p1, p2)
    cout << "p3.a = " << p3.a << ", " << "p3.b = " << p3.b << endl;
    // 启用全局函数或成员函数均可以完成重载
    // 左移运算符重载
    cout << p3 << endl;   // 成功实现左移运算符重载，但默认情况下这后面不能加endl，如果想继续在后面利用链式法则输出，需要返回cout
}


// 递增运算符重载
class MyInteger
{
    friend ostream& operator<<(ostream &cout,  MyInteger p);
public:
    MyInteger()
    {
        n = 0;
    }
    // 重载前置++运算符
    MyInteger& operator++()
    {
        n ++;
        return *this;   // 先做++再返回
    }   // 利用引用返回n本身
    // 重置后置++运算符
    MyInteger operator++(int)   // int代表一个占位参数，可以用于区分前置后后置递增
    {
        MyInteger temp = *this;   // 先记录当时结果
        n ++ ;   // 再递增，以确保该值确实增加了
        return temp;
    }   // 无法返回局部对象的引用，只能返回值，但是这种方法就不能实现 (myint++)++

    // 重载前置--运算符
    MyInteger& operator--()
    {
        n --;
        return *this;   
    }  
    // 重置后置--运算符
    MyInteger operator--(int)   
    {
        MyInteger temp = *this;   
        n -- ;   
        return temp;
    }   
    // 注意前置和后置的写法是相对固定的
private:
    int n;
};
ostream& operator<<(ostream &cout,  MyInteger myint)   // cout为ostream数据类型，为输出流对象，又由于cout全局只有一个，只能用引用的方式来引入函数中
{
    cout << myint.n;
    return cout;
}   // 利用引用返回cout本身，也可以将cout改为其他名字，因为引用的本身就是起别名
void test02()
{
    MyInteger myint1;
    cout << "++myint1: " << ++myint1 << endl;   // 说明前置递增成功
    MyInteger myint2;
    cout << "myint2++: " << myint2++ << endl;
    cout << "myint2: " << myint2 << endl;   // 说明后置递增成功

    MyInteger myint3;
    cout << "--myint3: " << --myint3 << endl;   // 说明前置递增成功
    MyInteger myint4;
    cout << "myint4--: " << myint4-- << endl;
    cout << "myint4: " << myint4 << endl;   // 说明后置递减成功
}


//赋值运算符重载
class Person2
{
public:
    Person2(int age)
    {
        this->age =  new int(age);
    }
    ~Person2()
    {
        if(age != NULL)
        {
            delete age;
            age = NULL;
        }
    }
    Person2& operator=(Person2 &p)
    {
        // 浅拷贝 age = p.age
        // 应该先判断是否有属性在堆区（this类之前本身开辟），如果有，先释放再深拷贝
        if(age != NULL)
        {
            delete age;
            age = NULL;
        }
        age = new int(*p.age);   // 深拷贝
        return *this;   // 返回自身可以实现连等
    }
    int *age;
};
void test03()
{
    Person2 p1(18);
    Person2 p2(20);
    Person2 p3(24);
    cout << "p1.age = " << *p1.age << endl;
    cout << "p2.age = " << *p2.age << endl;
    cout << "p3.age = " << *p3.age << endl;
    p2 = p1 = p3; // 赋值运算操作
    // 程序报错，由于默认赋值操作为浅拷贝，拷贝时会将p1的age中保存的地址拷贝给p2的位置中保存的地址，所以析构函数在释放时会对同一个地址释放两次，程序会报错
    // 可以通过重载赋值运算符解决问题
    cout << "p2 = p1 = p3" << endl;
    cout << "p1.age = " << *p1.age << endl;
    cout << "p2.age = " << *p2.age << endl;
    cout << "p3.age = " << *p3.age << endl;
}


// 关系运算符重载
class Person3
{
public:
    string name;
    int age;
    Person3(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator==(Person3 &p)
    {
        if( this->name == p.name && this->age == p.age ) return true;
        else return false;
    }
    bool operator!=(Person3 &p)
    {
        if( this->name != p.name || this->age != p.age ) return true;
        else return false;
    }
};
void test04()
{
    Person3 p1("Lisa", 24);
    Person3 p2("Lisa", 24);
    Person3 p3("Aimer", 24);
    if(p1 == p2) cout << "p1 == p2" << endl;
    else cout << "p1 != p2" << endl;
    if(p1 != p3) cout << "p1 != p3" << endl;
    else cout << "p1 == p3" << endl;
}


class MyPrint
{
public:
    // 重载函数调用运算符，将()定义为了使用下面的函数
    void operator()(string test)
    {
        cout << test << endl;
    }
};
void Print(string test)
{
    cout << test << endl;
}
void test05()
{
    MyPrint myPrint;
    myPrint("Hello World");   // 函数运算符()重载，由于使用起来非常像函数，所以称为仿函数
    // 利用这种仿函数的书写方式非常灵活
    MyPrint()("Hello World");   // 匿名函数对象
    Print("Hello World");   // 正常函数调用
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
    system("pause");
    return 0;
}