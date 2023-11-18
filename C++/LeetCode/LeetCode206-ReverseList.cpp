#include<iostream>
using namespace std;
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    vector<ListNode*> vec;
    while (head != nullptr) {
        vec.push_back(head);
        head = head->next;
    }
    ListNode* ans = vec[vec.size() - 1];
    for (int i = vec.size() - 1; i > 0; i--) {
        vec[i]->next = vec[i - 1];
    }
    vec[0]->next = nullptr;
    return ans;
}

ListNode* reverseList(ListNode* head, bool flag) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* current = head->next;
    ListNode* pre = head;
    ListNode* temp = current;
    while (current != nullptr) {
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }
    head->next = nullptr;
    return pre;
}



int main(int argc, char const *argv[]) {
    ListNode* l5 = new ListNode(5);
    ListNode* l4 = new ListNode(4, l5);
    ListNode* l3 = new ListNode(3, l4);
    ListNode* l2 = new ListNode(2, l3);
    ListNode* head = new ListNode(1, l2);
    ListNode* temp = reverseList(head, 1);
    return 0;
}
