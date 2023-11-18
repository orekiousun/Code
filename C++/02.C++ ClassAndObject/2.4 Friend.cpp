#include<iostream>
using namespace std;
#include<string>
/*
    友元  关键字friend
    在程序中，有一些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元技术
    友元有三种实现方法：加在类的定义内，即class中的{}内
        ·全局函数做友元
        ·类做友元
        ·成员函数做友元
    1.全局函数做友元
        friend 数据类型 函数名(形参列表);
    2.类做友元
        friend class 类名;
    3.成员函数做友元
        friend 数据类型 类名::成员函数名();
    4.在类的定义外书写函数的好处：
        当一个类的成员函数需要调用其他类的对象时，如果在定义内书写函数，可能无法找到该对象，程序无法编译
        但是如果将成员函数的实现写在所有类都定义好之后的类外时，程序就能找到相关的类和成员，以避免程序无法编译的问题

*/
class Gay;
class Gay2;
class Building;
void goodGay(Building *building);

class Building
{
    // 将goodGay全局函数作为bulding的友元，可以访问Building中的私有成员
    friend void goodGay(Building *building);
    // 将Gay这一类作为Building的友元，可以访问Building中的私有成员
    friend class Gay;
public:
    string SittingRoom;
    Building()
    {
        SittingRoom = "SittingRoom";
        BedRoom = "BedRoom";
    }
private:
    string BedRoom;
};
void goodGay(Building *building)   // 定义一个全局函数
{
    cout << "goodGay is finding " << building->SittingRoom << endl;
    cout << "goodGay is finding " << building->BedRoom << endl;   
    // 私有属性在类外无法访问，但是前面的Building类中
    // friend void goodGay(Building *building); 将当前函数定义为了友元，所以可以访问
}
// 在类外写成员函数
void test01()
{
    Building Building;
    goodGay(&Building);
}


class Gay
{
public:
    Building *building;
    void visit();   // 参观函数，访问building中的属性
    Gay();
};
Gay::Gay()
{
    building = new Building;
}
void Gay::visit()
{
    cout << "Gay is finding " << building->SittingRoom << endl;
    cout << "Gay is finding " << building->BedRoom << endl;
    // 私有属性在类外无法访问，但是前面的Building类中
    // friend class Gay; 将Gay类定义为了Building类的友元，所以可以访问
}
void test02()
{
    Gay g;
    g.visit();
}

class Building2;
class Gay2
{
public:
    Building2 *building;
    void visit_new();
    Gay2();
};


class Building2
{
    // 将Gay2这一类的成员函数visit_new作为Building的友元，可以访问Building中的私有成员
    friend void Gay2::visit_new();
public:
    string SittingRoom;
    Building2()
    {
        SittingRoom = "SittingRoom";
        BedRoom = "BedRoom";
    }
private:
    string BedRoom;
};

void Gay2::visit_new()
{
    cout << "Gay is finding " << building->SittingRoom << endl;
    cout << "Gay is finding " << building->BedRoom << endl;
}
Gay2::Gay2()
{
    building = new Building2;
}

void test03()
{
    Gay2 g;
    g.visit_new();
}

int main()
{
    cout << "------------ test01 ------------" << endl;
    test01();   
    cout << "------------ test02 ------------" << endl;
    test02();  
    cout << "------------ test03 ------------" << endl;
    test03();   
    system("pause");
    return 0;
}