#include<iostream>
using namespace std;
#include<queue>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector <vector <int>> ret;
        if (!root) 
        {
            return ret;
        }
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) 
            {
                auto node = q.front(); 
                q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ret;
    }
};

void divideLevel(queue<TreeNode*>& q, vector<vector<int>>& res, TreeNode* root, int level)
{
    if(level == res.size())
    {
        vector<int> temp;
        res.push_back(temp);
    }
    q.push(root);
    TreeNode* tempNode = q.front();
    q.pop();
    res[level].push_back(tempNode->val);
    if(tempNode->left != NULL || tempNode->right != NULL)
    {
        level++;
    }  
    if(tempNode->left != NULL)
    {
        divideLevel(q, res, tempNode->left, level);
    }
    if(tempNode->right != NULL)
    {
        divideLevel(q, res, tempNode->right, level);
    }
}

/*
vector<vector<int>> levelOrder(TreeNode* root) 
{
    queue<TreeNode*> q;
    vector<vector<int>> res;
    if(root == NULL) return res;
    divideLevel(q, res, root, 0);
    return res;
}
*/

vector<vector<int>> levelOrder(TreeNode* root) 
{
    queue<TreeNode*> q;
    vector<vector<int>> res;
    if(root == NULL) return res;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> temp;
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode* tempNode = q.front();
            temp.push_back(tempNode->val);
            if(tempNode->left != NULL) q.push(tempNode->left);
            if(tempNode->right != NULL) q.push(tempNode->right);
            q.pop(); 
        }
        res.push_back(temp);
    }
    return res;
}

int main()
{
    TreeNode* n15 = new TreeNode(15);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n20 = new TreeNode(20, n15, n7);
    TreeNode* n9 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(3, n9, n20);
    vector<vector<int>> res = levelOrder(n3);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}