#include<iostream>
using namespace std;
#include<vector>

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    vector<int> dp(size, -1);
    for (int i = temperatures.size() - 2; i >= 0; i--) {
        int index = i + 1;
        while (index != -1 && temperatures[i] >= temperatures[index]) {
            index = dp[index];
        }
        dp[i] = index;
    } 
    for (int i = 0; i < size; i++) {
        dp[i] = dp[i] == -1 ? 0 : (dp[i] - i);
    }
    return dp;
}

int main() {
    vector<int> temperatures{73,74,75,71,69,72,76,73};
    vector<int> ret = dailyTemperatures(temperatures);
    system("pause");
    return 0;
}