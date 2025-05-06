#include<iostream>
using namespace std;
#include<vector>

struct ListNode {
	int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* formatList(ListNode* head) {
    ListNode* root = new ListNode(0);

    root->next = head;

    while (1) {
        if(head->next != nullptr) {
            ListNode* temp1 = head->next;
            if(temp1->next != nullptr){
                ListNode* temp2 = temp1->next;
                temp1->next = temp2->next;
                temp2->next = root->next;
                root->next = temp2;
                head = temp1;
            }
            else{
                break;;
            }
        }
        else{
            break;
        }

    }
    return root->next;
}

int main(int argc, const char** argv) {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    formatList(l1);
    return 0;
}