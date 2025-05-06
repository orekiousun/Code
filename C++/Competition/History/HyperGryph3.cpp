#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* maxDepthAVL(int left, int right) {
	if(left > right) return nullptr;
	TreeNode* root = new TreeNode((left + right) / 2);
	if(left == right) return root;
	root->left = maxDepthAVL(left, (left + right) / 2 - 1);
	root->right = maxDepthAVL((left + right) / 2 + 1, right);
	return root;
}

TreeNode* maxDepthAVL(int n) {
    TreeNode* root = new TreeNode((1 + n) / 2 + 1);
	root->left = maxDepthAVL(1, (1 + n) / 2);
	root->right = maxDepthAVL((1 + n) / 2 + 2, n);
	return root;
}

int main(int argc, const char** argv) {
	TreeNode* res = maxDepthAVL(7);
    system("pause");
    return 0;
}