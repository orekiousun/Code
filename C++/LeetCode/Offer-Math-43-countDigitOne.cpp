#include<iostream>
using namespace std;
#include<vector>

/*
    输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数
    法一：结合动态规划的思想，记录每个 0-9， 0-99， 0-999... 出现1的个数，再计算余数中1的个数
    法二：固定某一位为1，讨论其它位可能出现的情况
        当该位上原来的数为0时，此位 1 的出现次数只由高位决定        例如 2304 的第二位 0，此时 xx1x 可以从 0010 到 2219，共 23 * 10 种
        当该位上原来的数为1时，此位 1 的出现次数由高位和低位决定    例如 2314 的第二位 1，此时 xx1x 可以从 0010 到 2314，共 235 种
        当该位上原来的数大于1时，此位 1 的出现次数只由高位决定      例如 2324 的第二位 2，此时 xx1x 可以从 0010 到 2319 共 (23 + 1) * 10 种
*/

// 法一：结合动态规划的思想，记录每个 0-9， 0-99， 0-999... 出现1的个数，再计算余数
class Solution {
public:
    vector<int> dp;
    int len;

    int countSize(int num) {
        len = 0;
        while (num != 0) {
            num /= 10;
            len++;
        }
        dp.resize(len, 0);
        num = 1;
        for (int i = 1; i < len; i++) {
            dp[i] = 10 * dp[i - 1] + num;
            num *= 10;
        }
        return num;
    }

    int countDigitOne(int n) {
        int ans = 0;
        int tempNum = countSize(n);
        while (len--) {
            if(n / tempNum == 0) {
                n %= tempNum;
                tempNum /= 10;
                continue;
            } 
            if(n == 0) break;
            ans += n >= tempNum * 2 ? tempNum : n - tempNum + 1;
            ans += dp[len] * (n / tempNum);
            n %= tempNum;
            tempNum /= 10;
        }
        return ans;
    }
};

// 法二：固定某一位为1，讨论其它位可能出现的情况
class Solution2 {
public:
    int countDigitOne(int n) {
        int ans = 0, temp = 1, nCopy = n;
        while (n >= temp) {
            int remain = nCopy % 10;
            nCopy /= 10;
            if(remain == 0) ans += nCopy * temp;
            else if(remain == 1) ans += (n % temp) + nCopy * temp + 1;
            else ans += (nCopy + 1) * temp;
            temp *= 10; 
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution* op = new Solution();
    Solution2* op2 = new Solution2();
    cout << op->countDigitOne(2314) << endl;
    cout << op2->countDigitOne(1) << endl;
    return 0;
}
/*
    2314
    xxx1: 232
    xx1x: 235
    x1xx: 215
    1xxx: 315
*/
