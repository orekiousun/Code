#include<iostream>
using namespace std;
#include<unordered_set>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 使用unordered_set存储办法
ListNode *detectCycle(ListNode *head) 
{
    if(head == NULL) return NULL;
    unordered_set<ListNode*> recordSet;
    recordSet.insert(head);
    while (head -> next != NULL)
    {
        head = head->next;
        if(recordSet.find(head) != recordSet.end()) return head;
        recordSet.insert(head);
    }
    return NULL;
}

// 双指针方法
ListNode *detectCycle2(ListNode *head) 
{
    if(head == NULL) return NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break;
        // 此时slow走过的路数一定是环的大小的整数倍
    }
    if(fast == NULL) return NULL;
    else
    {
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
}

int main()
{
    ListNode* head = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n0 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    head->next = n2;
    n2->next = n0;
    n0->next = n4;
    n4->next = n2;
    cout << detectCycle2(head)->val << endl;
    system("pause");
    return 0;
}
