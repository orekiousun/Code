#include<iostream>
using namespace std;
#include<string>

// 多态案例3：电脑
/*
    电脑的主要组成部件有CPU（计算），显卡（显示），内存条（存储）
    将每个零件封装出抽象基类，并且提供不同厂商生产不同的零件，例如intel和amd
    创建电脑提供让电脑工作的函数，并且调用每个零件工作的接口
    测试时组装三台不同的电脑进行工作
*/
class CPU
{
public:
    virtual void calculate() = 0;
    CPU()
    {
        cout << "CPU 构造函数调用" << endl;

    }
    ~CPU()
    {
        cout << "CPU 析构函数调用" << endl;
    }
};
class intelCPU:public CPU
{
public:
    void calculate()
    {
        cout << "intelCPU is calculating" << endl;
    }
};
class amdCPU:public CPU
{
public:
    void calculate()
    {
        cout << "amdCPU is working" << endl;
    }
};

class Graphics
{
public:
    virtual void display() = 0;
    Graphics()
    {
        cout << "Graphics 构造函数调用" << endl;

    }
    ~Graphics()
    {
        cout << "Graphics 析构函数调用" << endl;
    }
};
class intelGraphics:public Graphics
{
public:
    virtual void display()
    {
        cout << "intelGraphics is displaying" << endl;
    }
};
class amdGraphics:public Graphics
{
public:
    virtual void display()
    {
        cout << "amdGraphics is displaying" << endl;
    }
};

class Memory
{
public:
    virtual void storage() = 0;
    Memory()
    {
        cout << "Memory 构造函数调用" << endl;

    }
    ~Memory()
    {
        cout << "Memory 析构函数调用" << endl;
    }
};
class intelMemory:public Memory
{
public:
    void storage()
    {
        cout << "intelMemory is storaging" << endl;
    }
};
class amdMemory:public Memory
{
public:
    void storage()
    {
        cout << "amdMemory is storaging" << endl;
    }
};

class Computer
{
public:
    CPU* cpu;
    Graphics* gra;
    Memory* mem;
    Computer(CPU* cpu, Graphics* gra, Memory* mem)
    {
        cout << "Computer 构造函数调用" << endl;
        this->cpu = cpu;
        this->gra = gra;
        this->mem = mem;
    }
    void work()
    {
        cpu->calculate();
        gra->display();
        mem->storage();
    }
    ~Computer()
    {
        cout << "Computer 析构函数调用" << endl;
        if(cpu != NULL)
        {
            delete cpu;
            cpu = NULL;
        }
        if(gra != NULL)
        {
            delete gra;
            gra = NULL;
        }
        if(mem != NULL)
        {
            delete mem;
            mem = NULL;
        }   // 不写delete关键字去delete零件的话，就不会调用零件的析构函数（因为零件开辟在堆区）
    }
};

void test01()
{
    cout << "----- the first computer -----" << endl;
    Computer* computer1 = new Computer(new intelCPU, new intelGraphics, new intelMemory);   // 先构造零件，再创建电脑，即零件的构造函数先执行，再执行电脑的构造函数
    computer1->work();
    delete computer1;
    cout << "----- the second computer -----" << endl;
    Computer* computer2 = new Computer(new amdCPU, new amdGraphics, new amdMemory);
    computer2->work();
    delete computer2;
    cout << "----- the third computer -----" << endl;
    Computer* computer3 = new Computer(new amdCPU, new intelGraphics, new intelMemory); 
    computer3->work();
    delete computer3;
}
void test02()
{
    cout << "----- the first computer -----" << endl;
    Computer computer1(new intelCPU, new intelGraphics, new intelMemory);   // 先构造零件，再创建电脑，即零件的构造函数先执行，再执行电脑的构造函数
    computer1.work();
    cout << "----- the second computer -----" << endl;
    Computer computer2(new amdCPU, new amdGraphics, new amdMemory);
    computer2.work();
    cout << "----- the third computer -----" << endl;
    Computer computer3(new amdCPU, new intelGraphics, new intelMemory); 
    computer3.work();
    // 这种方法会在函数结束时统一释放栈区的数据
}
// 这里释放零件的代码不能写在对应零件的析构函数内，因为零件是被开辟到堆区的，想要释放就必须手动书写delete关键字来释放它，写delete时会调用析构函数，而不能通过析构函数的方式调用delete

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}