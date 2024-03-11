#include<iostream>
using namespace std;
#include<vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void DFS(TreeNode* node, int curVal, int& maxVal, vector<int> curPath, vector<int>& maxPath) {
    curPath.push_back(node->val);
    curVal += node->val;
    if (node->left == nullptr && node->right == nullptr) {
        if (curVal > maxVal) {
            maxPath = curPath;
            maxVal = curVal;
        }
    }

    if (node->left != nullptr) {
        DFS(node->left, curVal, maxVal, curPath, maxPath);
    }
    if (node->right != nullptr) {
        DFS(node->right, curVal, maxVal, curPath, maxPath);
    }
}

vector<int> maxPath(TreeNode* root) {
    vector<int> res;
    vector<int> curPath;
    if (root == nullptr)
        return res;

    int maxVal = INT_MIN;
    DFS(root, 0, maxVal, curPath, res);
    return res;
}

int main() {

    TreeNode* l1 = new TreeNode(2);
    TreeNode* l2 = new TreeNode(5);
    TreeNode* l3 = new TreeNode(6);
    TreeNode* l4 = new TreeNode(-1);
    TreeNode* l5 = new TreeNode(3);
    TreeNode* l6 = new TreeNode(-5);

    TreeNode* root = new TreeNode(4);
    root->left = l4;
    l4->left = l1;
    l4->right = l2;
    l1->left = l5;
    l1->right = l3;
    l3->left = l6;
    vector<int> res = maxPath(root);

    return 0;
}
