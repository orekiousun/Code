#include<vector>
using namespace std;
#include<unordered_map>

/*
    请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

    方法：
        利用哈希表将出现过的链表节点记录起来，避免出现重复
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 递归方法
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};

// 先用哈希表全部记录，再重建新的列表
Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    unordered_map<Node*, Node*> nodeMap;
    Node* ans = head;
    while (head != nullptr) {
        Node* node = new Node(head->val);
        nodeMap[head] = node;
        head = head->next;
    }
    head = ans;
    while (head != nullptr) {
        nodeMap[head]->next = nodeMap[head->next];
        nodeMap[head]->random = nodeMap[head->random];
        head = head->next;
    }
    return nodeMap[ans];
}

int main(int argc, char const *argv[]) {
    Node* head = new Node(3);
    Node* n1 = new Node(2);
    Node* n2 = new Node(1);
    head->next = n1;
    head->random = n2;
    n1->next = n2;
    n1->random = n1;
    n2->random = n1;
    Node* ans = copyRandomList(nullptr);
    return 0;
}
