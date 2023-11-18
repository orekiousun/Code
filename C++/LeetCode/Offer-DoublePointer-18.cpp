#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
