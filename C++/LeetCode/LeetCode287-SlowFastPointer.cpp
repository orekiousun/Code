#include<iostream>
using namespace std;
#include<vector>

/*
    利用位数建立映射关系，从而创建一张图
    比如数列为 1 3 4 2 2
    则图从0开始
    0-1-3-2-4-2-4 ... 开始出现环
    再利用双指针判环
*/

int findDuplicate(vector<int>& nums) {
    int fast = 0, slow = 0;
    slow = nums[slow];
    fast = nums[nums[fast]];
    while (fast != slow) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    // 成功入环，此时fast = slow = 环中的一个点
    // 下一步开始让fast和slow都回到相遇点
    /*
        假设环长为L，从起点到环入口的步数为a，从环入口继续走b到达相遇位置，从相遇位置继续走c回到环入口
        慢指针：走a+b步到达相遇位置   快指针：走了2(a + b)步
        所以有 2(a + b) = a + b + kL，得到 a + b = kL
        已知环的入口即为重复元素(同时有两个值指向环的入口)
        又 b = L - c，则有 a = (k - 1)L + c
        所有此时一节点从0位置开始走，一节点从相遇位置开始走，两节点每次都走一步，最终都走a步，会在环的入口相遇
    */
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector<int> nums{1, 3, 4, 2, 2};
    cout << findDuplicate(nums) << endl;
    system("pause");
    return 0;
}