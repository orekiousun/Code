#include<iostream>
using namespace std;
#include<vector>
#include<cmath>

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

vector<int> printNumbers(int n) {
    // long long cnt = fastPow(10, n) - 1;
    long long cnt = pow(10, n) - 1;  // 也可以使用pow函数，需要#include<cmath>
    vector<int> ans(cnt);
    for (int i = 1; i <= cnt; i++) {
        ans[i - 1] = i;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
