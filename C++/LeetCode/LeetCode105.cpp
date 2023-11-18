#include<iostream>
using namespace std;
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*改进前：
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    if(preorder.size() == 0)
    {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[0]);
    int i = 0;
    while (inorder[i] != root->val)
    {
        i++;
    }

    vector<int> leftPreOrder(preorder.begin() + 1, preorder.begin() + i + 1);
    vector<int> leftInOrder(inorder.begin(), inorder.begin() + i);
    vector<int> rightPreOrder(preorder.begin() + i + 1, preorder.end());
    vector<int> rightInOrder(inorder.begin() + i + 1, inorder.end());
    
    root->left = buildTree(leftPreOrder, leftInOrder);
    root->right = buildTree(rightPreOrder, rightInOrder);
    return root;
}
*/

TreeNode* buildTreeWithIndex(vector<int>& preorder, vector<int>& inorder, int preBegin, int inBegin, int size) 
{
    if (size < 1 || preBegin >= preorder.size() || inBegin >= preorder.size())
    {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[preBegin]);
    int i = 0;
    while (i < size && inorder[inBegin + i] != preorder[preBegin])
    {
        i++;
    }
    i += inBegin;
    root->left = buildTreeWithIndex(preorder, inorder, preBegin + 1, inBegin, i - inBegin);
    root->right = buildTreeWithIndex(preorder, inorder, preBegin + (i - inBegin) + 1, i + 1, size - (i - inBegin + 1));
    return root;
}

int main()
{
    vector<int> preorder{1, 2, 3, 4, 5};
    vector<int> inorder{3, 4, 2, 5, 1};
    TreeNode* root = buildTreeWithIndex(preorder, inorder, 0, 0, preorder.size());
    cout << root->val << endl;
    system("psuse");
    return 0;
}