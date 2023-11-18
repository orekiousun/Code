#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>
#include<cmath>
#include<unordered_map>

/*
    题目一：输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
    方法：
        1.层序遍历
        2.空间优化：采用递归(递归的本质还是使用了栈空间，所以空间也没有优化多少)
    
    题目二：输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
    方法：
        1.直接获取左右子树最大高度，比较
        2.遍历一遍，保存所有结果中左右子树最大高度，比较
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// int maxDepth(TreeNode* root) {
//     if(root == nullptr) return 0;
//     queue<TreeNode*> q;
//     q.push(root);
//     int depth = 0;
//     while (!q.empty()) {
//         int len = q.size();
//         while (len--) {
//             TreeNode* front = q.front();
//             if(front->left != nullptr) q.push(front->left);
//             if(front->right != nullptr) q.push(front->right);
//             q.pop();
//         }
//         depth++;
//     }
//     return depth;
// }

int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        bool ans = isBalanced(root->left) && isBalanced(root->right);
        int left = maxDepth(root->left), right = maxDepth(root->right);
        if(abs(left - right) > 1) return false;
        return ans;
    }
};

class Solution2 {
public:
    unordered_map<TreeNode*, int> depth;
    bool ans;

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int dep = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        depth[root] = dep;
        return dep;
    }

    void traverse(TreeNode* root) {
        if(root == nullptr) return;
        traverse(root->left);
        int leftDepth = root->left == nullptr ? 0 : depth[root->left];
        int rightDepth = root->right == nullptr ? 0 : depth[root->right];
        if(abs(leftDepth - rightDepth) > 1) ans = false;
        traverse(root->right);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        ans = true;
        maxDepth(root);
        traverse(root);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    TreeNode* root = new TreeNode(3);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n4 = new TreeNode(4);
    root->left = n1, root->right = n4;
    n1->right = n2;
    cout << maxDepth(root) << endl;
    return 0;
}
