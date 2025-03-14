//
// Created by ousun on 2025/3/14.
// 最大二叉树：https://www.programmercarl.com/0654.%E6%9C%80%E5%A4%A7%E4%BA%8C%E5%8F%89%E6%A0%91.html
// 最大二叉树：https://leetcode.cn/problems/maximum-binary-tree/
//

#include <iostream>
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findMaxIdx(vector<int>& nums, int left, int right) {
    if (left > right) return -1;
    int maxIdx = left;
    for (int i = left; i <= right; ++i) {
        if (nums[i] >= nums[maxIdx]) maxIdx = i;
    }
    return maxIdx;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int maxIdx = findMaxIdx(nums, l, r);
    TreeNode* node = new TreeNode(nums[maxIdx]);
    node->left = constructMaximumBinaryTree(nums, l, maxIdx - 1);
    node->right = constructMaximumBinaryTree(nums, maxIdx + 1, r);
    return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
}

int main() {
    return 0;
}