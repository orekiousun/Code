#include<iostream>
using namespace std;
#include<string>

/*
    C++对象模型和this指针
    1.成员变量和成员函数分开存储：C++中，成员变量和成员函数是分开存储的 
        只有非静态的成员变量才属于类的对象上
    2.this指针：
    由于成员变量和成员函数是分开存储的，但是函数不在对象上，只有一份，通过this指针的方法可以帮助编译器找到相应的对象
        ·this指针指向被调用的成员函数所属的对象，即当前对象
        ·this指针是隐含每一个非静态成员函数内的一种指针
        ·this指针不需要定义，直接使用即可
        ·本质是一个指针常量，指针的指向不可以改变
    用途：
        ·当形参和成员变量同名时，可以用this指针区分，解决名称冲突
        ·在类的非静态成员函数中返回对象本身，可以使用return *this
    3.空指针访问成员函数
        C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
        在类的内部，所有成员变量在调用时都默认加了一个this->var用于表示当前成员变量
    4.const修饰成员函数
    常函数：
        ·成员函数加const后我们称这个函数为常函数
        ·常函数内不可以修改成员属性
        ·成员属性声明时加关键字mutable后，在常函数中依然可以修改
    常对象：
        ·声明对象前加const称该对象为常对象
        ·常对象只能调用常函数（一般对象可以调用常函数）    
*/

// 成员变量和成员函数分开存储
class Person1{};
class Person2
{
    int a;   // 非静态变量
};
class Person3
{
    static int a;   // 静态变量
};
int Person3::a = 10;   // 静态成员变量初始化
class Person4
{
    void func()
    {
        cout << "func() use" << endl;
    }
};
class Person5
{
    static void func()
    {
        cout << "func() use" << endl;
    }
};
void test01()
{
    Person1 p1;
    // 空对象占用的内存空间为：1
    cout << "sizeof(p1): " << sizeof(p1) << endl;
    // 输出为：1   原因：C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置，每个空对象也应该有一个独一无二的内存地址
    Person2 p2;
    cout << "sizeof(p2): " << sizeof(p2) << endl;
    // 输出为：4   就是根据int类型分配了4个字节的大小，并且侧面验证了非静态成员变量属于类的对象上
    Person3 p3;
    cout << "sizeof(p3): " << sizeof(p3) << endl;
    // 输出为：1   说明静态成员变量不属于类的对象
    Person4 p4;
    cout << "sizeof(p4): " << sizeof(p4) << endl;
    // 输出为：1   说明非静态成员函数和成员变量是分开存储的
    Person5 p5;
    cout << "sizeof(p5): " << sizeof(p5) << endl;
    // 输出为：1   说明静态成员函数和成员变量是分开存储的
}
// 总结：只有非静态的成员变量才属于类的对象上，非静态函数实现靠的是指针来区别对象


// 在类的非静态成员函数中返回对象本身，可以使用return *this
class Person6
{
public:
    int age;
    Person6(int age)
    {
        // this指针指向被调用的成员函数所属的对象
        this->age = age;   // this->age代表下面类中定义的那个age
    }
    // 返回对象本身
    Person6& AddAge(Person6 &p)   // 利用引用的方式返回的才是本体
    {
        this->age = p.age + this->age;
        // this是一个在指向对象的本身的指针，而*this就是对象本体
        return *this;
        // 相当于 Person6 &var =  *this;   *this为对象本体，对对象本体进行了一次引用
        // 如果用值的方式返回，会复制一份新的数据出来，有出错的可能
    }
};
void test02()
{
    Person6 p1(10);
    cout << "p1.age = " << p1.age << endl;
    Person6 p2(16);
    // 链式编程思想
    p2.AddAge(p1).AddAge(p1).AddAge(p1);   // 如果之前没有用引用的方式返回本体，这里的p2.age只会加一次
    cout << "p2.age = " << p2.age << endl;
}


// 空指针访问成员函数
class Person7
{
public:
    int age; 
    void showClassName()
    {
        cout << "this is Person7 class" << endl;
    }
    void showAge()
    {
        if (this == NULL)
        {
            return;
        }
        else
        {
            cout << "age = " << age << endl;
        }
        // 在类的内部，所有成员变量在调用时都默认加了一个this->var用于表示当前成员变量
    }
};
void test03()
{
    Person7 *p = NULL;
    p->showClassName();   // showClassName中没有传入调用this指针，不会报错
    // p->showAge();   // 程序报错，传入的指针为空，空指针没有指向一个确切的对象，没有值，无法访问内部成员
    p->showAge();   // 修改showAge后加入判断条件，可以加强代码健壮性
}


// const修饰成员函数
class Person8
{
public:
    int a; 
    mutable int b;   // 特殊变量，加入mutable关键字后，即使是常函数中也可以修改值
    // this指针本质是一个指针常量，指针的指向不可以改变，但是指向的值是可以修改的
    // Person *const this;
    // 在成员函数后面加const修饰this指针，让指针指向的值也不可以修改
    Person8()
    {

    }
    void showPerson() const
    {
        // 再加一个const之后相当于 const Person *const this，表示指向和指向的值均不可以修改;
        // this->a = 100;   // 加入const后，成员属性不允许修改
        this->b = 100;
    }
    void func(){}
};
void test04()
{
    Person8 p1;
    p1.showPerson();
    cout << "p1.b = " << p1.b << endl;
    const Person8 p2;   // 在对象前加上const变为常对象，不允许修改对象内的值
    // p2.a = 100;   // 程序报错，常对象内的值不允许修改
    p2.b = 200;   // b是被mutable关键字修饰后的值，在常对象下也可以修改
    cout << "p2.b = " << p2.b << endl;
    // 常对象只能调用常函数
    p2.showPerson();
    cout << "p2.b = " << p2.b << endl;
    // p2.func();   // 程序报错，常对象无法调用常函数
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