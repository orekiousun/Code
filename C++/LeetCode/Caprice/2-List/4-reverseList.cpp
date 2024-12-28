//
// Created by ousun on 2024/12/14.
// 翻转链表：https://www.programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html
// 翻转链表：https://leetcode.cn/problems/reverse-linked-list/description/
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

// 双指针法
ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != nullptr) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode *reverseList2(ListNode* cur, ListNode* pre) {
    if (cur == nullptr) return pre;
    ListNode* tmp = cur->next;
    cur->next = pre;
    return reverseList2(tmp, cur);
}

// 递归法
ListNode *reverseList2(ListNode* head) {
    return reverseList2(head, nullptr);
}
                                                n
int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode* newHead = reverseList(l1);
    return 0;
}