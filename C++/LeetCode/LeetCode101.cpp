#include<iostream>
using namespace std;
#include<vector>
#include<queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void levelTraverse(TreeNode* root, vector<int>& res, bool flag) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        if(temp != nullptr) {
            res.push_back(temp->val);
            if(flag) {
                q.push(temp->left);
                q.push(temp->right);
            }
            else {
                q.push(temp->right);
                q.push(temp->left);
            }
        }
        else {
            res.push_back(-101);
        }
        q.pop();
    }
}

bool isSymmetric(TreeNode* root) {
    TreeNode* leftTree;
    TreeNode* rightTree;
    vector<int> res1, res2;
    if (root->left == nullptr && root->right == nullptr)  return true;
    if (root->left != nullptr && root->right != nullptr) {
        leftTree = root->left;
        rightTree = root->right;
        levelTraverse(leftTree, res1, false);
        levelTraverse(rightTree, res2, true);
    }
    else return false;
    if(res1.size() != res2.size()) return false;
    for (int i = 0; i < res1.size(); i++) {
        if(res1[i] != res2[i]) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    TreeNode* l3 = new TreeNode(3);
    TreeNode* r3 = new TreeNode(3);
    TreeNode* l2 = new TreeNode(2, nullptr, l3);
    TreeNode* r2 = new TreeNode(2, nullptr, r3);
    TreeNode* root = new TreeNode(1, l2, r2);
    cout << isSymmetric(root) << endl;
    system("pause");
    return 0;
}
