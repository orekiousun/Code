#include<iostream>
using namespace std;

/*
    反转链表：
    使用两个指针，一个pre，一个next
    利用temp记录next的next，再将next->next置为pre，
    pre = next， next = temp
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return head;
    ListNode* preNode = head, *nextNode = head->next;
    while (nextNode) {
        ListNode* temp = nextNode->next;
        nextNode->next = preNode;
        preNode = nextNode;
        nextNode = temp;
    }
    head->next = nullptr;
    return preNode;
}

int main(int argc, char const *argv[]) {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);
    ListNode* l7 = new ListNode(7);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;

    ListNode* ans = reverseList(l1);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}