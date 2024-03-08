#include<iostream>
using namespace std;
#include<vector>

/*
    给定一棵二叉搜索树，请找出其中第 k 大的节点的值。
    方法：进行反向后续遍历，利用k记录遍历过的节点次数，遍历到第k个节点时结束，返回值
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int k;
    int ans;
    void traverse(TreeNode* root) {
        if(root == nullptr) return;
        traverse(root->right);
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        } 
        traverse(root->left);  
    }
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
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
    int k = 2;
    Solution* op = new Solution();
    cout << op->kthLargest(root, 3) << endl;
    return 0;
}
