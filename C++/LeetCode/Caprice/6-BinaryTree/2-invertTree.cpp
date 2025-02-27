//
// Created by cd_ouymh on 2025/2/27.
// 翻转二叉树：https://www.programmercarl.com/0226.%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 翻转二叉树：https://leetcode.cn/problems/invert-binary-tree/
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

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
}

int main() {
    return 0;
}
