#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int numSquares(int n) {
    vector<int> nums;
    nums.resize(n + 1, 0);
    for (int i = 0; i * i <= n; i++) {
        nums[i * i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if(nums[i] == 0) {
            int temp = i;
            for(int j = 1; j * j < i; j++) {
                temp = min(temp, nums[j * j] + nums[i - j * j]);
            }
            nums[i] = temp;
        }
    }
    return nums[n];
}

int main() {
    cout << numSquares(2513) << endl;
    system("pause");
    return 0;
}