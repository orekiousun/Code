#include<iostream>
using namespace std;
#include<vector>

/*
    求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

    方法：利用短路逻辑代替if
*/


class Solution {
public:
    int res = 0;
    int sumNums(int n) {
        bool a = n >= 1 && sumNums(n - 1) > 0;
        res += n;
        return res;
    }
};

// 天秀解法
int sumNums(int n) {
    bool a[n][n + 1];
    return sizeof(a) >> 1;
}

// 违规，用了if
int sumNums(int n, bool flag) {
    if(n > 0)
        return n + sumNums(n - 1);
    else 
        return 0;
}

int main(int argc, char const *argv[]) {
    Solution *op = new Solution();
    cout << op->sumNums(7) << endl;
    return 0;
}
