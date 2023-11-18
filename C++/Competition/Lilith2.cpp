#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>

long long ans(vector<int>& array, int k) {
    sort(array.begin(), array.end());
    // 表示小于等于 i 的数的个数
    unordered_map<int, int> count;

    for (int i = 0; i < array.size(); i++) {
        count[array[i]] = i + 1;
    }

    vector<long long> dp(array.size() + 1, 0);
    for (int i = 2; i <= array.size(); i++) {
        if(array[i - 1] < k) {
            int j = i - 2;
            if(array[i - 1] * 2 <= k)
                dp[i] = dp[i - 1] + i - 1;
            else {
                if(count.find(k - array[i - 1]) != count.end()) {
                    dp[i] = dp[i - 1] + count[k - array[i - 1]];
                }
                else {
                    int z = i - 2;
                    while (z >= 0 && array[z] + array[i - 1] > k) {
                        z--;
                    }
                    dp[i] = dp[i - 1] + z + 1;
                }
            }
        }
        else {
            return dp[i - 1];
        }
    }
    return dp[array.size()];
}

int main(int argc, const char** argv) {
    vector<int> array{1, 2, 1, 2, 3};
    cout << ans(array, 4) << endl;
    return 0;
}