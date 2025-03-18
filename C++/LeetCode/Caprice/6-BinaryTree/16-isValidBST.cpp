//
// Created by cd_ouymh on 2025/3/18.
// 验证二叉搜索树：https://www.programmercarl.com/0098.%E9%AA%8C%E8%AF%81%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 验证二叉搜索树：https://leetcode.cn/problems/validate-binary-search-tree/description/
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

// 二叉搜索树：
//      1.节点的左子树只包含小于当前节点的数。
//      2.节点的右子树只包含大于当前节点的数。
//      3.所有左子树和右子树自身必须也是二叉搜索树。
// 注意还需要验证条件1和条件2
// 也可以使用中序遍历，将数据全部遍历出来，最后判断数组有序即可
bool isValidBST(TreeNode* root, long long left, long long right) {
    if (root == nullptr) return true;
    if (root->val <= left or root->val >= right) return false;
    if (root->left and root->left->val >= root->val) return false;
    if (root->right and root->right->val <= root->val) return false;
    return isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
}

int main() {
    return 0;
}
