//
// Created by ousun on 2025/3/22.
// 二叉树的最近公共祖先：https://www.programmercarl.com/0236.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 二叉树的最近公共祖先：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
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

// 查找节点，在左边找到了返回true，否则返回false
bool findNode(TreeNode* root, TreeNode* node) {
    if (root == node) return true;
    if (root->left == nullptr && root->right == nullptr) return false;
    if (root->left == nullptr) return findNode(root->right, node);
    if (root->right == nullptr) return findNode(root->left, node);
    return findNode(root->left, node) || findNode(root->right, node);
}

// 法一-多次递归查找，逻辑比较简单，但是时间复杂度高
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p == root || root == q || root == nullptr) return root;
    else if (p == q) return p;

    if (root->left == nullptr) return lowestCommonAncestor(root->right, p, q);
    if (root->right == nullptr) return lowestCommonAncestor(root->left, p, q);
    // 先找p,q分别在左子树还是右子树，进一步缩小范围
    bool pInLeft = findNode(root->left, p);
    bool qInLeft = findNode(root->left, q);
    if (pInLeft and qInLeft) return lowestCommonAncestor(root->left, p, q);
    else if(pInLeft == false and qInLeft == false) return lowestCommonAncestor(root->right, p, q);
    else return root;
}

// 官方解法
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == q || root == p || root == nullptr) return root;
    // 这其实是一个查找的过程，查找在左子树和右子树中有没有p,q中的任意一个
    // 如果左右子树中都找到了，说明p,q分别分布在左右子树中，返回root
    // 如果在一侧找到了，就返回一侧找到的结果
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) return root;
    if (left == nullptr) return right;
    return left;
}

int main() {
    return 0;
}
