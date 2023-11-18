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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* root;
    ListNode* temp;
    if(list1 == nullptr) return list2;
    else if(list2 == nullptr) return list1;
    if(list1->val < list2->val) {
        root = list1;
        list1 = list1->next;
    } 
    else {
        root = list2;      
        list2 = list2->next;
    }
    temp = root;  
    while (list1 != nullptr || list2 != nullptr) {
        if(list2 == nullptr) {
            temp->next = list1;
            list1 = list1->next; 
        }
        else if(list1 == nullptr) {
            temp->next = list2;
            list2 = list2->next;
        }
        else if(list1->val < list2->val ) {
            temp->next = list1;
            list1 = list1->next; 
        } 
        else if(list1->val >= list2 -> val) {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    return root;
}

int main() {
    ListNode* n14 = new ListNode(4);
    ListNode* n12 = new ListNode(2, n14);
    ListNode* list1 = new ListNode(1, n12);

    ListNode* n24 = new ListNode(4);
    ListNode* n23 = new ListNode(3, n24);
    ListNode* list2 = new ListNode(1, n23);

    ListNode* root = mergeTwoLists(list1, list2);

    system("pause");
    return 0;
}