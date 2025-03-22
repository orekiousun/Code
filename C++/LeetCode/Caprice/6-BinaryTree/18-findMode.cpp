//
// Created by ousun on 2025/3/22.
// 二叉搜索树中的众数：https://www.programmercarl.com/0501.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E4%BC%97%E6%95%B0.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 二叉搜索树中的众数：https://leetcode.cn/problems/find-mode-in-binary-search-tree/
//

#include <iostream>
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 根节点，最大次数，当前次数，结果数组
// 注意这里要把pre作为引用传递，直接用TreeNode* pre为拷贝传递，不会在函数之间传递值
void midTraverse(TreeNode* root, TreeNode*& pre, int& curCnt, int& maxCnt, vector<int>& ret) {
    if (root == nullptr) return;
    midTraverse(root->left, pre, curCnt, maxCnt, ret);
    if (pre == nullptr) {
        pre = root;
        curCnt = 1, maxCnt = 1;
        ret = vector<int>{root->val};
    }
    else {
        if (pre->val == root->val) curCnt += 1;
        else curCnt = 1;
        if (curCnt > maxCnt) {
            maxCnt = curCnt;
            ret = vector<int>{root->val};
        }
        else if (curCnt == maxCnt) {
            ret.push_back(root->val);
        }
        pre = root;
    }
    midTraverse(root->right, pre, curCnt, maxCnt, ret);
}

vector<int> findMode(TreeNode* root) {
    TreeNode* pre = nullptr;
    int curCnt, maxCnt;
    vector<int> ret;
    midTraverse(root, pre, curCnt, maxCnt, ret);
    return ret;
}

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(2);
    n1->right = n2;
    n2->left = n3;
    findMode(n1);
    return 0;
}