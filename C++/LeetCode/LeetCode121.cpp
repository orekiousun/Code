#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<algorithm>

int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int ans = 0;
    stack<int> s;
    s.push(prices[size  - 1]);
    for (int i = size - 2; i >= 0; i--) {
        if(prices[i] > s.top())
            s.push(prices[i]);
        else
            ans = max(s.top() - prices[i], ans);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> prices{7, 1, 5, 3, 6 ,4};
    cout << maxProfit(prices) << endl;
    return 0;
}
