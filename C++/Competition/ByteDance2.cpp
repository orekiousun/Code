#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int damage, use;
        cin >> damage >> use;
        m[damage] = max(m[damage], use);
    }
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int ques;
        cin >> ques;
        int temp = m[ques];
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            if((*it).first <= ques)
                temp = max((*it).second, temp);
            else
                break;
        }
        m[ques] = temp;
        cout << (temp == 0 ? -1 : temp) << endl;
    }

    system("pause");
    return 0;
}



    // int dp[n + 1][size + 1];
    // for (int i = 0; i < n; i++) {
    //     dp[i][0] = 0;
    // }
    // for (int j = 0; j <= size; j++) {
    //     dp[0][size] = 0;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= size; j++) {
    //         if(damage[i - 1] <= j)
    //             dp[i][j] = max(dp[i - 1][j - damage[i - 1]] + use[i - 1], dp[i - 1][j]);
    //         else
    //             dp[i][j] = dp[i - 1][j];
    //     }
    // }

    // for (int i = 0; i < m; i++) {
    //     cout << dp[n][ques[i]] << endl;
    // }