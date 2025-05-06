//
// Created by ousun on 2025/5/5.
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <array>
#include <algorithm>

/*
    0 -
        0 - power cost
        1 - power cost
    1 -
        0 - power cost
        1 - power cost
 */
int bag(vector<vector<array<int, 2>>>& bags, int gold) {
    vector<vector<int>> dp(bags.size() + 1, vector<int>(gold + 1, 0));
    for (int i = 1; i <= bags.size(); ++i) {
        for (int j = 0; j <= gold; ++j) {
            for (int k = 0; k < bags[i - 1].size(); ++k) {
                int power = bags[i - 1][k][0], cost = bags[i - 1][k][1];
                if (j >= cost)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost] + power);
            }
        }
    }
    // TODO:回溯构造结果
    return dp[bags.size()][gold];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int cnt, gold;
        cin >> cnt >> gold;
        vector<string> names(cnt);
        // 由于装备可以重复强化，且强化次数有限制，转换成一个背包问题
        // 0-装备索引 1-装备是+几 1-增加的战力 2-金币数
        vector<vector<array<int, 2>>> bags;
        for (int i = 0; i < cnt; ++i) {
            cin >> names[i];
            int m;
            cin >> m;
            int power = 0, needGold = 0;
            vector<array<int, 2>> vec;
            for (int j = 0; j < m; ++j) {
                int power_, needGold_;
                cin >> power_ >> needGold_;
                power += power_, needGold += needGold_;
                vec.push_back({power, needGold});
            }
            bags.push_back(vec);
        }
        int ret = bag(bags, 100);
        cout << ret << endl;
    }
    return 0;
}


/*
 * 案例：
    2
    4 100
    Item1 1 20 30
    Item2 1 30 41
    Item3 1 10 10
    Item4 1 50 50
    6 256
    Item1 2 12 43 35 58
    Item2 2 34 54 88 31
    Item3 2 43 10 58 65
    Item4 2 32 54 19 19
    Item5 2 84 1 15 45
    Item6 2 19 40 99 12
 */