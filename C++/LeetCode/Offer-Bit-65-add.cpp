#include<iostream>
using namespace std;

/*
    写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
    和s = 非进位和 + 进位
    非进位和 = a ^ b
    进位 = (a & b) << 1
    直到没有进位，终止
*/



class Solution {
public:
    int add(int a, int b) {
        if (b == 0) {      // b=0也就是进位c=0，因此结果为非进位和n,也就是a
            return a;
        }
        return add(a ^ b, static_cast<unsigned int>(a & b) << 1);     // n=a^b，c= (a & b) << 1; 将a=n，b=c 继续递归 （注: leetcode不支持负值左移，需要强制转换(a&b)为无符号数）
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}
