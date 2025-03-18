//
// Created by cd_ouymh on 2025/3/18.
// 二叉搜索树中的搜索：https://www.programmercarl.com/0700.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E6%90%9C%E7%B4%A2.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 二叉搜索树中的搜索：https://leetcode.cn/problems/search-in-a-binary-search-tree/
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

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) return nullptr;
    else if (val == root->val) return  root;
    else if (val > root->val) return searchBST(root->right, val);
    else return searchBST(root->left, val);
}

int main() {
    return 0;
}
