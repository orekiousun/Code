//
// Created by ousun on 2024/12/14.
// 两两交换链表中的节点：https://www.programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 两两交换链表中的节点：https://leetcode.cn/problems/swap-nodes-in-pairs/description/
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

// 使用虚拟头节点
ListNode* swapPairs(ListNode* head) {
    ListNode* fakeHead = new ListNode(0, head);
    ListNode* pre = fakeHead;
    ListNode* cur = head;
    while (cur != nullptr) {
        ListNode* next = cur->next;
        if (next == nullptr) break;
        ListNode* tmp = next->next;
        next->next = cur;
        cur->next = tmp;
        pre->next = next;
        pre = cur;
        cur = tmp;
    }

    ListNode* ret = fakeHead->next;
    delete fakeHead;
    return ret;
}

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    ListNode* newHead = swapPairs(l1);
    return 0;
}