#include<iostream>
using namespace std;
#include<map>
#include<unordered_map>
// unordered_map实现原理哈希表，map实现原理红黑树

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
    除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
    给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
*/
// unordered_map 实测更快
int rob(TreeNode* root, bool parentVisited, unordered_map<TreeNode*, int>& nodeParentTrueMap, unordered_map<TreeNode*, int>& nodeParentFalseMap) {
    if(root == NULL) return 0;
    int result = 0;
    if(parentVisited) {
        result += nodeParentFalseMap.find(root->left) == nodeParentFalseMap.end() ? 
            rob(root->left, false, nodeParentTrueMap, nodeParentFalseMap) : nodeParentFalseMap[root->left];
        result += nodeParentFalseMap.find(root->right) == nodeParentFalseMap.end() ? 
            rob(root->right, false, nodeParentTrueMap, nodeParentFalseMap) : nodeParentFalseMap[root->right];
    }
    else {
        result = max(
            root->val + (nodeParentTrueMap.find(root->left) == nodeParentTrueMap.end() ? rob(root->left, true, nodeParentTrueMap, nodeParentFalseMap) : nodeParentTrueMap[root->left])
            + (nodeParentTrueMap.find(root->right) == nodeParentTrueMap.end() ? rob(root->right, true, nodeParentTrueMap, nodeParentFalseMap) : nodeParentTrueMap[root->right])
            , (nodeParentFalseMap.find(root->left) == nodeParentFalseMap.end() ? rob(root->left, false, nodeParentTrueMap, nodeParentFalseMap) : nodeParentFalseMap[root->left])
            + (nodeParentFalseMap.find(root->right) == nodeParentFalseMap.end() ? rob(root->right, false, nodeParentTrueMap, nodeParentFalseMap) : nodeParentFalseMap[root->right])
        );
    }
    if(parentVisited)
        nodeParentTrueMap[root] = result;
    else
        nodeParentFalseMap[root] = result;
    return result;
}

// map 会慢一点
int rob(TreeNode* root, bool parentVisited, map<TreeNode*, int>& nodeParentTrueMap, map<TreeNode*, int>& nodeParentFalseMap) {
    if(root == NULL) return 0;
    int result = 0;
    if(parentVisited) {
        result += nodeParentFalseMap.find(root->left) == nodeParentFalseMap.end() ? 
            rob(root->left, false, nodeParentTrueMap, nodeParentFalseMap) : nodeParentFalseMap[root->left];
        result += nodeParentFalseMap.find(root->right) == nodeParentFalseMap.end() ? 
            rob(root->right, false, nodeParentTrueMap, nodeParentFalseMap) : nodeParentFalseMap[root->right];
    }
    else {
        result = max(
            root->val + (nodeParentTrueMap.find(root->left) == nodeParentTrueMap.end() ? rob(root->left, true, nodeParentTrueMap, nodeParentFalseMap) : nodeParentTrueMap[root->left])
            + (nodeParentTrueMap.find(root->right) == nodeParentTrueMap.end() ? rob(root->right, true, nodeParentTrueMap, nodeParentFalseMap) : nodeParentTrueMap[root->right])
            , (nodeParentFalseMap.find(root->left) == nodeParentFalseMap.end() ? rob(root->left, false, nodeParentTrueMap, nodeParentFalseMap) : nodeParentFalseMap[root->left])
            + (nodeParentFalseMap.find(root->right) == nodeParentFalseMap.end() ? rob(root->right, false, nodeParentTrueMap, nodeParentFalseMap) : nodeParentFalseMap[root->right])
        );
    }
    if(parentVisited)
        nodeParentTrueMap[root] = result;
    else
        nodeParentFalseMap[root] = result;
    return result;
}

int rob(TreeNode* root) {
    unordered_map<TreeNode*, int> nodeParentTrueMap;
    unordered_map<TreeNode*, int> nodeParentFalseMap;
    return rob(root, false, nodeParentTrueMap, nodeParentFalseMap);
}

int main() {
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(4, n2, n1);
    TreeNode* n5 = new TreeNode(5, NULL, n3);
    TreeNode* root = new TreeNode(3, n4, n5);
    cout << rob(root) << endl;
    system("pause");
    return 0;
}