#include<algorithm>
using namespace std;
#include<vector>

/*
    0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

    方法：
        约瑟夫环问题，本质上是一个动态规划
        设[i, m]问题的解为dp[i]
        通过以下公式可以从dp[i - 1]递推得到dp[i]
            dp[i] = (dp[i - 1] + m) % i; -- 有点难理解，看看题解

        dp[i]是dp[i - 1]进行补充后在进行m次右移的结果

        参考：https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solutions/178427/huan-ge-jiao-du-ju-li-jie-jue-yue-se-fu-huan-by-as/?envType=study-plan-v2&envId=coding-interviews
*/

int lastRemaining(int n, int m) {
    int pos = 0;
    for (int i = 2; i <= n; i++) {
        pos = (pos + m) % i;
    }
    return pos;
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
