#include<iostream>
using namespace std;
#include<vector>

/*
    反向打印链表：
        ·法一：先将链表反转，再打印
        ·法二：利用递归，本质上还是一个栈
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#pragma region  法一：先反转链表，再打印
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

vector<int> reversePrint(ListNode* head) {
    head = reverseList(head);
    vector<int> ans;
    while (head != nullptr) {
        ans.push_back(head->val);
        head = head->next;
    }
    return ans;
}
#pragma endregion

#pragma region 法二：不反转链表，递归法  -- 递归栈，本质上还是用了一个栈
void reversePrint(ListNode* head, vector<int>& ans) {
    if(head != nullptr)
        reversePrint(head->next, ans);
    else
        return;
    ans.push_back(head->val);
}

vector<int> reversePrint(ListNode* head, bool override) {
    vector<int> ans;
    reversePrint(head, ans);
    return ans;
}
#pragma endregion

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

    vector<int> ans = reversePrint(l1, true);

    for(int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
