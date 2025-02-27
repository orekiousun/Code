//
// Created by cd_ouymh on 2025/2/25.
// 遍历：https://www.programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html#%E6%80%9D%E8%B7%AF
// 非递归法前、中、后序遍历其实个人感觉意义不大
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void _preTraverseRecursion(TreeNode* root, vector<int>& ret) {
    if (root == nullptr) return;
    ret.push_back(root->val);
    cout << root->val << " ";
    _preTraverseRecursion(root->left, ret);
    _preTraverseRecursion(root->right, ret);
}

// 递归前序遍历 根左右
vector<int> preTraverseRecursion(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    _preTraverseRecursion(root, ret);
    cout << endl;
    return ret;
}

// 非递归前序遍历 根左右
vector<int> preTraverse(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* top = s.top();
        s.pop();
        ret.push_back(top->val);
        cout << top->val << " ";
        if (top->right) s.push(top->right);
        if (top->left) s.push(top->left);
    }
    cout << endl;
    return ret;
}

void _midTraverseRecursion(TreeNode* root, vector<int>& ret) {
    if (root == nullptr) return;
    _midTraverseRecursion(root->left, ret);
    ret.push_back(root->val);
    cout << root->val << " ";
    _midTraverseRecursion(root->right, ret);
}

// 递归中序遍历 左根右
vector<int> midTraverseRecursion(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    _midTraverseRecursion(root, ret);
    cout << endl;
    return ret;
}

// 非递归中序遍历 左根右
vector<int> midTraverse(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    stack<TreeNode*> s;
    TreeNode* cur = root;
    while (cur != nullptr || !s.empty()) {
        if (cur != nullptr) {
            s.push(cur);
            cur = cur->left;
        }
        else {
            TreeNode* top = s.top();
            s.pop();
            ret.push_back(top->val);
            cout << top->val << " ";
            cur = top->right;
        }
    }
    cout << endl;
    return ret;
}

void _backTraverseRecursion(TreeNode* root, vector<int>& ret) {
    if (root == nullptr) return;
    _backTraverseRecursion(root->left, ret);
    _backTraverseRecursion(root->right, ret);
    ret.push_back(root->val);
    cout << root->val << " ";
}

// 递归后序遍历 左右根
vector<int> backTraverseRecursion(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    _backTraverseRecursion(root, ret);
    cout << endl;
    return ret;
}

// 非递归后序遍历 左右根
vector<int> backTraverse(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* top = s.top();
        s.pop();
        ret.push_back(top->val);
        if (top->left) s.push(top->left); // 相对于前序遍历，这更改一下入栈顺序
        if (top->right) s.push(top->right);
    }
    reverse(ret.begin(), ret.end()); // 将结果反转之后就是左右中的顺序了
    for (auto v : ret) {
        cout << v << " ";
    }
    cout << endl;
    return ret;
}

int main() {
    /*
     *          1
     *         / \
     *        2   3
     *       / \ / \
     *       4 5 6 7
     */
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
    cout << "前序遍历（根左右）：" << endl;
    preTraverseRecursion(n1);
    preTraverse(n1);
    cout << "中序遍历（左根右）：" << endl;
    midTraverseRecursion(n1);
    midTraverse(n1);
    cout << "后序遍历（左右根）：" << endl;
    backTraverseRecursion(n1);
    backTraverse(n1);
    cout << "层序遍历：" << endl;
    return 0;
}
