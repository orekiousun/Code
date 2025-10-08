//
// Created by ousun on 2025/10/08.
// 求根节点到叶节点数字之和：https://www.programmercarl.com/0129.%E6%B1%82%E6%A0%B9%E5%88%B0%E5%8F%B6%E5%AD%90%E8%8A%82%E7%82%B9%E6%95%B0%E5%AD%97%E4%B9%8B%E5%92%8C.html
// 求根节点到叶节点数字之和：https://leetcode.cn/problems/sum-root-to-leaf-numbers/
//

#include <iostream>
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

void backtrack(int &sum, int curSum, TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) {
        sum += curSum;
        return;
    }

    if (root->left) backtrack(sum, curSum * 10 + root->left->val, root->left);
    if (root->right) backtrack(sum, curSum * 10 + root->right->val, root->right);
}

int sumNumbers(TreeNode* root) {
    int sum = 0;
    backtrack(sum, root->val, root);
    return sum;
}

int main() {
    return 0;
}