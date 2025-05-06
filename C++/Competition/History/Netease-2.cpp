#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    int n = 3;
    int nums[3] = {3,6,19};
    int maxNum = 0;
    for (int i = 0; i < n; ++i) {
        maxNum = max(maxNum, nums[i]);
    }

    int dp_add[maxNum + 1];  // 最后一位是复制一位复制来的
    int dp_copy[maxNum + 1]; // 最后一位是复制一串复制来的
    dp_add[1] = 0;
    dp_copy[1] = 0;
    dp_add[2] = 3;
    dp_copy[2] = 3;
    dp_add[3] = 4;
    dp_copy[3] = INT_MAX;

    for (int i = 4; i <= maxNum; ++i) {
        if (i % 2 == 0) {
            dp_add[i] = dp_add[i - 1] + 1;
            dp_copy[i] = min(dp_copy[i / 2], dp_add[i / 2]) + 3;
        } else {
            dp_add[i] = min(dp_add[i - 1] + 1, min(dp_copy[i / 2], dp_add[i / 2]) + 6);
            dp_copy[i] = INT_MAX;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << min(dp_add[nums[i]], dp_copy[nums[i]]) << endl;
    }

    return 0;
}