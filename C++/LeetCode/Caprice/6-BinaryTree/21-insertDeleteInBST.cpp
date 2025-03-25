//
// Created by cd_ouymh on 2025/3/25.
// 二叉搜索树的插入操作：https://www.programmercarl.com/0701.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E6%8F%92%E5%85%A5%E6%93%8D%E4%BD%9C.html
// 二叉搜索树的插入操作：https://leetcode.cn/problems/insert-into-a-binary-search-tree/
// 二叉搜索树的删除操作：https://www.programmercarl.com/0450.%E5%88%A0%E9%99%A4%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 二叉搜索树的删除操作：https://leetcode.cn/problems/delete-node-in-a-bst/
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

// 插入
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

// 删除Bst中的根节点
// 法一：将根节点和左子树中的最大节点或右子树的最小节点替换
TreeNode* deleteRootInBst(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) return nullptr;
    TreeNode* node;
    if (root->left != nullptr) {
        if (root->left->right == nullptr) {
            root->left->right = root->right;
            return root->left;
        }
        else {
            node = root->left;
            TreeNode* preNode;
            while (node->right != nullptr) {
                preNode = node;
                node = node->right;
            }
            preNode->right = deleteRootInBst(preNode->right);
            node->left = root->left;
            node->right = root->right;
            return node;
        }
    }
    else {
        if (root->right->left == nullptr) {
            root->right->left = root->left;
            return root->right;
        }
        else {
            node = root->right;
            TreeNode* preNode;
            while (node->left != nullptr) {
                preNode = node;
                node = node->left;
            }
            preNode->left = deleteRootInBst(preNode->left);
            node->left = root->left;
            node->right = root->right;
            return node;
        }
    }
}

// 删除Bst中的根节点-###更简单###
// 法二：删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点
TreeNode* deleteRootInBst1(TreeNode* root) {
    if (root->right == nullptr) return root->left;
    TreeNode* node = root->right;
    while (node->left != nullptr) {
        node = node->left;
    }
    node->left = root->left;
    return root->right;
}

// 删除
TreeNode* deleteNodeInBst(TreeNode* root, int key) {
    if (root == nullptr) return root;
    if (key < root->val) root->left = deleteNodeInBst(root->left, key);
    else if (key > root->val) root->right = deleteNodeInBst(root->right, key);
    else return deleteRootInBst(root);
    return root;
}

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    n1->right = n2;
    deleteRootInBst(n1);
    return 0;
}
