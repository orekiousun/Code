#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm> 

/*
    string容器
    1.string本质是一个类
    string和char*的区别：
        char*是一个指针
        string是一个类，类内封装了char*，管理这个字符串，是一个char*型的容器
    特点：
        string类内部封装了很多成员方法 find，copy，delete，replace，insert等
        string管理char*所分配的内存，不用担心复制越界和取值越界等，有类内部进行负责
    2.string构造函数
    构造函数原型：
        string();                     // 创建一个空的字符串
        string(const char* s);        // 使用字符串s初始化
        string(const string& str);    // 使用一个string对象初始化另一个string对象
        string(int m, char c);        // 使用n个字符串c初始化
    3.string的赋值操作
    函数原型：
        string& operator=(const char* s);            //char*类型字符串 赋值给当前的字符串
        string& operator=(const string &s);          //把字符串s赋给当前的字符串
        string& operator=(char c);                   //字符赋值给当前的字符串
        
        string& assign(const char *s);               //把字符串s赋给当前的字符串
        string& assign(const char *s, int n);        //把字符串s的前n个字符赋给当前的字符串
        string& assign(const string &s);             //把字符串s赋给当前字符串
        string& assign(int n, char c);               //用n个字符c赋给当前字符串
    4.string字符串拼接
        string& operator+=(const char* str);              //重载+=操作符
        string& operator+=(const char c);                 //重载+=操作符
        string& operator+=(const string& str);            //重载+=操作符

        string& append(const char *s);                    //把字符串s连接到当前字符串结尾
        string& append(const char *s, int n);             //把字符串s的前n个字符连接到当前字符串结尾
        string& append(const string &s);                  //同operator+=(const string& str)
        string& append(const string &s, int pos, int n);  //字符串s中从pos开始的n个字符连接到字符串结尾
    5.string查找和替换
    查找：查找指定字符串是否存在
    替换：在指定位置替换字符串
        int find(const string& str, int pos = 0) const;           //查找str第一次出现位置,从pos开始查找
        int find(const char* s, int pos = 0) const;               //查找s第一次出现位置,从pos开始查找
        int find(const char* s, int pos, int n) const;            //从pos位置查找s的前n个字符第一次位置
        int find(const char c, int pos = 0) const;                //查找字符c第一次出现位置

        int rfind(const string& str, int pos = npos) const;       //查找str最后一次位置,从pos开始查找
        int rfind(const char* s, int pos = npos) const;           //查找s最后一次出现位置,从pos开始查找
        int rfind(const char* s, int pos, int n) const;           //从pos查找s的前n个字符最后一次位置
        int rfind(const char c, int pos = 0) const;               //查找字符c最后一次出现位置

        string& replace(int pos, int n, const string& str);       //替换从pos开始n个字符为字符串str
        string& replace(int pos, int n,const char* s);            //替换从pos开始的n个字符为字符串s
        rfind和find的区别：rfind从右往左查，find从左往右查
    6.字符串比较
        字符串是按ASCII码进行对比
    = 返回 0
    > 返回 1
    < 返回 -1
        int compare(const string &s) const;    //与字符串s比较
        int compare(const char *s) const;      //与字符串s比较
    最大用处还是比较两个字符串之间是否相等
    7.字符存取
    string中单个字符存取方式有两种
        char& operator[](int n);     // 通过[]方式取字符
        char& at(int n);             // 通过at方法获取字符
    8.字符串插入和删除
    对string字符串进行插入和删除字符操作
        string& insert(int pos, const char* s);               //插入字符串
        string& insert(int pos, const string& str);           //插入字符串
        string& insert(int pos, int n, char c);               //在指定位置插入n个字符c
        string& erase(int pos, int n = npos);                 //删除从Pos开始的n个字符 
    9.子串获取
    从字符串中获取想要的子串
        string substr(int pos = 0, int n = npos) const;       //返回由pos开始的n个字符组成的字符串
    10.string和char的区别
*/
// string构造函数
void test01()
{
    string s1;
    const char* str = "YOASOBI";
    string s2(str);
    cout << "s2 = " << s2 << endl;
    string s3(s2);
    cout << "s3 = " << s3 << endl;
    string s4(10 , 'a');
    cout << "s4 = " << s4 << endl;
}   

// string的赋值操作
void test02()
{
    //  string& operator=(const char* s);            //char*类型字符串 赋值给当前的字符串
    string str1;
    str1 = "YOASOBI";
    cout << "str1 = " << str1 << endl;

    // string& operator=(const string &s);          //把字符串s赋给当前的字符串
    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    // string& operator=(char c);                   //字符赋值给当前的字符串
    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    // string& assign(const char *s);               //把字符串s赋给当前的字符串
    string str4;
    str4.assign("Lisa");
    cout << "str4 = " << str4 << endl;

    // string& assign(const char *s, int n);        //把字符串s的前n个字符赋给当前的字符串
    string str5;
    str5.assign("Lisa", 2);
    cout << "str5 = " << str5 << endl;

    // string& assign(const string &s);             //把字符串s赋给当前字符串
    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    // string& assign(int n, char c);               //用n个字符c赋给当前字符串
    string str7;
    str7.assign(6, 'w');
    cout << "str7 = " << str7 << endl;
}

// string字符串拼接
void test03()
{
    // string& operator+=(const char* str);              //重载+=操作符
    string str1 = "YOASOBI";
    str1 += " a super singer";
    cout << "str1 = " << str1 << endl;

    // string& operator+=(const char c);                 //重载+=操作符
    string str2 = "Lis";
    str2 += 'a';
    cout << "str2 = " << str2 << endl;
    
    // string& operator+=(const string& str);            //重载+=操作符
    string str3 = "Ikura";
    string temp = " a super singer";
    str3 += temp;
    cout << "str3 = " << str3 << endl;
    
    // string& append(const char *s);                    //把字符串s连接到当前字符串结尾
    string str4 = "Yama";
    str4.append(" a super singer");
    cout << "str4 = " << str4 << endl;

    // string& append(const char *s, int n);             //把字符串s的前n个字符连接到当前字符串结尾
    string str5 = "Milet";    
    str5.append(" a super singer aaaa", 15);
    cout << "str5 = " << str5 << endl;
    
    // string& append(const string &s);                  //同operator+=(const string& str)
    string str6 = "Miku";    
    str6.append(temp);
    cout << "str6 = " << str6 << endl;
    
    // string& append(const string &s, int pos, int n);  //字符串s中从pos开始的n个字符连接到字符串结尾
    string str7 = "Aimer";
    str7.append("aa a super singer aa", 2, 15);
    cout << "str7 = " << str7 << endl;
}

// string查找和替换
void test04()
{
    // 查找
    string str1 = "abcdefg";
    int pos1 = str1.find("de");   // 返回de第一次出现的位置
    int pos2 = str1.find("df");   // 没有找打返回-1
    cout << "pos1 = " << pos1 << " pos2 = " << pos2 << endl;
    pos1 = str1.rfind("ab");
    cout << "pos1_new = " << pos1 << endl;
    // 替换
    str1.replace(2, 3, "xxxxxx");   // 会全都替换进去
    cout << "str1 = " << str1 << endl;
    
}

// 字符串比较
void test05()
{
    string str1 = "abcdef";
    int result = str1.compare("abcdef");
    cout << "result = " << result << endl;
    string str2 = "abcdem";
    result = str1.compare(str2);
    cout << "result = " << result << endl;
    string str3 = "abcdee";
    result = str1.compare(str3);
    cout << "result = " << result << endl;
}

// 字符存取
void test06()
{
    string str = "hello";
    // 通过[]访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    // 通过at方法访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;
    str[0] = 'x';
    str.at(1) = 'x';
    cout << "str = " << str << endl;
}

// 字符串插入和删除
void test07()
{
    string str = "xxxxx";
    str.insert(1, "abc");
    cout << "str = " << str << endl;
    str.erase(1, 3);
    cout << "str = " << str << endl;
    str.insert(1, 3, 'w');
    cout << "str = " << str << endl;
}

// 子串获取
void test08()
{
    string str = "abcdef";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;
    string email = "1187749429@qq.com";
    int temp = email.find('@');
    string qq = email.substr(0, temp);
    cout << "qq = " << qq << endl;
}

void test09()
{
    string name = "Lisa";
    char name2[4] = {'c','o','c','o'};
    char *name3 = "coco";     // 会发生一次强制类型转换
    // 会报错，但是可以运行
    char name4[] = "coco";    // 会发生一次强制类型转换
    char name5[5] = "coco";   // 注意字符数组最后会保存一个\0，为系统默认，所以要多开一个空间
    cout << name[1] << endl;
    cout << name2[3] << endl;
    cout << name3[3] << endl;
    cout << name4[2] << endl;
    cout << name5[4] << endl;
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
    cout << "------------ test05 ------------" << endl;
    test05(); 
    cout << "------------ test06 ------------" << endl;
    test06();
    cout << "------------ test07 ------------" << endl;
    test07();
    cout << "------------ test08 ------------" << endl;
    test08();
    cout << "------------ test09 ------------" << endl;
    test09();
    system("pause");
    return 0;
}