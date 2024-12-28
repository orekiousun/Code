//
// Created by ousun on 2024/12/22.
// 环形链表：https://www.programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html
// 环形链表：https://leetcode.cn/problems/linked-list-cycle-ii/description/
// 

#include <iostream>
using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode* a = slow;
            ListNode* b = head;
            while (a != b) {
                a = a->next;
                b = b->next;
            }
            return a;
        }
    }
    return nullptr;
}

int main() {
    return 0;
}
