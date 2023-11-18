#include<iostream>
using namespace std;
#include<vector>
#include<stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};  

bool isPalindrome(ListNode* head) {
    int size = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    if(size == 0 || size == 1) return true;
    stack<int> nums;
    int i = size / 2;
    temp = head;
    while (i--) {
        nums.push(temp->val);
        temp = temp->next;
    }
    if(size % 2 == 1) temp = temp->next;
    while (!nums.empty()) {
        if(nums.top() == temp->val)
            temp = temp->next;
        else
            return false;
        nums.pop();
    }
    return true;
}

int main(int argc, char const *argv[]) {
    ListNode* l5 = new ListNode(1);
    ListNode* l4 = new ListNode(2, l5);
    ListNode* l3 = new ListNode(3, l4);
    ListNode* l2 = new ListNode(2, l3);
    ListNode* l1 = new ListNode(1, l2);
    cout << isPalindrome(l1) << endl;
    return 0;
}
