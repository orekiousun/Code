#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
    计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
    你可以认为每种硬币的数量是无限的。
*/

int coinChange(vector<int>& coins, int amount) {
    int size = coins.size();
    vector<int> count(amount + 1, amount + 1);
    count[0] = 0;
    for (int i = 0; i <= amount; i++) {
        for (int coin : coins) {   // 这样访问vector内元素真的会快一点
            if(coin <= i)
                count[i] = min(count[i], 1 + count[i - coin]);
        }
    }
    return count[amount] > amount ? -1 : count[amount];
}

int main() {
    vector<int> coins{1, 2, 5};
    int amount = 33;
    cout << coinChange(coins, amount) << endl;
    system("pause");
    return 0;
}