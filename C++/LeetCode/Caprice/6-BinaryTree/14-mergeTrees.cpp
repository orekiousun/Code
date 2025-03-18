//
// Created by cd_ouymh on 2025/3/18.
// 合并二叉树：https://www.programmercarl.com/0617.%E5%90%88%E5%B9%B6%E4%BA%8C%E5%8F%89%E6%A0%91.html
// 合并二叉树：https://leetcode.cn/problems/merge-two-binary-trees/
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

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) return nullptr;
    int sum = 0;
    if (root1) sum += root1->val;
    if (root2) sum += root2->val;
    TreeNode* nRoot = root1 ? root1 : root2;
    nRoot->val = sum;
    nRoot->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
    nRoot->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
    return nRoot;
}

int main() {
    return 0;
}