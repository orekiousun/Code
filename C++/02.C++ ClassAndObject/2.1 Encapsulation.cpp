#include <iostream>
using namespace std;
#include<string>
/*
    C++面向对象的三大特性为：封装、继承和多态
    C++认为万事万物都为对象，对象上有其属性和行为
    具有相同性质的对象，我们可以抽象为类，例如人类，车类

    封装
    1.封装的意义
    ·将属性和行为作为一个整体，表现生活中的事物
    ·将属性和行为加以权限控制
        class 类名{ 访问权限:属性/行为 };   // 注意最后这个分号一定不能省略
    访问权限有以下三种：
        1）public    公共权限 -> 类内可以访问，类外可以访问 
        2）protected 保护权限 -> 类内可以访问，类外不可以访问 子类可以访问父类中的保护权限的内容
        3）private   私有权限 -> 类内可以访问，类外不可以访问 子类不可以访问父类中的私有权限的内容
    2.struct和class的区别：默认的访问权限不同
        ·struct默认权限为公共 public
        ·class 默认权限为私有 private
    3.成员属性私有化：可以控制读写权限
        对于写权限，可以检测数据有效性，防止数据超出有效范围
        一般习惯性将成员属性私有化，通过函数设置值
    4.项目中写类的方法：
        1.创建一个.h文件引入各种头文件并只书写类中的函数定义
        2.创建一个.cpp文件引入.h文件并只写下相关函数的实现，对于类中的函数前面要加 类的名称:: 
        3.在main.cpp中包含.h头文件
*/
const double pi = 3.14;
class Circle
{ 
public:   // 代表公共权限
    // 类中的属性和行为统一称为成员
    // 属性：一般用变量表示，叫做成员属性/成员变量
    int m_r;
    // 行为：一般用函数表示，叫做成员函数/成员方法
    double Circumference()
    {
        return 2 * pi * m_r;
    }
    void setM_r(int r)
    {
        m_r = r;
    }   // 也可以通过类里面的一个函数对属性赋值
};

class Person
{
public:   // 公共权限
    string name;
protected:   // 保护权限
    string car;
private:   // 私有权限
    int password;

private:   // 私有权限
    void func()
    {
        name = "Aimer";
        car = "BMW";
        password = 123456;
    }
};

class PersonNew
{
private:
    string m_Name;   // 可读可写
    int m_Age;   // 只读 -> 修改为可读可写，如果是写，则年龄范围修改到0-150之间
    string m_Lover;   // 只写
public:
    void setName(string name) // 设置姓名
    {
        m_Name = name;
    }
    string getName()   // 获取年龄
    {
        return m_Name;
    }
    int getAge()   // 获取年龄
    {
        return m_Age;
    }
    void setAge(int age)
    {
        if (age >= 0 && age <= 150 )
        {
            m_Age = age;
        }
        else
        {
            cout << "input false" << endl;
            m_Age = -1;
        }
    }
    void setLover(string lover)   // 设置情人
    {
        m_Lover = lover;
    }
};

class Cube
{
private:
    int m_L;   // 长
    int m_W;   // 宽
    int m_H;   // 高
public:
    void setProperty(int L, int W, int H)
    {
        m_L = L;
        m_W = W;
        m_H = H;
    }
    int getL(){ return m_L; }
    int getW(){ return m_W; }
    int getH(){ return m_H; }
    int getS()
    {
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
    }
    int getV()
    {
        return m_L * m_H * m_W;
    }
    bool isSameByClass(Cube& c1)   // 利用成员函数判断时只用传入一个参数即可
    {
        if(c1.getL() == m_L && c1.getW() == m_W && c1.getH() == m_H) return true;
        else return false;
    }
};

bool isSame(Cube& c1, Cube& c2)   // 利用引用可以避免拷贝数据，直接用原始的数据
{
    if(c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) return true;
    else return false;
}

class Point
{
private:
    int x;
    int y;
public:
    void setPoint(int x_new, int y_new)
    {
        x = x_new;
        y = y_new;
    }
    int getX(){ return x; }
    int getY(){ return y; }
};

class CircleNew
{
private:
    Point center;   // 在类中可以让另一个类成为本类中的成员
    int r; 
public:
    void setCenter(Point center_new)
    {
        center = center_new;
    }
    Point getCenter(){ return center; }
    void setR(int r_new)
    {
        r = r_new;
    }
    int getR(){ return r; }
};

void isInCircle(Point point, CircleNew circle)
{
    int x_point = point.getX(), y_point = point.getY();
    int r_circle = circle.getR();
    int x_circle = circle.getCenter().getX(), y_circle = circle.getCenter().getY();
    int d = (x_circle - x_point) * (x_circle - x_point) + (y_circle - y_point) * (y_circle - y_point);
    if ( d < r_circle * r_circle ) cout << "the point is in circle" << endl;
    else if ( d == r_circle * r_circle ) cout << "the point is on circle" << endl;
    else cout << "the point is out of circle" << endl;
}

int main(){
    // 通过圆类创建具体的圆（对象）
    // 实例化：通过一个类创建一个对象的过程
    Circle c1;
    c1.m_r = 10;   // 给圆对象的属性进行赋值
    cout << "the Circumference of c1: " << c1.Circumference() << endl;
    Circle c2;
    c2.setM_r(5);
    cout << "the Circumference of c2: " << c2.Circumference() << endl;

    // 权限分类
    Person p1;
    p1.name = "Swift";
    // p1.car = "Benz";   // 程序报错，car为保护权限的变量，无法在类外部修改
    // p1.password = 123;   // 程序报错，car为私有权限的变量，无法在类外部修改
    // p1.func()   // 程序报错，car为私有权限的函数，无法在类外部修改

    // 成员属性私有化
    PersonNew p2;
    p2.setName("Lisa");
    cout << "p2.m_Name: " << p2.getName() << endl;
    p2.setAge(178);
    cout << "p2.m_Age: " << p2.getAge() << endl; 
    p2.setAge(18);
    cout << "p2.m_Age: " << p2.getAge() << endl;
    p2.setLover("David");

    // 案例-立方体类
    Cube c3;
    c3.setProperty(2, 3, 4);
    cout << "Acreage: " << c3.getS() << endl;
    cout << "Volume: " << c3.getV() << endl;
    Cube c4;
    c4.setProperty(2, 4, 4);
    bool ret = isSame(c3, c4);
    if (ret) cout << "c3 == c4" << endl;
    else cout << "c3 != c4" << endl;
    bool ret2 = c3.isSameByClass(c4);
    if (ret2) cout << "c3 == c4 by Class" << endl;
    else cout << "c3 != c4 by Class" << endl;

    // 案例-点与圆的位置关系
    CircleNew c5;
    Point p3;
    Point center;
    center.setPoint(10, 0);
    c5.setCenter(center);
    cout << "x_center: " << c5.getCenter().getX() << ", " << "y_center: " << c5.getCenter().getY() << endl;
    c5.setR(10);
    cout << "r_circle: " << c5.getR() << endl;
    p3.setPoint(10, 8);
    cout << "x_point: " << p3.getX() << ", " << "y_point: " << p3.getY() << endl;
    isInCircle(p3, c5);

    system("pause");
    return 0;
}