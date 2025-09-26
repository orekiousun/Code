//
// Created by ousun on 2025/09/26.
// 回文链表：https://www.programmercarl.com/0234.%E5%9B%9E%E6%96%87%E9%93%BE%E8%A1%A8.html
// 回文链表：https://leetcode.cn/problems/palindrome-linked-list/
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

// 法一：递归做法
bool isPalindrome(ListNode*& head, ListNode* tail) {
    bool ret = true;
    if (tail->next != nullptr)
        ret = isPalindrome(head, tail->next);
    ret = ret && tail->val == head->val;
    head = head->next;
    return ret;
}

bool isPalindrome(ListNode* head) {
    return isPalindrome(head, head);
}

// 法二：快慢指针+反转链表
bool isPalindrome2(ListNode* head) {
    ListNode* fast = head, *slow = head;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
        if (fast->next != nullptr)
            fast = fast->next;
    }
    // 快指针走到尾部，慢指针刚好走到中间，开始反转慢指针之后的链表
    ListNode* pre = slow;
    ListNode* next = pre->next;
    pre->next = nullptr;
    while (next != nullptr) {
        ListNode* tmp = next->next;
        next->next = pre;
        pre = next;
        next = tmp;
    }
    // 开始比较
    while (pre != nullptr && head != nullptr) {
        if (pre->val != head->val)
            return false;
        pre = pre->next;
        head = head->next;
    }
    return true;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout << isPalindrome2(n1) << endl;
    return 0;
}