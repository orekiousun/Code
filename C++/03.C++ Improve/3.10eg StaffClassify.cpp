#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<ctime>

/*
    案例描述：
        公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
        员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
        随机给10名员工分配部门和工资
        通过multimap进行信息的插入  key(部门编号) value(员工)
        分部门显示员工信息
    实现步骤
        1. 创建10名员工，放到vector中
        2. 遍历vector容器，取出每个员工，进行随机分组
        3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
        4. 分部门显示员工信息
*/
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
    string name;
    int salary;
    Worker(string name, int salary)
    {
        this->name = name;
        this->salary = salary;
    }
};


void createWoker(vector<Worker> &vWorker)   // 注意需要通过引用传入
{
    string nameList = "ABCDEFGHIJ";
    
    for (int i = 0; i < 10; i++)
    {
        string name = "";
        name += nameList[i];
        // 注意这里字符串拼接的手法，char类型不能强转为string类，需要进行一个空字符串的拼接
        // 非常常用以及重要易错
        Worker w(name, rand()%10000 + 10000);   // 10000-19999
        vWorker.push_back(w);
    }
}
void printWorkerVector(const vector<Worker> &v)
{
    for (vector<Worker>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " <<it->name << "\tsalary: " << it->salary << endl;
    }
    cout << endl;
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 < v2;
    }
};

void creatMultimap(vector<Worker> &vWorker, multimap<int, Worker, MyCompare> &mWorker)
{
    
    vector<Worker>::iterator it = vWorker.begin();
    for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end() ; it++)
    {
        mWorker.insert(make_pair(rand()%3, *it));
    }
}

void printMultimap(multimap<int, Worker, MyCompare> &m)
{
    string depArr[3] = {"策划", "美术", "研发"};
    for (multimap<int, Worker, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "Department:" << depArr[it->first] << "\tname: " << it->second.name << endl;
    }

    cout << "策划部门：" << endl;
    // int count = m.count(CEHUA);
    // 利用MyCompare自定义排序顺序时，不能使用m.count方法(编译器报错)
    int index = 0;
    for(multimap<int, Worker, MyCompare>::iterator pos = m.find(CEHUA) ; pos != m.end() && pos->first == CEHUA ;index++, pos++)
    {
        cout << "Department:" << depArr[pos->first] << "\tname: " << pos->second.name << "\tsalary: " << pos->second.salary << endl;
    }

    cout << "美术部门：" << endl;
    // count = m.count(MEISHU);
    index = 0;
    for(multimap<int, Worker, MyCompare>::iterator pos = m.find(MEISHU) ; pos != m.end() && pos->first == MEISHU ;index++, pos++)
    {
        cout << "Department:" << depArr[pos->first] << "\tname: " << pos->second.name << "\tsalary: " << pos->second.salary << endl;
    }

    cout << "研发部门：" << endl;
    // count = m.count(YANFA);
    index = 0;
    for(multimap<int, Worker, MyCompare>::iterator pos = m.find(YANFA) ; pos != m.end() && pos->first == YANFA ;index++, pos++)
    {
        cout << "Department:" << depArr[pos->first] << "\tname: " << pos->second.name << "\tsalary: " << pos->second.salary << endl;
    }
}

int main()
{
    // 创建员工
    vector<Worker> vWorker;
    srand((unsigned int)time(NULL));  // 生成一个随机数种子
    createWoker(vWorker);
    printWorkerVector(vWorker);

    // 员工分组
    multimap<int, Worker, MyCompare> mWorker;
    creatMultimap(vWorker, mWorker);
    printMultimap(mWorker);

    system("pause");
    return 0;
}