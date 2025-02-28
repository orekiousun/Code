//
// Created by ousun on 2025/2/28.
// 对称二叉树：https://www.programmercarl.com/0101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 对称二叉树：https://leetcode.cn/problems/symmetric-tree/
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

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr or right == nullptr) return false;
    if (left->val != right->val) return false;
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

// 递归法，如果用迭代法的话，需要用栈活动队列记录两个子树的样子再迭代
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return isSymmetric(root->left, root->right);
}

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    n1->left = n2, n1->right = n3;
    n2->left = n4, n2->right = n5;
    n3->left = n6, n3->right = n7;
    return 0;
}