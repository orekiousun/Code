#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*
    参考力扣股票问题
*/

vector<int> getEmotion(vector<int>& prices) {
    int size = prices.size();
    vector<int> ans(size, 0);
    ans[size - 1] = 0;
    for (int i = size - 2; i >= 0 ; i--) {
        if(prices[i + 1] > prices[i]) ans[i] = 0;
        else {
            int temp = prices[i] - prices[i - 1], j = i + 1;
            while (j < size && prices[j] <= prices[i]) {
                temp = max(temp, prices[i] - prices[j]);
                j++;
            }
            ans[i] = temp;
        }
    }
    return ans;
}

int main(int argc, const char** argv) {
    system("pause");
    return 0;
}