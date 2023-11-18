#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



int main()
{   
    ListNode* l12 = new ListNode(3);
    ListNode* l22 = new ListNode(4);
    ListNode* l11 = new ListNode(4, l12);
    ListNode* l21 = new ListNode(6, l22);
    ListNode* l1 = new ListNode(2, l11); 
    ListNode* l2 = new ListNode(5, l21); 

    ListNode* res = l1;

    while (l1 != NULL || l2 != NULL)
    {
        if(l1 == NULL) l1 = new ListNode();
        if(l2 == NULL) l2 = new ListNode();
        if(l1->next == NULL && l2->next == NULL)
        {
            // do nothing
        }
        else if(l1->next == NULL)
            l1->next = new ListNode();
        else if(l2->next == NULL)
            l2->next = new ListNode();
        
        int add = l1->val + l2->val;
        if(add >= 10)
        {
            if(l1->next == NULL)
                l1->next = new ListNode(1);
            else
                l1->next->val++;
        }
        l1->val = add % 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    

    system("pause");
    return 0;
}