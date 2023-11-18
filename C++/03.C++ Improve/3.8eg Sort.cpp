#include<iostream>
using namespace std;
#include<list>
#include<string>

/*
    案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
    排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
*/
class Person
{
public:
    string name;
    int age;
    int height;
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

bool myCompare(Person &p1, Person &p2)   // 仿函数实现
{
    if (p1.age != p2.age)   // 年龄不相同，按照年龄降序
    {
        return p1.age < p2.age;
    }
    else   // 年龄不相同，按照身高降序
    {
        return p1.height < p2.height;
    }
    
}
void printList(const list<Person> &l)
{
    for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "name: " << it->name << "\tage: " <<  it->age << "\t height: " << it->height << endl;
    }
}
void test01()
{
    list<Person> l1;
    Person p1("Lisa", 26, 165);
    Person p2("Ikura", 22, 153);
    Person p3("Aimer", 27, 160);
    Person p4("Jusin", 27, 173);
    Person p5("Taylor", 32, 180);
    Person p6("Yama", 27, 171);
    l1.push_back(p1);
    l1.push_back(p2);
    l1.push_back(p3);
    l1.push_back(p4);
    l1.push_back(p5);
    l1.push_back(p6);
    cout << "------------ 排序前 ------------" << endl;
    printList(l1);
    l1.sort(myCompare);
    cout << "------------ 排序后 ------------" << endl;
    printList(l1);
}

int main()
{
    test01();
    system("pause");
    return 0;
}