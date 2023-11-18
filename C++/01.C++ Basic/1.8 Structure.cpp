#include<iostream>
using namespace std;
#include<string>

/*
    结构
    1.基本概念：自定义的数据类型，允许用户存储不同的数据类型
    2.结构体的定义与使用：
        定义：struct 结构体名{ 结构体成员列表 };
            struct 结构体名 变量名
            struct 结构体名 变量名 = {成员1值, 成员2值...}
            定义结构体时顺便创建变量
        使用：
            struct Student s1;
            struct Student s2 = { ... }、
            Student s3;
            在定义结构体时顺便创建结构体变量
    3.结构体配合数组使用
        Student stuArr[3];
    4.结构体指针
        Student* p = &s4;
        p->name = "xxx";   // 通过指针访问结构体变量中数据
    5.结构体嵌套结构体：结构体中的成员可以是另一个结构体
    6.结构体做函数参数
        值传递和地址传递原理同基本数据结构
    7.结构体中const使用场景：利用const防止误操作
*/

struct Student
{
    string name;
    int age;
    int score;   // 本质上就是内置数据类型的集合 
}s3;   // 此处顺便创建结构体变量

struct Teacher
{
    string name;
    int age;
    string id;    
    Student stu1;   // 结构体中嵌套结构体
    Student stu2;
};

void stuPrint(Student stu)
{
    cout << "name: " << stu.name << ", age: " << stu.age << ", score: " << stu.score << endl; 
}

// 将函数中的形参改为指针，可以减少内存空间，而且不会复制出新的副本出来
void stuScoreChange(Student * stu)
{
    stu->score = 100;
}

void stuAgeChange(const Student * stu)
{
    //stu->age = 100;
    //加上const修饰之后stu结构体内值无法再改变
    cout << "name: " << stu->name << ", age: " << stu->age << ", score: " << stu->score << endl; 
}

int main() 
{
    // 调用法1
    struct Student s1;    // struct 关键字可以省略
    s1.name = "Lisa";
    s1.age = 18;
    s1.score = 92;
    cout << "name: " << s1.name << ", age: " << s1.age << ", score: " << s1.score << endl; 
    // 调用法2
    Student s2 = {"Yoasobi", 20, 100};
    cout << "name: " << s2.name << ", age: " << s2.age << ", score: " << s2.score << endl; 
    // 调用法3
    s3.name = "Aimer";
    s3.age = 25;
    s3.score = 100;
    stuPrint(s3); 
    // 结构体数组
    Student stuArr[3] = {
        {"Justin", 24, 99},
        {"Swift", 30, 98},
        {"Eminem", 35, 100}
    };
    for (int i = 0; i < 3; i++)
    {
        cout << "name: " << stuArr[i].name << ", age: " << stuArr[i].age << ", score: " << stuArr[i].score << endl; 
    }
    // 结构体指针
    Student s4 = {"Milet", 24, 60};
    stuScoreChange(&s4);   // 利用函数将成绩改为100分
    Student * p = &s4;
    cout << "name: " << p->name << ", age: " << p->age << ", score: " << p->score << endl;   // 通过指针访问结构体变量中数据
    // 结构体嵌套
    Teacher t1;
    t1.name = "Yama";
    t1.age = 32;
    t1.id = "0001";
    t1.stu1.name = "Yuki";
    t1.stu1.age = 18;
    t1.stu1.score = 88;
    t1.stu2 = s1;
    cout << "name: " << t1.name << ", age: " << t1.age << ", id: " << t1.id << ", stu1 name: " << t1.stu1.name << ", stu2 name: " << t1.stu2.name << endl;   // 通过指针访问结构体变量中数据 
    system("pause"); 
    return 0;
}