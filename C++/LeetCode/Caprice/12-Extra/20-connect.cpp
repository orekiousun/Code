//
// Created by ousun on 2025/10/18.
// 填充每个节点的下一个右侧节点指针：
// 填充每个节点的下一个右侧节点指针：
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 层序遍历
Node* connect(Node* root) {
    if (!root) return root;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* front = q.front();
            q.pop();
            if (size > 0) front->next = q.front();            
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
    return root;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    n4->left = n2;
    n2->left = n1;
    n2->right = n3;
    n4->right = n6;
    n6->left = n5;
    n6->right = n7;
    connect(n4);
    return 0;
}