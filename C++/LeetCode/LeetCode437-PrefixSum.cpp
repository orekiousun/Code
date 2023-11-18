#include<iostream>
using namespace std;
#include<queue>
#include<unordered_map>
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 记录所有的前缀和，只要差值为8，就可以ret++
int dfs(TreeNode *root, unordered_map<long long, int>& prefix, long long curr, int targetSum) {
    if (!root) return 0;
    int ret = 0;
    curr += root->val;
    if (prefix.count(curr - targetSum))
        ret = prefix[curr - targetSum];

    prefix[curr]++;
    ret += dfs(root->left, prefix, curr, targetSum);
    ret += dfs(root->right, prefix, curr, targetSum);
    prefix[curr]--;

    return ret;
}

int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long long, int> prefix;
    prefix[0] = 1;
    return dfs(root, prefix, 0,  targetSum);
}



int main() {
    TreeNode* n30 = new TreeNode(3);
    TreeNode* n31 = new TreeNode(-2);
    TreeNode* n32 = new TreeNode(1);
    TreeNode* n20 = new TreeNode(3, n30, n31);
    TreeNode* n21 = new TreeNode(2, NULL, n32);
    TreeNode* n22 = new TreeNode(11);
    TreeNode* n10 = new TreeNode(5, n20, n21);
    TreeNode* n11 = new TreeNode(-3, NULL, n22);
    TreeNode* root = new TreeNode(10, n10, n11);
    cout << pathSum(root, 8) << endl;
    system("pause");
    return 0;
}