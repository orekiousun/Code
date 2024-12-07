//
// Created by cd_ouymh on 2024/12/7.
// 移除链表元素：https://www.programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/description/
//

#include <iostream>
using namespace std;
#include <vector>

// 链表构造函数
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/description/
ListNode* removeElements(ListNode* head, int val) {
    // 添加一个虚拟头节点
    ListNode* headNew = new ListNode(0, head);
    ListNode* cur = headNew;

    while (cur != nullptr && cur->next != nullptr) {
        if (cur->next->val == val) {
            ListNode* next = cur->next;
            cur->next = next->next;
            delete next; // 注意C++没有使用了的内存可以删除，以达到更好的性能
        }
        else
            cur = cur->next;
    }
    return headNew->next;
}

int main() {

}
