#include<iostream>
using namespace std;
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {    
    if(head == NULL) return false;
    ListNode* fast;        
    ListNode* slow;
    if(head->next != NULL) fast = head->next;
    else return false;
    if(fast->next != NULL) slow = fast->next;
    else return false;
    while (fast != slow) {
        if(fast -> next != NULL)
            fast = fast->next;
        else 
            return false;
        if(slow->next != NULL)
            slow = slow->next;
        else 
            return false;
        if(slow->next != NULL)
            slow = slow->next;
        else 
            return false;
    }
    return true;
}

int main() {

    system("pause");
    return 0;
}