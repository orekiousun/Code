#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 通过右中左的遍历方式可以将二叉搜索树按照从大到小排列打印出来
void midTraverse(TreeNode *root)
{
    if(root->right != NULL) midTraverse(root->right);
    cout << root->val << " ";
    if(root->left != NULL) midTraverse(root->left);
    return;
}

// 用一个数字来记录前面的数字求和即可  --  必须引用传递，保证num的值在随递归一直改变
void midTraverseAndAdd(TreeNode *root, int& num)
{
    if(root->right != NULL) midTraverseAndAdd(root->right, num);
    num = num + root->val;
    root->val = num;
    cout << root->val << " ";
    if(root->left != NULL) midTraverseAndAdd(root->left, num);
    return;
}

int main()
{
    TreeNode *t8 = new TreeNode(8); 
    TreeNode *t7 = new TreeNode(7, NULL , t8); 
    TreeNode *t5 = new TreeNode(5); 
    TreeNode *t6 = new TreeNode(6, t5, t7); 
    TreeNode *t3 = new TreeNode(3); 
    TreeNode *t2 = new TreeNode(2, NULL, t3); 
    TreeNode *t0 = new TreeNode(0); 
    TreeNode *t1 = new TreeNode(1, t0, t2); 
    TreeNode *t4 = new TreeNode(4, t1, t6); 
    int num = 0;
    midTraverseAndAdd(t4, num);
    cout << endl;
    system("pause");
    return 0;
}