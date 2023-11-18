#include<iostream>
using namespace std;

/*
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

*/

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

Node* treeToDoublyList(Node* root) {
    return nullptr;
}

// 思路：中序遍历
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node *pre, *head;
    void dfs(Node* cur) {
        if(cur == nullptr) return;
        dfs(cur->left);
        if(pre != nullptr) pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};

int main(int argc, char const *argv[]) {
    Node* n1 = new Node(1);
    Node* n3 = new Node(3);
    Node* n5 = new Node(5);
    Node* n2 = new Node(2, n1, n3);
    Node* n4 = new Node(4, n2, n5);
    Node* ans =  treeToDoublyList(n4);
    return 0;
}
