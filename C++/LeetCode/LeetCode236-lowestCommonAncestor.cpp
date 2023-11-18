#include<iostream>
using namespace std;
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* leftnode, TreeNode* rightnode) :  val(x), left(leftnode), right(rightnode) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> nodeList;
    vector<int> parent;
    nodeList.push_back(root);
    parent.push_back(-1);
    int count = 0, pPos = -1, qPos = -1;
    while (pPos == -1 || qPos == -1) {
        TreeNode* node = nodeList[count];
        if(node == p) pPos = count;
        if(node == q) qPos = count;
        if(node->left != NULL) {
            nodeList.push_back(node->left);
            parent.push_back(count);
        }
        if(node->right != NULL) {
            nodeList.push_back(node->right);
            parent.push_back(count);
        }
        count++;
    }
    while (pPos != qPos) {
        if(pPos > qPos)
            pPos = parent[pPos];
        else
            qPos = parent[qPos];
    }
    return nodeList[pPos];
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == q || root == p || root == NULL) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) return root; //1

    if (left == NULL && right != NULL) return right;//2

    else if (left != NULL && right == NULL) return left;//3,左边不为空，右边为空，如果先遇到p，说明q一定在p下面，两者公共祖先一定是先遇到的那个。
    else return NULL; //4 (left == NULL && right == NULL)
}

int main() {
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n2 = new TreeNode(2, n7, n4);
    TreeNode* n1 = new TreeNode(1, n0, n8);
    TreeNode* n5 = new TreeNode(5, n6, n2);
    TreeNode* root = new TreeNode(3, n5, n1);

    TreeNode* nx = new TreeNode(2);
    TreeNode* root1 = new TreeNode(1, nx, NULL);

    cout << lowestCommonAncestor(root1, root1, nx)->val << endl;
    system("pause");
    return 0;
}