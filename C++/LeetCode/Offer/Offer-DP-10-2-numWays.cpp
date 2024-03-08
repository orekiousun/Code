#include<iostream>
using namespace std;
#include<vector>

/*
    动态规划，同斐波拉契数列只是初始值不一致
        ·方案一：维护一个数组进行动归
        ·方案二：只用记录前两个数就行
*/

int numWays(int n) {
    int pre1 = 1, pre2 = 2;
    if(n == 0) return 1;
    else if(n <= 2) return 1;
    int ans;
    for (int i = 3; i <= n; i++) {
        ans = (pre1 + pre2) % 1000000007;
        pre1 = pre2, pre2 = ans;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    cout << numWays(7) << endl;
    return 0;
}


