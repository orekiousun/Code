#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
    给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
    方法：
        双指针记录一个pre和next，两者一起移动
*/

ListNode* deleteNode(ListNode* head, int val) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    if(head->val == val) return head->next;
    ListNode* pre = head, *next = head->next;
    while (next != nullptr) {
        if(next->val == val) {
            pre->next = next->next;
            break;
        }
        pre = next;
        next = next->next;
    }
    return head;
}

int main(int argc, char const *argv[]) {
    // 懒得做测试数据了
    return 0;
}
