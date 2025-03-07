//
// Created by ousun on 2025/3/7.
// 平衡二叉树：https://www.programmercarl.com/0110.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 平衡二叉树：https://leetcode.cn/problems/balanced-binary-tree/
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

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// 存在重复递归的问题，可以优化
bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced((root->right));
}

// 返回以该节点为根节点的二叉树的高度，如果不是平衡二叉树了则返回-1，在遍历子节点高度的同时通过区分返回值判断了是否是平衡二叉树
int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    if (leftHeight == -1) return -1;
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1) return -1;
    return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
}

bool isBalanced2(TreeNode* root) {
    return getHeight(root) == -1 ? false : true;
}

int main() {
    return 0;
}
