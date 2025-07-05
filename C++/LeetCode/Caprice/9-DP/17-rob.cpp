//
// Created by ousun on 2025/07/05.
// 打家劫舍：https://www.programmercarl.com/0198.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 打家劫舍：https://leetcode.cn/problems/house-robber/
// 打家劫舍II：https://www.programmercarl.com/0213.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DII.html
// 打家劫舍II：https://leetcode.cn/problems/house-robber-ii/description/
// 打家劫舍III：https://www.programmercarl.com/0337.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DIII.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 打家劫舍III：https://leetcode.cn/problems/house-robber-iii/description/
//

/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。  
 */

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 不能偷相邻的房间
int rob(vector<int> &nums) {
    int size = nums.size();
    if (size == 0) return 0;
    if (size == 1) return nums[0]; 
    // 偷前n家的最大金额
    vector<int> dp(size, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[size - 1];
}

// 房间围成一圈，不能偷相邻的房间
// 分别计算偷 0 - n-1 和 1 - n 家的最大值，再取最大值
// 这样就可以保证不会同时偷到首和尾
int rob2(vector<int> &nums) {
    int size = nums.size();
    if (size == 0) return 0;
    if (size == 1) return nums[0];
    vector<int> numsLeft(nums.begin(), nums.end() - 1);
    vector<int> numsRight(nums.begin() + 1, nums.end());
    return max(rob(numsLeft), rob(numsRight));
}

// 思路是正确的，记忆化递归
// 后续遍历打劫，边打劫边记录对应根节点的最大金额
void backTraverse(
    TreeNode* root, 
    unordered_map<TreeNode*, int>& withRoot, 
    unordered_map<TreeNode*, int>& withoutRoot
) {
    if (root == nullptr) return;
    backTraverse(root->left, withRoot, withoutRoot);
    backTraverse(root->right, withRoot, withoutRoot);
    withoutRoot[root] = 0;
    withRoot[root] = root->val;
    if (root->left) {
        withoutRoot[root] += withRoot[root->left];
        withRoot[root] += withoutRoot[root->left];
    }
    if (root->right) {
        withoutRoot[root] += withRoot[root->right];
        withRoot[root] += withoutRoot[root->right];
    }
    // withRoot的结果需要始终保持最大值，这样可以保证后续的计算结果也始终是最大值
    withRoot[root] = max(withRoot[root], withoutRoot[root]);
}

// 二叉树打劫，不能打劫相邻的节点
int rob3(TreeNode* root) {
    if (root == nullptr) return 0;
    unordered_map<TreeNode*, int> withRoot;
    unordered_map<TreeNode*, int> withoutRoot;
    backTraverse(root, withRoot, withoutRoot);
    return withRoot[root];
}

int main(){
    vector<int> nums{9, 4, 1, 1, 9};
    cout << rob2(nums) << endl;
    return 0;
}