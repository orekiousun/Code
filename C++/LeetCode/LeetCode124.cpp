#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#define maxInt 0x7fffffff

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxRightPathSum(TreeNode* root);

int maxLeftPathSum(TreeNode* root) {
    int leftMaxPathSum = 0;
    if(root->left != nullptr)
        leftMaxPathSum = max(leftMaxPathSum, max(maxLeftPathSum(root->left), maxRightPathSum(root->left)));
    return root->val + leftMaxPathSum;
}

int maxRightPathSum(TreeNode* root) {
    int rightMaxPathSum = 0;
    if(root->right != nullptr)
        rightMaxPathSum = max(rightMaxPathSum, max(maxLeftPathSum(root->right), maxRightPathSum(root->right)));
    return root->val + rightMaxPathSum;
}

int maxPathSum(TreeNode* root) {
    int leftPathSum = 0, rightPathSum = 0;
    int leftMaxPathSum = -maxInt, rightMaxPathSum = -maxInt;
    if(root->left != nullptr) {
        leftPathSum = max(leftPathSum, max(maxLeftPathSum(root->left), maxRightPathSum(root->left)));
        leftMaxPathSum = maxPathSum(root->left);
    }
    if(root->right != nullptr) {
        rightPathSum = max(rightPathSum, max(maxLeftPathSum(root->right), maxRightPathSum(root->right)));
        rightMaxPathSum = maxPathSum(root->right);
    }
    int rootMaxPathSum = leftPathSum + root->val + rightPathSum;
    return max(rootMaxPathSum, max(leftMaxPathSum, rightMaxPathSum));
}

class Solution {
private:
    int maxSum = -maxInt;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int main(int argc, const char** argv) {
    TreeNode* node6_1 = new TreeNode(-6);

    TreeNode* node6_2 = new TreeNode(-6, node6_1, nullptr);
    TreeNode* node6_3 = new TreeNode(6);
    TreeNode* node2_1 = new TreeNode(2, node6_2, node6_1);

    TreeNode* node2_2 = new TreeNode(2, node2_1, nullptr);
    TreeNode* node3 = new TreeNode(-3, node6_1, node2_2);
    TreeNode* root = new TreeNode(9, node6_3, node3);

    cout << maxPathSum(root) << endl;
    return 0;
}