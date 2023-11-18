#include<iostream>
using namespace std;
#include<vector>

/*
    提供二叉树的前序遍历和中序遍历，构建一颗二叉树
    利用分治的思想，将遍历数组分段，再递归调用
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
    TreeNode* root = new TreeNode(preorder[preLeft]);
    if(preLeft == preRight) return root;
    int size = 0;
    for (int i = inLeft; i <= inRight; i++) {
        if(inorder[i] == root->val) {
            size = i - inLeft;
            break;
        }
    }
    root->left = size == 0 ? nullptr : buildTree(preorder, inorder, preLeft + 1, preLeft + size, inLeft, inLeft + size - 1);
    root->right = inLeft + size + 1 > inRight ? nullptr : buildTree(preorder, inorder, preLeft + size + 1, preRight, inLeft + size + 1, inRight);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty()) return nullptr;
    return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main(int argc, char const *argv[]) {
    // TreeNode* n7 = new TreeNode(7);
    // TreeNode* n15 = new TreeNode(15);
    // TreeNode* n9 = new TreeNode(9);
    // TreeNode* n20 = new TreeNode(20, n15, n7);
    // TreeNode* n3 = new TreeNode(20, n9, n20);
    vector<int> preorder{1, 2};
    vector<int> inorder{2, 1};
    TreeNode* root = buildTree(preorder, inorder);

    return 0;
}
