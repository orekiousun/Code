//
// Created by ousun on 2025/09/26.
// 环形链表：https://www.programmercarl.com/0141.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8.html
// 环形链表：https://leetcode.cn/problems/linked-list-cycle/
//

#include <iostream>
using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};


bool hasCycle(ListNode *head) {
    ListNode* fast = head, *slow = head;
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
        if (fast == nullptr)
            return false;
        fast = fast->next;
        if (fast == slow)
            return true;
    }
    return false;
}

int main() {
    return 0;
}