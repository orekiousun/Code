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

void flatten(TreeNode* root) 
{
    TreeNode* tempRoot = root;
    if(root == NULL) return;
    TreeNode* temp;
    while (tempRoot->left != NULL || tempRoot->right != NULL)
    {
        if(tempRoot->left != NULL)
        {
            temp = tempRoot->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = tempRoot->right;
            tempRoot->right = tempRoot->left;
            tempRoot->left = NULL;
        }
        tempRoot = tempRoot->right;
    }
}

int main()
{
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n5 = new TreeNode(5, NULL, n6);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(2, n3, n4);
    TreeNode* root = new TreeNode(1, n2, n5);
    flatten(root);
    system("pause");
    return 0;
}