//
// Created by cd_ouymh on 2025/3/24.
// 二叉搜索树的最近公共祖先：https://www.programmercarl.com/0235.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.html
// 二叉搜索树的最近公共祖先：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestorInBst(TreeNode* root, int& minVal, int& maxVal) {
    if (root->val == minVal || root->val == maxVal) return root;
    if (root->val > minVal && root->val < maxVal) return root;
    if (root->val < minVal && root->right != nullptr)
        return lowestCommonAncestorInBst(root->right, minVal, maxVal);
    if (root->val > maxVal && root->left != nullptr)
        return lowestCommonAncestorInBst(root->left, minVal, maxVal);
    return nullptr;
}

// 二叉搜索树，可以通过节点值判断最小公共祖先，也可以使用传统的二叉树最小公共祖先算法
// 这里使用通过节点值判断最小公共祖先大方法，其实本质是查找节点值val，val >= p.val && val <= q.val
TreeNode* lowestCommonAncestorInBst(TreeNode* root, TreeNode* p, TreeNode* q) {
    int minVal = min(p->val, q->val);
    int maxVal = max(p->val, q->val);
    return lowestCommonAncestorInBst(root, minVal, maxVal);
}

int main() {
    return 0;
}