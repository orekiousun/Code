#include<iostream>
using namespace std;

/*
    判断一棵树是否是镜面对称的

    方法：递归
    写一个函数镜面查找即可
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* a, TreeNode* b) : val(x), left(a), right(b) {}
};

bool isTwoTreeMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    else if (left == nullptr || right == nullptr) return false;
    if (left->val != right->val) return false;
    return isTwoTreeMirror(left->left, right->right) && isTwoTreeMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return isTwoTreeMirror(root->left, root->right);
}

int main(int argc, char const *argv[]) {
    TreeNode* A1 = new TreeNode(1);
    TreeNode* A2 = new TreeNode(2);
    TreeNode* A5 = new TreeNode(5);
    TreeNode* A4 = new TreeNode(4, A1, A2);
    TreeNode* A = new TreeNode(3, A4, A4);

    TreeNode* B1 = new TreeNode(1);
    TreeNode* B = new TreeNode(4, B1, nullptr);
    cout << isSymmetric(A) << endl;
    return 0;
}
