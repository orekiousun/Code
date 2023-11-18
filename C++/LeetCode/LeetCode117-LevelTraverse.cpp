#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Node 
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(): val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val): val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {}
};

// 大佬做法
class Solution {
public:
    Node* connect(Node* root) {
        Node* res = root, *temp = nullptr, *last = nullptr; // temp表示下一层第一个要访问的节点, last表示同一层上一个不为空的节点
        while (root) {
            if (root->left) { // 如果左节点存在
                if (!temp) temp = root->left; // temp没有设置就设置
                if (last) last->next = root->left; // last存在说明可以连接
                root->left->next = root->right, last = root->left;  // 进行连接
            }
            // 同理右节点
            if (root->right) {
                if (!temp) temp = root->right;
                if (last) last->next = root->right;
                if (root->next) root->right->next = root->next->left, last = root->right;
            }
            if (root->next) root = root->next; // 如果当前节点存在next, 就到next去 
            else root = temp, temp = nullptr, last = nullptr; // 如果同一层访问完了, 去下一层
        }
        return res;
    }
};

// 也叫宽度优先遍历BFS
int LevelTraverse(Node* root)
{
    if(root == NULL) return NULL;

    queue<Node*> nodeQueue;
    vector<int> level;
    int levelNow = 0, count = 0;
    nodeQueue.push(root);
    level.push_back(levelNow);
    Node* temp;
    
    while (1)
    {
        if(nodeQueue.front()->left != NULL) 
        {
            nodeQueue.push(nodeQueue.front()->left);
            level.push_back(levelNow+1);
        }
        if(nodeQueue.front()->right != NULL)
        {
            nodeQueue.push(nodeQueue.front()->right);
            level.push_back(levelNow+1);
        } 
        temp = nodeQueue.front();
        nodeQueue.pop();
        if(nodeQueue.empty()) break;

        count++;
        
        if(level[count] != levelNow)
        {
            temp->next = NULL;
            levelNow++;
        } 
        else temp->next = nodeQueue.front();
    }
    temp->next = NULL;
    return root;
}

int main()
{
    Node* root = new Node(0);
    system("pause");
    return 0;
}
