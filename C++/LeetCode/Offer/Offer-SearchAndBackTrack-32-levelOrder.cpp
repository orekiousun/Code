#include<iostream>
using namespace std;
#include<vector>
#include<queue>

/*
    二叉树层序遍历
    I级：  简单的层序遍历        -- 利用队列
    II级： 分层层序遍历          -- 每次获取队列的大小，纪录队列大小的节点
    III级：分层顺序交叉层序遍历   -- 只改变结果记录逻辑即可
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* a, TreeNode* b) : val(x), left(a), right(b) {}
};

vector<int> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> ans;
    if (root == nullptr) return ans;
    q.push(root);
    while (!q.empty()) {
        TreeNode* front = q.front();
        if (front->left != nullptr) q.push(front->left);
        if (front->right != nullptr) q.push(front->right);
        ans.push_back(front->val);
        q.pop();
    }
    return ans;
}

// 采用分层记录法  --  每次循环开始前，获取当前队列的大小，便可以获取当前层级中的元素个数 !!! 很重要，老容易忘
vector<vector<int>> levelOrder(TreeNode* root, bool flag) {
    queue<TreeNode*> q;
    vector<vector<int>> res;
    if(root == nullptr) return res;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> temp(levelSize);
        for (int i = 0; i < levelSize; i++) {
            TreeNode* tempNode = q.front();
            if (level % 2 == 0)
                temp[i] = tempNode->val;
            else
                temp[levelSize - i - 1] = tempNode->val;
            if(tempNode->left != NULL) q.push(tempNode->left);
            if(tempNode->right != NULL) q.push(tempNode->right);
            q.pop(); 
        }
        res.push_back(temp);
        level++;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    TreeNode* A1 = new TreeNode(1);
    TreeNode* A2 = new TreeNode(2);
    TreeNode* A5 = new TreeNode(5);
    TreeNode* A4 = new TreeNode(4, A1, A2);
    TreeNode* A = new TreeNode(3, A4, A5);

    vector<vector<int>> ans = levelOrder(A, false);
    return 0;
}
