#include<iostream>
using namespace std;
#include<string>

/*
    多态：C++面向对象的三大特性之一
    1.多态的基本概念
    多态的分类：
        ·静态多态：函数重载，运算符重载属于静态多态，复用函数名
        ·动态多态：派生类和虚函数实现运行时多态
    静态多态和动态多态的区别：
        ·静态多态的函数地址早绑定 - 编译阶段确定函数地址
        ·动态多态的函数地址晚绑定 - 运行阶段确定函数地址
    动态多态的满足条件：
    1）有继承关系
    2）父类中要有虚函数
    3）子类要重写父类的虚函数（与重载不同，函数名称，返回值类型，参数列表完全相同才叫重写）
    动态多态的使用条件：
    1）父类的指针或引用指向子类对象
    2.多态的优点
        ·代码组织结构清晰
        ·可读性强
        ·利于前期和后期的拓展及维护
    3.纯虚函数和抽象类：
    在多态中，父类中的虚函数实现是毫无意义的，主要都是子类重写内容
    因此可以将虚函数定义为纯虚函数：
        virtual 返回值类型 函数名 (参数列表) = 0;
    当类中有了纯虚函数，该类也被称为抽象类，写纯虚函数的目的就是实现多态，子类会重写父类中的纯虚函数
    抽象类的特点：
    ·无法实例化对象
    ·子类必须重写抽象类中的纯虚函数，否则该子类也属于抽象类（无法实例化对象）
    4.虚析构和纯虚析构
    多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
    解决方法：将父类中的析构函数改为虚析构或者纯虚析构
    虚析构和纯虚析构共性：
        ·可以解决父类指针无法释放子类对象的问题
        ·都需要有具体的函数实现
        ·如果子类中没有堆区的数据，也可以不写虚析构或纯虚析构
    虚析构和纯虚析构的区别：
        ·如果是纯虚构函数，该类属于抽象类，无法实例化对象
    虚析构语法：
        virtual ~类名(){}
    纯虚析构语法：
        virtual ~类名() = 0;
        类名::~类名(){纯虚析构函数定义}   // 纯虚析构函数也需要代码实现，因为父类也有可能会有属性开辟到堆区，需要手动释放
    
*/

// 多态的使用
class Animal
{
public:
    // 虚函数 
    virtual void speak()
    {
        cout << "the animal is speaking" << endl;
    }
};
class Cat: public Animal
{
public:
    virtual void speak()   // 子类中是否定义为virtual关键字可写可不写，因为他的下面没有进一步的子类来完成多态的条件
    {
        cout << "the cat is speaking" << endl;
    }
};
class Dog: public Animal
{
    void speak()
    {
        cout << "the dog is speaking" << endl;
    }
};
void doSpeak(Animal &animal)  // 执行说话的函数
{
    // 地址早绑定，在编译阶段就确定了函数地址
    // 如果想执行Cat类中的dospeak，那么这个地址就不能提前绑定，需要在运行阶段进行绑定，即地址晚绑定
    // 进行地址晚绑定，需要用到动态多态，即将Animal中的speak函数变为虚函数
    animal.speak();  // 此时speak有了多种形态，即多态
}
void test01()
{
    Cat cat;
    doSpeak(cat);  // C++支持父类和子类之间的强制类型转换，但是上面调用的函数还是Animal类中的speak函数
    // 将animal中的speak改为虚函数之后，地址在程序运行时才开始绑定，可以访问到Cat中的speak函数
    Dog dog;
    doSpeak(dog);
}

// 多态的原理
void test02()
{
    cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
    // 没加virtual关键字时，输出为：1，非静态成员函数和成员变量分开存储，而空对象（类）占用的空间大小为1
    // 加入virtual关键字时，输出为：8，因为这是64位系统，这8个字节指一个指针（vfptr v-virtual f-function ptr-pointer，表示虚函数（表）指针）
    // 加入virtual关键字后，Animal类中会有一个指针vfptr，该指针会指向一个虚函数表vftable（虚函数表），表内部记录虚函数的地址：&Animal::speak
    cout << "sizeof(Cat) = " << sizeof(Cat) << endl;
    // 当没有发生重写时，子类从父类中继承指针vfptr，该指针指向的虚是函数表中记录的Animal中的函数地址即：&Animal::speak
    // 当子类中重写父类虚函数时，子类中的虚函数表内部会替换成子类的虚函数地址，即子类中虚函数表更换为：&Cat::speak，而父类中的虚函数表没有改变
    // 当父类的指针或引用指向子类对象的时候，发生多态，当调用speak函数时，由于调用的是一个cat对象，编译器就会从cat的vbtable中找到函数地址，即cat下的speak函数
}

// 纯虚函数和抽象类
class Base
{
public:
    // 只要有一个纯虚函数，这个类称为抽象类
    virtual void func() = 0;   // 纯虚函数
    // 使用 Base b;  new Base;  均会报错，无法实例化对象 
};
class Son1:public Base
{
public:  
};
class Son2:public Base
{
public:
    virtual void func()
    {
        cout << "func() use" << endl;
    }
};
void test03()
{
    // Base b;   // 报错,无法实例化对象
    // new Base;   // 报错,无法实例化对象
    // Son1 s;   // 报错，由于子类没有重写父类中的纯虚函数，子类也为抽象类，无法实例化对象
    Base* base = new Son2;   // 但是可以利用指针实例化一个子类的对象
    base->func();
}

// 虚析构和纯虚析构
class Animal2
{
public:
    Animal2()
    {
        cout << "Animal2() use" << endl;
    }
    // 利用虚析构可以解决父类指针无法释放子类对象的问题
    // virtual ~Animal2()   // 虚析构
    // {
    //     cout << "~Animal2() use" << endl;
    // }
    virtual ~Animal2() = 0;   // 这里也可以写为纯虚虚构，但只写这一段会报错，纯虚析构也需要代码实现，因为父类也有可能会有属性开辟到堆区，需要手动释放
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual void speak() = 0;   // 纯虚函数
};
Animal2::~Animal2()
{
    cout << "~Animal2() use" << endl;
}
class Cat2:public Animal2
{
public:
    Cat2(string name)
    {
        cout << "Cat2(string name) use" << endl; 
        this->name = new string(name);   // 在堆区创建了一属性，需要释放
    }
    void speak()
    {
        cout << "the cat " << *name << " is speaking" << endl;
    }
    ~Cat2()
    {
        if(this->name != NULL)
        {
            cout << "~Cat2() use" << endl; 
            delete this->name;   // 这里利用的是父类的指针指向子类的对象，所以删除父类指针时，并不会走子类的析构代码
            // 解决方法：将父类的虚构函数改为虚析构，在函数定义前加一个virtual
            this->name = NULL;
        }
    }
    string* name;
};
void test04()
{
    Animal2* animal = new Cat2("Tom");
    animal->speak();
    delete animal;
    // 这一步只是释放一个Animal2类型的数据，即只会执行父类析构，不会调用子类的析构函数，导致子类如果有堆区属性，会出现内存泄漏的情况
    // 解决方法：将父类的虚构函数改为虚析构，在函数定义前加一个virtual
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
    system("pause");
    return 0;
}