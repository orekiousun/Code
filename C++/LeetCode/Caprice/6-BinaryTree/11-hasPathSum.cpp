//
// Created by cd_ouymh on 2025/3/11.
// 路径总和：https://www.programmercarl.com/0112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.html
// 路径总和：https://leetcode.cn/problems/path-sum/
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    if (targetSum - root->val == 0 && root->left == nullptr && root->right == nullptr) return true;
    int sum = targetSum - root->val;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

int main() {
    return 0;
}