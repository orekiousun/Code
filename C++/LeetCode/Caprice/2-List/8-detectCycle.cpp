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

// 快慢指针，相遇的点再和头节点走相同的步数，即是入环的第一个节点
// 假设从head走到相遇需要m步，从相遇走到再次相遇（即成环）需要n步
// 即有 m + an = 2(m + bn)，可得m = (b - 2a)n
// 需要证明：m + an + m = m + kn
// 替换最后一个m，可得 m + an + (b - 2a)n = m + kn
// m + (b - a)n = m + kn，存在k = b - a成立
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
