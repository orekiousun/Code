//
// Created by ousun on 2025/3/22.
// 二叉搜索树的最小绝对差：https://www.programmercarl.com/0530.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E7%BB%9D%E5%AF%B9%E5%B7%AE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 二叉搜索树的最小绝对差：
//

#include <iostream>
using namespace std;
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void midTraverse(TreeNode* root, int& preNum, int& ret) {
    if (root == nullptr) return;
    midTraverse(root->left, preNum, ret);
    // 首次进入，更新preNum，初始化ret
    if (ret == -1) preNum = root->val, ret = INT_MAX;
    else ret = min(abs(root->val - preNum), ret), preNum = root->val;
    midTraverse(root->right, preNum, ret);
}

// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
// 差值是一个正数，其数值等于两值之差的绝对值。
// 中序遍历，边遍历边求插值
int getMinimumDifference(TreeNode* root) {
    int preNum = 0, ret = -1;
    midTraverse(root, preNum, ret);
    return ret;
}

int main() {
    return 0;
}
