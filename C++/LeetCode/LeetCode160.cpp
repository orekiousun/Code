#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptrA = headA, *ptrB = headB;
    vector<ListNode*> vecA;
    vector<ListNode*> vecB;
    while (ptrA != ptrB) {
        if(ptrA->next != nullptr) {
            vecA.emplace_back(ptrA);
            ptrA = ptrA->next;
        }
        if(ptrB->next != nullptr) {
            vecB.emplace_back(ptrB);
            ptrB = ptrB->next;
        }
        if(ptrA->next == nullptr && ptrB->next == nullptr) {
            break;
        }
    }
    vecA.emplace_back(ptrA);
    vecB.emplace_back(ptrB);
    if(ptrA != ptrB)
        return nullptr;
    int i = vecA.size() - 1, j = vecB.size() - 1;
    while (i >= 0 && j >= 0 && vecA[i] == vecB[j]) {
        i--;
        j--;
    }
    return vecA[++i];
}

int main(int argc, char const *argv[]) {
    ListNode* n4 = new ListNode(4);
    ListNode* n2 = new ListNode(2);
    n2->next = n4;
    ListNode* n1 = new ListNode(1);
    ListNode* n3 = new ListNode(3);
    n1->next = n2;
    n3->next = n2;
    ListNode* n9 = new ListNode(9);
    n9->next = n1;
    cout << getIntersectionNode(n4, n4)->val << endl;
    return 0;
}
