#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    int n;
    cin >> n;
    int nums[n];
    int ret[4] = {0, 0, 0, 0};  // 0-1周年 1-3周年 2-6周年 3-10周年
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) {
            ret[0] += 1;
        } else if(nums[i] == 2) {

        } else if(nums[i] == 3) {
            ret[1] += 1;
        } else if(nums[i] == 4) {
            ret[0] += 1;
        } else if(nums[i] == 5) {
            ret[0] += 1;
        } else if(nums[i] == 6) {
            ret[0] += 1;
            ret[1] += 1;
            ret[2] += 1;
        } else if(nums[i] <= 8) {
            ret[0] += 1;
            ret[1] += 1;
        } else if(nums[i] == 9) {
            ret[0] += 1;
            ret[1] += 1;
            ret[2] += 1;
        } else if(nums[i] == 10) {
            ret[0] += 1;
            ret[1] += 1;
            ret[2] += 1;
            ret[3] += 1;
        } else if(nums[i] <= 12) {
            ret[0] += 1;
            ret[1] += 1;
            ret[2] += 1;
        } else {
            ret[0] += 1;
            ret[1] += 1;
            ret[2] += 1;
            ret[3] += 1;
        }
    }

    cout << ret[0] << " " << ret[1] << " " << ret[2] << " " << ret[3] << endl;
    return 0;
}