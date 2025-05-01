//
// Created by ousun on 2025/5/1.
// 监控二叉树：https://www.programmercarl.com/0968.%E7%9B%91%E6%8E%A7%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 监控二叉树：https://leetcode.cn/problems/binary-tree-cameras/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 0-无覆盖 1-摄像头 2-有覆盖
int traverse(TreeNode* cur, int& ret) {
    if (cur == nullptr) return 2;
    int left = traverse(cur->left, ret);    // 左
    int right = traverse(cur->right, ret);  // 右
    if (left == 2 && right == 2) return 0;
    else if (left == 0 || right == 0) {
        ret++;
        return 1;
    }
    // 说明肯定有一边放了摄像头
    else return 2;
}

// 尽可能让摄像头影响到多的节点
// 后续遍历
int minCameraCover(TreeNode* root) {
    int ret = 0;
    if (traverse(root, ret) == 0) ret++;
    return ret;
}

int main() {
    TreeNode* n1 = new TreeNode(0);
    TreeNode* n2 = new TreeNode(0);
    TreeNode* n3 = new TreeNode(0);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n5 = new TreeNode(0);
    n1->left = n2;
    n2->left = n3;
    n3->left = n4;
    n4->right = n5;
    cout << minCameraCover(n1) << endl;
    return 0;
}
