//
// Created by cd_ouymh on 2025/3/11.
// 从中序与后序遍历序列构造二叉树：https://www.programmercarl.com/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.html
// 从中序与后序遍历序列构造二叉树：https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

int findIdx(vector<int>& nums, int number) {
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        if (nums[i] == number) return i;
    }
    return -1;
}

// 通过索引重建树，可以减少一些开销
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int postL, int postR) {
    if (inL > inR || postR > postR) return nullptr;
    TreeNode* root = new TreeNode(postorder[postR]);
    if (inL == inR || postL == postR) return root;
    int pos = findIdx(inorder, postorder[postR]);
    int leftLen = pos - inL - 1;
    TreeNode* left = buildTree(inorder, postorder, inL, pos - 1, postL, postL + leftLen);
    TreeNode* right = buildTree(inorder, postorder, pos + 1, inR, postL + leftLen + 1, postR - 1);
    root->left = left;
    root->right = right;
    return root;
}

// inorder中序遍历（左中右），postorder后序遍历（左右中）
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main() {
    vector<int> inorder{9,3,15,20,7};
    vector<int> postorder{9,15,7,20,3};
    buildTree(inorder, postorder);
    return 0;
}