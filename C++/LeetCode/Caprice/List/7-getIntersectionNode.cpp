//
// Created by ousun on 2024/12/22.
// 链表相交：https://www.programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html
// 链表相交：https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
        if (a == nullptr) a = headB;
        else a = a->next;
        if (b == nullptr) b = headA;
        else b = b->next;
    }
    return a;
}

int main() {
    return 0;
}