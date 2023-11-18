#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<cmath>
#include<functional>
#include<unordered_map>
#include<numeric>

int findMaxNum(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] > nums[i + 1])
            return nums[i];
    }
    return nums[nums.size() - 1];
}

vector<int> repeat0(vector<int>& nums) {
    int count = 0;
    for(auto item : nums) {
        if(item == 0) count++;
    }
    
    vector<int> ans(nums.size() + count, 0);
    int i = 0;
    for(auto item : nums) {
        ans[i++] = item;
        if(item == 0)
            i++;
    }
    return ans;
}

#pragma region 将一个数组分为和相等的k个子数组
bool backtrack(vector<int>& nums, vector<bool>& visited, int k, int current, int target, int groups, int start_index) {
    if (groups == k) return true;
    if (current == target) return backtrack(nums, visited, k, 0, target, groups + 1, 0);
    for (int i = start_index; i < nums.size(); i++) {
        if (!visited[i] && current + nums[i] <= target) {
            visited[i] = true;
            if (backtrack(nums, visited, k, current + nums[i], target, groups, i + 1)) return true;
            visited[i] = false;
        }
    }
    return false;
}

bool divideNums(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % k != 0) return false;
    int add = sum / k;
    sort(nums.begin(), nums.end());
    if(nums[nums.size() - 1] > add) return false;
    vector<bool> visited(nums.size(), false);
    return backtrack(nums, visited, k, 0, add, 0, 0);
}
#pragma endregion

int maxDamage(int k1, int k2, int d1, int d2, int t) {
    // 1跟随2攻击
    int ans = d1 + d2;                           // 一开始时，1和2均攻击1次
    if(k1 < k2) {
        // 如果1的冷却小于2的冷却，则在2的冷却期间，1尽可能的多攻击
        int damage = (k2 / k1) * d1 + d2 + d1;   // 计算一次2的冷却期间造成的伤害
        ans += damage * (t / k2);                // 计算2一共能进行多少次攻击
        ans += t % k2 / k1 * d1;                 // 剩下的时间1继续执行攻击
    }
    else {
        // 如果1的冷却时间大于2的冷却时间，则1跟随2进行攻击即可
        ans += t / k2 * (d1 + d2);
    }
    return ans;
}

float maxDamage(int k1, int k2, int d1, int d2, int t, int x) {
    // 1和2同时攻击会获得额外增伤

    // 思路一：尽量使用增伤策略
    float ans1 = (d1 + d2) + (d1 + d2) * x / 100;                           // 一开始时，1和2均攻击1次
    if(k1 < k2) {
        // 如果2的冷却更大，则尽可能让1在2的冷却期间多进行攻击的同时，2在攻击时1也攻击
        float damage = (k2 / k1 - 1) * d1 + (d1 + d2) + (d1 + d2) * x / 100;
        ans1 += damage * (t / k2);                                          // 计算2一共能进行多少次攻击
        ans1 += t % k2 / k1 * d1;                                           // 剩下的时间1继续执行攻击
    }
    else {
        float damage = (k1 / k2 - 1) * d2 + (d2 + d1) + (d2 + d1) * x / 100;
        ans1 += damage * (t / k1);                                         
        ans1 += t % k1 / k2 * d2;   
    }

    // 思路二：各打各的，采用模拟的方法
    int time = 0;
    int CD1 = 0, CD2 = 0;
    float ans2 = 0.0;
    while (time < t) {
        if(CD1 > 0) CD1--;
        if(CD2 > 0) CD2--;
        
        if(CD1 == 0 && CD2 == 0) {
            ans2 += (d1 + d2) * x / 100;
        }
        if(CD1 == 0) {
            ans2 += d1;
            CD1 = k1;
        }
        if(CD2 == 0) {
            ans2 += d2;
            CD2 = k2;
        }
        time++;
    }
    return max(ans1, ans2);
}

int main(int argc, char const *argv[]) {
    vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    cout << divideNums(nums, 4);

    return 0;
}
