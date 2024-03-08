#include<iostream>
using namespace std;

/*
    对一棵树进行镜面翻转

    方法：
        递归
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* a, TreeNode* b) : val(x), left(a), right(b) {}
};

TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);
    return root;
}

int main(int argc, char const *argv[]) {
    TreeNode* A1 = new TreeNode(1);
    TreeNode* A2 = new TreeNode(2);
    TreeNode* A5 = new TreeNode(5);
    TreeNode* A4 = new TreeNode(4, A1, A2);
    TreeNode* A = new TreeNode(3, A4, A5);

    TreeNode* B1 = new TreeNode(1);
    TreeNode* B = new TreeNode(4, B1, nullptr);
    TreeNode* mirror = mirrorTree(A);
    return 0;
}
