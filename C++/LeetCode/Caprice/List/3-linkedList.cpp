//
// Created by cd_ouymh on 2024/12/7.
// 设计链表：https://www.programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF
// https://leetcode.cn/problems/design-linked-list/submissions/585582414/
//

#include <iostream>
using namespace std;

// 双向链表构造函数
struct LinkedListNode {
    int val;
    LinkedListNode *next;
    LinkedListNode *pre;
    LinkedListNode() : val(0), next(nullptr) {}
    LinkedListNode(int x) : val(x), next(nullptr), pre(nullptr) {}
    LinkedListNode(int x, LinkedListNode* pre, LinkedListNode* next) : val(x), pre(pre), next(next) {}
};

class LinkedList {
private:
    int len;
    LinkedListNode* root = nullptr;

    // 初始化根节点
    void _initRoot(LinkedListNode* node) {
        root = node;
        root->next = root;
        root->pre = root;
        len = 1;
    }

    // 在单节点头部插入元素
    void _addAtNodeHead(LinkedListNode* origin, LinkedListNode* node) {
        LinkedListNode* pre = origin->pre;
        pre->next = node;
        origin->pre = node;
        node->next = origin;
        node->pre = pre;
        len++;
    }

    // 移除节点
    void _removeNode(LinkedListNode* node) {
        LinkedListNode* pre = node->pre;
        LinkedListNode* next = node->next;
        pre->next = next;
        next->pre = pre;
        if (node == root) {
            root = node->next;
        }
        delete node;
        len--;
        if(len == 0)
            root = nullptr;
    }

    // 通过索引获取对应索引位置的节点
    LinkedListNode* _getNodeByIdx(int idx) {
        if (root == nullptr)
            return nullptr;
        if (idx == 1)
            return root;

        LinkedListNode* node = root->next;
        int cnt = 1;
        while (node != root) {
            cnt++;
            if (cnt == idx)
                return node;
            node = node->next;
        }

        return nullptr;
    }

public:
    LinkedList() {
        len = 0;
    }

    int get(int index) {
        LinkedListNode* node = _getNodeByIdx(index);
        if (node != nullptr)
            return node->val;
        else
            return -1;
    }

    void addAtHead(int val) {
        addAtTail(val);
        root = root->pre;
    }

    void addAtTail(int val) {
        LinkedListNode* node = new LinkedListNode(val);
        if (root == nullptr)
            _initRoot(node);
        else
            _addAtNodeHead(root, node);
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        LinkedListNode* node = _getNodeByIdx(index);
        if (node != nullptr)
            _addAtNodeHead(node->next, new LinkedListNode(val));
    }

    void deleteAtIndex(int index) {
        LinkedListNode* node = _getNodeByIdx(index);
        if (node != nullptr)
            _removeNode(node);
    }

    void log() {
        cout << root->val << " ";
        LinkedListNode* node = root->next;
        while (node != root) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList* list = new LinkedList();
    list->addAtHead(1);
    list->log();
    list->addAtTail(3);
    list->log();
    list->addAtIndex(1, 2);
    list->log();
    list->deleteAtIndex(0);
    list->log();
    cout << list->get(1) << endl;
    return 0;
}