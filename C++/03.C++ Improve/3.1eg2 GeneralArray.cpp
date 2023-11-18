#include<iostream>
using namespace std;
#include<string>

/*
    案例描述：实现一个通用的数组类，要求如下：
        可以对内置数据类型以及自定义数据类型进行存储
        将数组存储到堆区
        构造函数中传入数组的容量
        提供对应的拷贝构造函数以及operator=防止浅拷贝问题
        提供尾插法和尾删法对数组中的数据进行增加和删除
        可以通过下标的方式访问数组中的元素
        可以获取数组中当前元素个数和数组的容量
    几个需要注意的细节：
        拷贝构造函数参数的传入方式：const 数据类型& p
        运算符重载要返回引用
*/
template<class T>
class MyArray
{
private:
    T *array;
    int size;
    int capacity;
public:
    MyArray(int capacity)   // 有参构造
    {
        cout << "有参构造调用" << endl;
        this->capacity = capacity;
        this->size = 0;
        this->array = new T[this->capacity];
    }
    ~MyArray()
    {
        if (this->array != NULL)
        {
            cout << "析构函数调用" << endl;
            delete[] this->array;   // 注意这是一个数组
            this->array = NULL;
        }
    }
    MyArray(const MyArray& p)   // 注意拷贝构造函数参数的传入方式
    {
        cout << "拷贝构造调用" << endl;
        this->size = p.size;
        this->capacity = p.capacity;
        // 深拷贝
        this->array = new T[capacity];
        // 将array中数据都拷贝过来
        for (int i = 0; i < this->size; i++)
        {
            this->array[i] = p.array[i];
        }
    }
    MyArray& operator=(const MyArray& p)   // 为防止a = b = c的操作，利用引用返回本身
    {
        cout << "+”重载调用" << endl;

        // 先判断原来堆区是否有数据，如果有，先释放
        if (this->array != NULL)
        {
            delete[] this->array;   // 注意这是一个数组
            this->array = NULL;
            this->capacity = 0;
            this->size = 0;
        }
        this->size = p.size;
        this->capacity = p.capacity;
        // 深拷贝
        this->array = new T[this->capacity];
        // 将array中数据都拷贝过来
        for (int i = 0; i < this->size; i++)
        {
            this->array[i] = p.array[i];
        }
        return *this;
    }
    // 尾插法
    void myAdd(const T &value)
    {
        // 判断容量是否超标
        if(this->capacity == this->size)
        {
            return;
        }
        this->array[this->size] = value;   // 在数组末尾插入数据
        this->size++;   // 更新数组大小
    }
    void myDelete()
    {
        // 让用户访问不到最后一个元素
        if (this->size == 0)
        {
            return;
        }
        this->size--;
    }
    T& operator[](int index)   // 返回引用使其可以作为左值存在
    {
        return this->array[index];
    }
    int getCapacity()
    {
        return this->capacity;
    }
    int getSize()
    {
        return this->size;
    }
};
void printIntArray(MyArray<int>& p)
{
    for (int i = 0; i < p.getSize(); i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}
class Person
{
public:
    int m_age;
    string m_name;
    Person(){};
    Person(string name, int age)
    {
        this->m_age = age;
        this->m_name = name;
    }
};
void printPersonArray(MyArray<Person>& p)
{
    for (int i = 0; i < p.getSize(); i++)
    {
        cout << "name: " << p[i].m_name << "\tage: " << p[i].m_age << endl;
    }
}
void test01()
{
    MyArray<int> a1(5);
    for (int i = 0; i < 5; i++)
    {
        a1.myAdd(i);
    }
    cout << "array的打印输出为：";
    printIntArray(a1);
    a1.myDelete();
    cout << "array删除一个末尾元素后的打印输出为：";
    printIntArray(a1);
    cout << "array在末尾增加一个元素后的打印输出为：";
    a1.myAdd(4);
    printIntArray(a1);
    MyArray<int> a2(a1);
    cout << "array2的打印输出为：";
    printIntArray(a2);
    cout << "array2的打容量为：" << a2.getCapacity() << endl;
    cout << "array2的打大小为：" << a2.getSize() << endl;
    MyArray<int> a3(100);
    a3 = a1;
    // 测试自定义数据类型
    MyArray<Person> a4(10);
    Person p1("Lisa", 24);
    Person p2("Aimer", 22);
    Person p3("yama", 21);
    Person p4("ikura", 17);
    Person p5("milet", 23);
    a4.myAdd(p1);
    a4.myAdd(p2);
    a4.myAdd(p3);
    a4.myAdd(p4);
    a4.myAdd(p5);
    printPersonArray(a4);
}
int main()
{
    cout << "------------ test01 ------------" << endl;
    test01();
    system("pause");
    return 0;
}