#include <iostream>
using namespace std;
#include <vector>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* formatList(ListNode* head) {
    ListNode* cur = head;

    while (cur->next != nullptr && cur->next->next != nullptr) {
        // 先前插
        ListNode* next = cur->next;
        ListNode* temp = cur->next->next;
        next->next = temp->next;
        temp->next = head;
        head = temp;
        cur = next;
    }

    return head;
}

int main() {

}