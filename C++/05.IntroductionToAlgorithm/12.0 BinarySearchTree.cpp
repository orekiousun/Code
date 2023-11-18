#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *parent) : val(x), left(left), right(right), parent(parent) {}
};

void treeInsert(TreeNode* root, TreeNode* node)
{
    TreeNode* parent;
    while (root != NULL)
    {
        parent = root;
        if(node->val <= root->val)
            root = root->left;
        else 
            root = root->right;
    }
    node->parent = parent;
    if(node->val <= parent->val) 
        parent->left = node;
    else 
        parent->right = node;
}

void treeTraverse(TreeNode *root)
{
    if(root == NULL) 
        return;
    treeTraverse(root->left);
    cout << root->val << " ";
    treeTraverse(root->right);
}

TreeNode* getTreeMax(TreeNode* root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

TreeNode* getTreeMin(TreeNode* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// 找到后继
TreeNode* treeSuccessor(TreeNode *node)
{
    if(node->right != NULL) 
        return getTreeMax(node->right);
    TreeNode* temp = node->parent;
    while (temp != NULL && temp->right == node)
    {
        node = temp;
        temp = node->parent;
    }
    return temp;
}

void transplant(TreeNode *root, TreeNode* u, TreeNode* v)
{
    if(root == u)
    {
        root->left = v->left;
        root->right = v->right;
        root->val = v->val;
    }
    else if(u == u->parent->left)
        u->parent->left = v;
    else if(u == u->parent->right)
        u->parent->right = v;
    if(v != NULL)
        v->parent = u->parent;
}

void treeDelete(TreeNode* root, TreeNode* node)
{
    if(node->left == NULL) 
        transplant(root, node, node->right);
    else if(node->right == NULL) 
        transplant(root, node, node->left);
    else
    {
        TreeNode* next = getTreeMin(node->right);
        if(next->parent != node) 
        {
            transplant(root, next, next->right);
            next->right = node->right;
            next->right->parent = next;
        }
        transplant(root, node, next);
        next->left = node->left;
        next->left->parent = next;
    }
}

int main()
{
    TreeNode* root = new TreeNode(12);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node18 = new TreeNode(18);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node21 = new TreeNode(21);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node19 = new TreeNode(19);

    treeInsert(root, node5);
    treeInsert(root, node2);
    treeInsert(root, node18);
    treeInsert(root, node15);
    treeInsert(root, node21);
    treeInsert(root, node7);
    treeInsert(root, node19);

    treeTraverse(root);
    cout << endl;

    TreeNode* max = getTreeMax(root);
    cout << max->val << endl;
    treeDelete(root, node18);
    treeTraverse(root);

    system("pause");
    return 0;
}