#include<iostream>
using namespace std;
#include<queue>
#include<string>
#include<algorithm>
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    根据字符串和根节点序列化和反序列化二叉树
    序列化：利用一个flag记录下一层是否是空层，并一层一层的便利
    反序列化：注意从string到int类型的转换stoi函数
*/


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string ans = "";
        q.push(root);
        bool levelNullFlag = false;
        while (!q.empty() && !levelNullFlag) {
            levelNullFlag = true;
            int levelSize = q.size();
            while (levelSize--) {
                TreeNode* node = q.front();
                if(node == nullptr) {
                    ans.append("null,");
                } 
                else {
                    ans.append(to_string(node->val).append(","));
                    q.push(node->left);
                    q.push(node->right);
                    if(node->left != nullptr || node->right != nullptr) {
                        levelNullFlag = false;
                    }
                }
                q.pop();
            }
        }
        ans.erase(ans.size() - 1);
        return '[' + ans + ']';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> vec;
        string temp = "";
        for (int i = 1; i < data.size() - 1; i++) {
            if(data[i] == ',') {
                vec.push_back(temp == "null" ? nullptr : new TreeNode(stoi(temp)));
                temp = "";
            }
            else{
                temp.append(1, data[i]);
            }
        }
        vec.push_back(temp == "null" ? nullptr : new TreeNode(stoi(temp)));
        int parent = 0, son = 1;
        while (son < vec.size()) {
            if(vec[parent] == nullptr) {
                parent++;
                continue;
            }
            vec[parent]->left = vec[son++];
            vec[parent]->right = vec[son++];
            parent++;
        }
        return vec[0];
    }
};

int main(int argc, char const *argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);
    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n5->right = n7;
    n6->left = n8;
    Codec* operation = new Codec();
    cout << operation->serialize(root) << endl;
    TreeNode* ans = operation->deserialize("[1,2,3,4,null,5,6,null,null,null,7,8,null]");

    return 0;
}
