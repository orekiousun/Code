#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
    给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
    每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
    0 <= j <= nums[i]
    i + j < n
    返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
 *
 */

int jump(vector<int>& nums) {
    // 思路：贪心，在能跳到的位置中选择下一步能跳到最远的位置去跳
    int i = 0, n = nums.size(), count = 0;
    if (n == 1) return 0;
    while (i < n) {
        if (i + nums[i] >= n - 1) {
            return count + 1;
        }

        int nextPos = 0, maxDistance = 0;
        for (int j = i; j <= i + nums[i]; ++j) {
            if (j + nums[j] > maxDistance) {
                maxDistance = j + nums[j];
                nextPos = j;
            }
        }
        i = nextPos, count++;
    }

    return count;
}

int main() {
    vector<int> nums{2,3,1,1,4};
    cout << jump(nums) << endl;
    return 0;
}
