#include<iostream>
using namespace std;
#include<vector>
#include<string>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{
    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* head = new ListNode(1, n2);
    int n = 2;

    if(res->next == NULL)
    {
        res = NULL;
        return res;
    } 

    ListNode* res = head;
    ListNode* frontNode = head;
    ListNode* backNode = head;
    for(int i = 0; i < n; i++)
    {
        backNode = backNode->next;
    }
    if(backNode == NULL)
    {
        res = res->next;
    }
    while (backNode->next != NULL)
    {
        frontNode = frontNode->next;
        backNode = backNode->next;
    }
    frontNode->next = frontNode->next->next;
    system("pause");
    return 0;
}