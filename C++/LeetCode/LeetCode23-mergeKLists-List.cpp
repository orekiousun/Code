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

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if ((!a) || (!b)) return a ? a : b;
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) {
        if (aPtr->val < bPtr->val) {
            tail->next = aPtr; aPtr = aPtr->next;
        } else {
            tail->next = bPtr; bPtr = bPtr->next;
        }
        tail = tail->next;
    }
    tail->next = (aPtr ? aPtr : bPtr);
    return head.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* ret = nullptr;
    for (int i = 0; i < lists.size(); i++) {
        ret = mergeTwoLists(ret, lists[i]);
    }
    return ret;
}

int main() {
    ListNode *l1 = new
    system("pause");
    return 0;
}