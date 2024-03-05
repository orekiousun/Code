#include<vector>
using namespace std;

/*
    给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径
    深度遍历（栈实现）
    节点数可以为负值
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void pathSum(TreeNode* root, int target, vector<int>& temp, vector<vector<int>>& ans) {
    if(root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        if (target == root->val) {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
        }
        return;
    }
    temp.push_back(root->val);
    pathSum(root->left, target - root->val, temp, ans);
    pathSum(root->right, target - root->val, temp, ans);
    temp.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int target) {
    vector<int> temp;
    vector<vector<int>> ans;
    pathSum(root, target, temp, ans);
    return ans;
}

int main(int argc, char const *argv[]) {
    TreeNode* r1 = new TreeNode(5);
    TreeNode* r2 = new TreeNode(2);
    TreeNode* r3 = new TreeNode(6);
    TreeNode* r4 = new TreeNode(6);
    TreeNode* r5 = new TreeNode(5, r1, r2);
    TreeNode* r51 = new TreeNode(4, r3, r4);
    TreeNode* root = new TreeNode(0, r5, r51);
    vector<vector<int>> ans = pathSum(root, 10);
    return 0;
}
