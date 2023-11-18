#include<iostream>
using namespace std;
#include<vector>

/*
    把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

    你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

    方法：动态规划
        用前一个结果的基础上加上1，2，3，4，5，6 并乘以概率
*/

vector<double> dicesProbability(int n) {    
    vector<double> pre(6, 1.0/6.0);
    if(n == 1) return pre;
    for (int k = 2; k <= n; k++) {
        vector<double> cur(k * 6 - k + 1);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < pre.size(); j++) {
                cur[i + j] += pre[j] / 6.0;
            }
        }
        pre = cur;
    }
    return pre;
}

int main(int argc, char const *argv[]) {
    vector<double> res = dicesProbability(3);
    return 0;
}