//
// Created by ousun on 2025/3/7.
// 二叉树的所有路径：https://www.programmercarl.com/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 二叉树的所有路径：https://leetcode.cn/problems/binary-tree-paths/
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

void binaryTreePaths(TreeNode* root, string str, vector<string>& ret) {
    if (root == nullptr) return;
    string nStr = str + str == "" ? to_string(root->val) : "->" + to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) ret.push_back(nStr);
    binaryTreePaths(root->left, nStr, ret);
    binaryTreePaths(root->right, nStr, ret);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    binaryTreePaths(root, "", ret);
    return ret;
}

int main() {

}