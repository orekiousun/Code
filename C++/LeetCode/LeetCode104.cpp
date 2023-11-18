#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    if(root->left != nullptr && root->right != nullptr)
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    else if(root->left != nullptr && root->right == nullptr)
        return 1 + maxDepth(root->left);
    else if(root->right != nullptr && root->left == nullptr)
        return 1 + maxDepth(root->right);
    else
        return 1;
}

int main(int argc, const char** argv) {
    TreeNode* n15 = new TreeNode(15);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n9 = new TreeNode(9);
    TreeNode* n20 = new TreeNode(20, n15, n7);
    TreeNode* n3 = new TreeNode(3, n9, n20);
    cout << maxDepth(n3) << endl;
    return 0;
}