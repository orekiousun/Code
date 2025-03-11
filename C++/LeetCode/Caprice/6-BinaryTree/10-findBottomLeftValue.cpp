//
// Created by cd_ouymh on 2025/3/11.
// 找树左下角的值：https://www.programmercarl.com/0513.%E6%89%BE%E6%A0%91%E5%B7%A6%E4%B8%8B%E8%A7%92%E7%9A%84%E5%80%BC.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 找树左下角的值：https://leetcode.cn/problems/find-bottom-left-tree-value/description/
//

#include <iostream>
using namespace std;
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int ret;
    while (!q.empty()) {
        ret = q.front()->val;
        int len = q.size();
        while (len--) {
            TreeNode* front = q.front();
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
            q.pop();
        }
    }

    return ret;
}

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    n1->left = n2, n1->right = n3;
    n2->left = n4, n2->right = n5;
    n3->left = n6, n3->right = n7;
    cout << findBottomLeftValue(n1) << endl;
    return 0;
}
