//
// Created by ousun on 2025/09/26.
// 重排链表：https://www.programmercarl.com/0143.%E9%87%8D%E6%8E%92%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF
// 重排链表：https://leetcode.cn/problems/reorder-list/
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

// 先快慢指针，找到中间值，然后反转后半部分链表，再合并两个链表
void reorderList(ListNode* head) {
    ListNode* fast = head, *slow = head;
    // 快指针走到尾部，慢指针刚好走到中间
    while (fast->next != nullptr) {
        fast = fast->next;
        ListNode* tmp = slow->next;
        if (fast->next != nullptr)
            fast = fast->next;
        else
            slow->next = nullptr;
        slow = tmp;
    }
    // 反转后半部分链表
    ListNode* pre = slow;
    ListNode* next = pre->next;
    pre->next = nullptr;
    while (next != nullptr) {
        ListNode* tmp = next->next;
        next->next = pre;
        pre = next;
        next = tmp;
    }
    // 将pre为头的链表插入head为头的链表中
    ListNode* insert = head;
    while (insert != nullptr && pre != nullptr) {
        ListNode* tmp = insert->next;
        ListNode* tmp2 = pre->next;
        insert->next = pre;
        pre->next = tmp;
        insert = tmp;
        pre = tmp2;
    }
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    reorderList(n1);
    return 0;
}