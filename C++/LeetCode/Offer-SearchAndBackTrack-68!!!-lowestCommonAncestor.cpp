#include<iostream>
using namespace std;
#include<vector>

/*
    题目一：
        给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

    题目二：
        给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

    思路：很巧妙！！！
        先假设左右分别为新的跟节点，再分别在左右子树中递归寻找公共祖先
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left == nullptr && right == nullptr) return nullptr; // 1.
    if(left == nullptr) return right; // 3.
    if(right == nullptr) return left; // 4.
    return root; // 2. if(left != null and right != null)
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
