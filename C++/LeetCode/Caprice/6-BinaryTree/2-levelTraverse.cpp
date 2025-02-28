//
// Created by cd_ouymh on 2025/2/27.
// 层序遍历：https://www.programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_102-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86
// 层序遍历：https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
// 层序遍历II：https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/submissions/604047823/
//

#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 非递归层序遍历
vector<int> levelTraverse(TreeNode *root) {
    // 使用队列进行前序遍历
    queue<TreeNode *> q;
    q.push(root);
    vector<int> ret;
    while (!q.empty()) {
        TreeNode *front = q.front();
        ret.push_back(front->val);
        cout << front->val << " ";
        q.pop();
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
    cout << endl;
    return ret;
}

void _levelTraverseRecursion(TreeNode *cur, vector<vector<int>> &ret, int depth) {
    if (cur == nullptr) return;
    if (ret.size() == depth) ret.push_back(vector<int>());
    ret[depth].push_back(cur->val);
    _levelTraverseRecursion(cur->left, ret, depth + 1);
    _levelTraverseRecursion(cur->right, ret, depth + 1);
}

// 层序遍历II
// 递归层序遍历，记录每一层的结果
vector<vector<int>> levelTraverseRecursion(TreeNode *root) {
    vector<vector<int>> ret;
    _levelTraverseRecursion(root, ret, 0);
//    是否要反转
//    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    return 0;
}
