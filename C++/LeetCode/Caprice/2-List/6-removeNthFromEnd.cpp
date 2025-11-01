//
// Created by ousun on 2024/12/14.
// 删除链表的倒数第n个节点：https://www.programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html
// 删除链表的倒数第n个节点：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fakeHead = new ListNode(0, head);
    // 先往后走n+1步
    ListNode *left = fakeHead, *right = fakeHead;
    int i = 0;
    while (i < n) {
        right = right->next;
        i++;
    }

    while (right->next != nullptr) {
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;
    ListNode* ret = fakeHead->next;
    delete fakeHead;
    return ret;
}

int main() {

}