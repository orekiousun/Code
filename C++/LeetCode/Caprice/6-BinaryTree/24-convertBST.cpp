//
// Created by ousun on 2025/3/29.
// 把二叉搜索树转换为累加树：https://www.programmercarl.com/0538.%E6%8A%8A%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E8%BD%AC%E6%8D%A2%E4%B8%BA%E7%B4%AF%E5%8A%A0%E6%A0%91.html
// 把二叉搜索树转换为累加树：https://leetcode.cn/problems/convert-bst-to-greater-tree/description/
//

#include <iostream>
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

TreeNode* convertBST(TreeNode* root, int& curVal) {
    if (root == nullptr) return root;
    root->right = convertBST(root->right, curVal);
    root->val = root->val + curVal;
    curVal = root->val;
    root->left = convertBST(root->left, curVal);
    return root;
}

TreeNode* convertBST(TreeNode* root) {
    int curVal = 0;
    return convertBST(root, curVal);
}

int main() {
    return 0;
}