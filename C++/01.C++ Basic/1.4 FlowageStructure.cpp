#include<iostream>
using namespace std;
#include<string>
// time系统时间头文件
#include<ctime>
/*
    流语句结构
    1.选择结构
        1）if语句   嵌套，多条件...
            if(条件){条件满足执行的语句}   // 注意if条件的后面不要加;
            else if(条件){条件满足执行的语句}
            ...
            else{条件不满足执行的语句}
        2）三目运算符
            表达式1?表达式2:表达式3
                如果表达式1的值为真，执行表达式2，并返回表达式2的结果
                如果表达式1的值为假，执行表达式3，并返回表达式3的结果
            返回的是变量，可以继续赋值
        3）switch语句
            switch(表达式)
            {
                case 结果1:执行语句;break;
                case 结果2:执行语句;break;
                ...
                default:执行语句;break;
            }
            缺点：在判断分支时只能是整型或者字符型，不能是一个区间，但通常情况下switch语句执行效率会更高
    2.循环结构
        1）while循环：只要循环条件的结果为真，就执行循环语句
            while(循环条件)
                {循环语句};
        2）生成随机数：
            伪随机：
            int num = rand() 
            int num = rand() % 100 + 1   // 用于生成0-100内随机数
            真随机：利用当前系统当前时间生成随机数，防止每次随机数一致
            srand((unsigned int)time(NULL));  // 生成一个随机数种子
            int num = rand()
        3）do......while循环：先进行依次循环，再判断循环条件
            do{循环语句}while{循环条件};
        4）for循环：
            for(起始表达式;条件表达式;末尾循环体)
            {循环语句;}
        5）跳转语句：
            1.break：用于跳出选择结构或循环结构
            2.continue：跳过本次循环中余下尚未执行的语句，继续执行下一次循环   // 注意break会退出循环而continue不会
            3.goto：可以无条件地跳转语句
                goto 标记;   // 如果标记名称存在，，执行到 go to 语句时，会跳转到标记的位置
                goto Flag;
                xxx;xxx;
                Flag:
                xxx;xxx;

*/
int main()
{
    srand((unsigned int)time(NULL));
    if (2 == 1)
    {
        cout << "2 == 1" << endl;
    }
    else if (2 != 1)
    {
        cout << "2 != 1" << endl;
    }
    
    if (5 == 5) cout << "5 == 5" << endl;
    else cout << "5 != 5" << endl;
    // 三目运算符
    int a = 10;
    int b = 20;
    int c = 0;
    c = (a > b ? a : b);
    cout << "c =" << c << endl;
    (a > b ? a : b) = 100;   // 此处返回b的变量，相当于给b赋值
    cout << "a =" << a << endl;
    cout << "b =" << b << endl;
    // switch
    int score;
    cout << "input score:";
    cin >> score;
    switch (score)
    {
    case 10: cout <<"score:" << 10 << ",the best" << endl;break;
    case 9: cout <<"score:" << 9 << ",good" << endl;break;
    case 8: cout <<"score:" << 8 << ",good" << endl;break;
    case 7: cout <<"score:" << 7 << ",good" << endl;break;
    case 6: cout <<"score:" << 6 << ",common" << endl;break;
    case 5: cout <<"score:" << 5 << ",common" << endl;break;
    case 4: cout <<"score:" << 4 << ",common" << endl;break;
    default: cout <<"score:" << score << ",bad" << endl;break;
    }
    cout << 1 << endl;
    goto Flag;
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    Flag:
    cout << 4 << endl;
    cout << 5 << endl;
    cout << 6 << endl;
    system("pause");
    return 0;
}