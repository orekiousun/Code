#include<iostream>
using namespace std;
#include<vector>

/*
    输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
    获取到从倒数第k个开始的子链表
    采用双指针，先走k步，再进行两个指针一起走
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (k--) {
        if (fast != nullptr) 
            fast = fast->next;
        else
            return nullptr;
    }
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(int argc, char const *argv[]) {

    return 0;
}
