#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
#include<ctime>
/*
    常用排序算法
        sort             // 对容器内元素进行排序
        random_shuffle   // 洗牌   指定范围内的元素随机调整次序
        merge            // 容器元素合并，并存储到另一容器中
        reverse          // 反转指定范围的元素
    1.sort
    功能描述：
        对容器内元素进行排序
    函数原型：
    sort(iterator beg, iterator end, _Pred);  `
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    //  beg    开始迭代器
    //  end    结束迭代器
    // _Pred   谓词 不填默认从小到大排序
    2.random_shuffle
    功能描述：
        洗牌   指定范围内的元素随机调整次序
        加入随机数种子让每次打乱结果不同
    函数原型：
        random_shuffle(iterator beg, iterator end);  `
        // 指定范围内的元素随机调整次序
        // beg 开始迭代器
        // end 结束迭代器
    3.merge
    功能描述：
        两个容器元素合并，并存储到另一容器中
    函数原型：
        merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
        // 容器元素合并，并存储到另一容器中
        // 注意: 两个容器必须是 有序的
        // beg1   容器1开始迭代器
        // end1   容器1结束迭代器
        // beg2   容器2开始迭代器
        // end2   容器2结束迭代器
        // dest    目标容器开始迭代器
    4.reverse
    功能描述：
        将容器内元素进行反转（首尾对调）
    函数原型：
        reverse(iterator beg, iterator end);  
        // 反转指定范围的元素
        // beg 开始迭代器
        // end 结束迭代器

*/
void myPrint(int val)
{
    cout << val << " ";
}

// sort
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(60);
    v.push_back(80);
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // 改变为降序 -- 使用内建函数对象
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);  
    cout << endl;
}

// random_shuffle
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // 利用洗牌算法打乱顺序
    srand((unsigned int)time(NULL));
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

// merge
void test03()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }
    vector<int> v3;
    v3.resize(20);   // 需要先为v3容器开辟空间，不能硬把东西塞进容器中
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), myPrint);
    cout << endl;
}

// reverse
void test04()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
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