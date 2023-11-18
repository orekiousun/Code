#include<iostream>
using namespace std;
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
#include<ctime>


/*
    案例描述
        有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
    实现步骤
        1. 创建五名选手，放到vector中
        2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
        3. sort算法对deque容器中分数排序，去除最高和最低分
        4. deque容器遍历一遍，累加总分
        5. 获取平均分
*/

class Person
{
public:
    string name;
    int score;
    Person(string name, int score)
    {
        this->name = name;
        this->score = score;
    }
};

// 初始化容器
void initPerson(vector<Person> &v)
{
    string strName = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name = name + strName[i];
        Person p(name, 0);
        v.push_back(p);
    }
}

// 打印Person容器
void printVector(const vector<Person> v)
{
    for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->name << "\t分数：" << (*it).score << endl;
    }
}

// 打印得分
void printDeque(const deque<int> v)
{
    for (deque<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 得到平均分
int getAvgScore()
{
    deque<int> score;
    
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 41 + 60;
        score.push_back(num);
    }
    printDeque(score);
    sort(score.begin(), score.end());  // 排序
    score.pop_back();
    score.pop_front();   // 去除最高最低分
    int tolScore = 0;
    for (int i = 0; i < 8; i++)
    {
        tolScore = tolScore + score[i];
    }
    int avgSocre = tolScore / score.size();
    return avgSocre;
}

// 将平均分重新设置给Person
void resetPerson(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->name << "的分数为：";
        it->score = getAvgScore();
    }
}

int main()
{
    vector<Person> com;
    initPerson(com);   // 初始化容器
    // 注意随机数种子要写在main函数中
    srand((unsigned int)time(NULL));  // 生成一个随机数种子
    resetPerson(com);   // 评委随机打分
    printVector(com);
    system("pause");
    return 0;
}