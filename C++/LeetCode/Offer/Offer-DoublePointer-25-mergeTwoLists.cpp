#include<iostream>
using namespace std;
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
    合并两个有序链表

    方法：
        直接判断大小合并即可。为节省空间，可以同意合并到1中
*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // 统一合并到l1中
    ListNode *root = new ListNode(0);
    root->next = l1;
    ListNode *pre = root;
    if (l1 == nullptr || l2 == nullptr) return l1 == nullptr ? l2 : l1;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            pre = l1;
            l1 = l1->next;
        }
        else {
            ListNode* temp = l2->next;
            l2->next = pre->next;
            pre->next = l2;
            pre = l2;
            l2 = temp;
        }
    }
    if (l1 == nullptr) pre->next = l2;
    return root->next;
}

int main(int argc, char const *argv[]) {
    ListNode* l1 = new ListNode(1);
    ListNode* l11 = new ListNode(2);
    ListNode* l12 = new ListNode(5);
    l1->next = l11;
    l11->next = l12;

    ListNode* l2 = new ListNode(3);
    ListNode* l21 = new ListNode(4);
    ListNode* l22 = new ListNode(5);
    ListNode* l23 = new ListNode(7);
    ListNode* l24 = new ListNode(8);
    l2->next = l21;
    l12->next = l22;
    l22->next = l23;
    l23->next = l24;

    ListNode* ans = mergeTwoLists(l1, l2);

    return 0;
}
