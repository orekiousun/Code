//
// Created by ousun on 2024/11/23.
// 长度最小的子数组：https://www.programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html#%E6%80%9D%E8%B7%AF
// 长度最小的子数组：https://leetcode.cn/problems/minimum-size-subarray-sum/
// 水果成篮：https://leetcode.cn/problems/fruit-into-baskets/description/
// 最小覆盖度子串：https://leetcode.cn/problems/minimum-window-substring/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

// 长度最小的子数组-滑动窗口
// https://leetcode.cn/problems/minimum-size-subarray-sum/
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0, size = nums.size();
    int sum = 0;
    int ret = 0;
    while (right < size) {
        sum += nums[right];
        while (sum >= target) {
            int len = right - left + 1;
            ret = ret == 0 ? len : min(ret, len);
            sum -= nums[left++];
        }
        right++;
    }

    return ret;
}

// 水果成篮-即找到一个出现的类型个数小于等于2的最长子串
// https://leetcode.cn/problems/fruit-into-baskets/
int totalFruit(vector<int>& fruits) {
    int size = fruits.size(), left = 0, right = 0;
    int recordNum = 0;
    int recordMaxNum = 2;
    int ret = 0;
    unordered_map<int, int> recordMap;
    while (right < size) {
        int type = fruits[right];

        // 记录类型数据
        if (recordMap[type] == 0)
            recordNum++;
        recordMap[type]++;

        // 判断是否超过上限，进行窗口滑动
        while (recordNum > recordMaxNum) {
            int leftType = fruits[left++];
            recordMap[leftType]--;
            if (recordMap[leftType] == 0)
                recordNum--;
        }

        ret = max(ret, right - left + 1);
        right++;
    }

    return ret;
}

// 水果成篮-通过移除哈希表键值对实现
// https://leetcode.cn/problems/fruit-into-baskets/
int totalFruit2(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int, int> cnt;

    int left = 0, ans = 0;
    for (int right = 0; right < n; ++right) {
        ++cnt[fruits[right]];
        while (cnt.size() > 2) {
            auto it = cnt.find(fruits[left]);
            --it->second;
            if (it->second == 0) {
                cnt.erase(it); // 移除哈希表键值对，可以节省一定空间
            }
            ++left;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

bool check(unordered_map<char, int>& sMap, unordered_map<char, int>& tMap) {
    for(auto v : tMap) {
        if (sMap[v.first] < v.second)
            return false;
    }

    return true;
}

// 最小覆盖度子串
// https://leetcode.cn/problems/minimum-window-substring/
string minWindow(string s, string t) {
    unordered_map<char, int> tMap;
    for (auto v : t) {
        tMap[v]++;
    }
    unordered_map<char, int> sMap;
    int l = 0, r = -1;
    int len = INT_MAX, ansL = -1;
    int size = s.size();
    while (r < size) {
        if (tMap.find(s[++r]) != tMap.end()) {
            ++sMap[s[r]];
        }
        while (check(sMap, tMap) && l <= r) {
            if (r - l + 1 < len) {
                len = r - l + 1;
                ansL = l;
            }
            if (tMap.find(s[l]) != tMap.end()) {
                --sMap[s[l]];
            }
            ++l;
        }
    }

    return ansL == -1 ? string() : s.substr(ansL, len);
}

int main() {
    vector<int> nums{2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << minSubArrayLen(target, nums) << endl;
    vector<int> fruits{3,3,3,1,2,1,1,2,3,3,4};
    cout << totalFruit(fruits) << endl;
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
