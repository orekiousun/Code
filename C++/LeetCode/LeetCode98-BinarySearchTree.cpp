#include<iostream>
using namespace std;
#include<vector>
// 验证二叉搜索树 是否符合二叉搜索树的标准（即左边的都小于，右边的都大于）

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool traverse(TreeNode* root, long& lastVal)
{
    bool res =true;
    if(root->left != NULL) res = traverse(root->left, lastVal);
    if (lastVal >= root->val) return false;
    lastVal = root->val;
    if(root->right != NULL) res = res && traverse(root->right, lastVal);
    if(root->left == NULL && root->right == NULL) res = true;
    return res;
}

int main()
{
    
    TreeNode* r1 = new TreeNode(1);
    TreeNode* r3 = new TreeNode(3);
    TreeNode* r6 = new TreeNode(6);
    TreeNode* r4 = new TreeNode(4, r3, r6);
    TreeNode* root = new TreeNode(5, r1, r4);

    long lastVal =  -4353564672;
    
    cout << traverse(root, lastVal) << endl;

    system("pause");
    return 0;
}