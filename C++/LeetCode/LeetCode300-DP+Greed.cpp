#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    动态规划
*/
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

/*
    贪心：
    我们维护一个数组d[i]，表示长度为i的最长上升子序列的末尾元素的最小值
    如果nums[i]>d[len]，则直接加入到d数组末尾，并更新len=len+1    
    否则，在d数组中二分查找，找到第一个比nums[i]小的数d[k]并更新d[k+1]=nums[i]
*/
int lengthOfLIS2(vector<int>& nums) {
    int len = 1, n = (int)nums.size();
    if (n == 0) {
        return 0;
    }
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > d[len]) {
            d[++len] = nums[i];
        } else {
            int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (d[mid] < nums[i]) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            d[pos + 1] = nums[i];
        }
    }
    return len;
}


int main() {
    vector<int> nums;
    cout << lengthOfLIS(nums) << endl;
    system("pause");
    return 0;
}