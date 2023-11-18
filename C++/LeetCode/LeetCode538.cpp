#include<iostream>
using namespace std;
#include<vector>

/*
    二叉树中序遍历
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void MidTraverse(TreeNode* root, vector<TreeNode*>& vec) {
    if(root->left != nullptr) {
        MidTraverse(root->left, vec);
    }
    vec.push_back(root);
    if(root->right != nullptr) {
        MidTraverse(root->right, vec);
    }
}

TreeNode* convertBST(TreeNode* root, int overrideflag) {
    if(root == nullptr) return root;
    vector<TreeNode*> vec;
    MidTraverse(root, vec);
    int add = 0;
    for (int i = vec.size() - 1; i >= 0; i--) {
        add += vec[i]->val;
        vec[i]->val = add;
    }
    return root;
}

TreeNode* convertBST(TreeNode* root, int& sum) {
    if(root == nullptr) return root;
    convertBST(root->right);
    sum += root->val;
    root->val = sum;
    convertBST(root->left);
    return root;
}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    return convertBST(root, sum);
}

int main() {
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n7 = new TreeNode(7, nullptr, n8);
    TreeNode* n6 = new TreeNode(6, n5, n7);
    TreeNode* n2 = new TreeNode(2, nullptr, n3);
    TreeNode* n1 = new TreeNode(1, n0, n2);
    TreeNode* root = new TreeNode(4, n1, n6);
    TreeNode* ret = convertBST(root);

    system("pause");
    return 0;
}