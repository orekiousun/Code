#include<iostream>
using namespace std;
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void MidTraverse(TreeNode* root, vector<int>& ans) {
    if(root->left != nullptr) MidTraverse(root->left, ans);
    ans.push_back(root->val);
    if(root->right != nullptr) MidTraverse(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    MidTraverse(root, ans);
    return ans;
}

int main() {
    TreeNode* r1 = new TreeNode(1);
    TreeNode* r3 = new TreeNode(3);
    TreeNode* r6 = new TreeNode(6);
    TreeNode* r4 = new TreeNode(4, r3, r6);
    TreeNode* root = new TreeNode(5, r1, r4);
    vector<int> ans = inorderTraversal(root);
    system("pause");
    return 0;
}