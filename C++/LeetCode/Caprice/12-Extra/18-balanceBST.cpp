//
// Created by ousun on 2025/10/08.
// 将二叉搜索树变平衡：https://www.programmercarl.com/1382.%E5%B0%86%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E5%8F%98%E5%B9%B3%E8%A1%A1.html
// 将二叉搜索树变平衡：https://leetcode.cn/problems/balance-a-binary-search-tree/
//

#include <iostream>
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

void midTraverse(TreeNode* root, vector<TreeNode*>& vec) {
    if (root == nullptr) return;
    midTraverse(root->left, vec);
    vec.push_back(root);
    midTraverse(root->right, vec);
}

TreeNode* rebuildTree(vector<TreeNode*>& vec, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* root = vec[mid];
    root->left = nullptr, root->right = nullptr;
    if (start == end) return root;
    root->left = rebuildTree(vec, start, mid - 1);
    root->right = rebuildTree(vec, mid + 1, end);
    return root;
}

// 就是先遍历，再重建二叉树。。没有好的递归方法
TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> vec;
    midTraverse(root, vec);
    return rebuildTree(vec, 0, vec.size() - 1);
}

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    n1->right = n2;
    n2->right = n3;
    n3->right = n4;
    TreeNode* root = balanceBST(n1);
    return 0;
}