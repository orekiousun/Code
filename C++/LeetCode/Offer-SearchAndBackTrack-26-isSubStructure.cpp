#include<iostream>
using namespace std;

/*
    判断一棵树B是否是另一棵树A的子树

    方法：
        以B为模板，确定相同的根节点，再检测B是否是A的子树
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* a, TreeNode* b) : val(x), left(a), right(b) {}
};

// 检测是否是由同一个根节点向下的同一棵树
bool isSameTree(TreeNode* A, TreeNode* B) {
    if (A == nullptr) return false;
    if (A->val != B->val) return false;
    bool ans = true;
    if (B->left != nullptr) ans &= isSameTree(A->left, B->left);
    if (B->right != nullptr) ans &= isSameTree(A->right, B->right);
    return ans;
}

bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(B == nullptr) return false;
    if(A == nullptr) return false;
    bool ans;
    if (A->val == B->val) {
        ans |= isSameTree(A, B);
        if (ans) return true;
    }
    if (A->left != nullptr && isSubStructure(A->left, B) == true) return true;
    if (A->right != nullptr && isSubStructure(A->right, B) == true) return true; 
    return false;
}

int main(int argc, char const *argv[]) {
    TreeNode* A1 = new TreeNode(1);
    TreeNode* A2 = new TreeNode(2);
    TreeNode* A5 = new TreeNode(5);
    TreeNode* A4 = new TreeNode(4, A1, A2);
    TreeNode* A = new TreeNode(3, A4, A5);

    TreeNode* B1 = new TreeNode(1);
    TreeNode* B = new TreeNode(4, B1, nullptr);
    cout << isSubStructure(A, B) << endl;
    return 0;
}
