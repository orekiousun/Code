#include<iostream>
using namespace std;

/*
    快速幂，只不过是将幂次数不断右移，这样可以有效避免幂次数太大的问题
    同时可以处理负数
*/

// 初始快速幂
long long fastPow(int x, int k) {
    long long ans = 1;
    while (k > 0) {
        if(k % 2 == 1)  // 说明最后一位为1，需要乘
            ans = ans * x;
        x *= x;
        k >>= 1;
    }
    return ans;
}

// 快速幂，可以处理为大数情况
long long fastPow(int x, int k, int modNum) {
    long long ans = 1;
    while (k > 0) {
        if(k % 2 == 1)  // 说明最后一位为1，需要乘
            ans = (ans % modNum) * (x % modNum) % modNum;
        x = (x % modNum) * (x % modNum) % modNum;
        k >>= 1;
    }
    return ans % modNum;
}

// 可以处理负数情况
double quickMul(double x, long long N) {
    double ans = 1.0;
    while (N > 0) {
        if (N % 2 == 1) {
            ans *= x;
        }
        x *= x;
        N >>= 1;
    }
    return ans;
}

double myPow(double x, int n) {
    long long N = n;
    return N > 0 ? quickMul(x, N) : 1 / quickMul(x, -N);
}


int main(int argc, char const *argv[]) {
    cout << fastPow(2, 10) << endl;
    return 0;
}
