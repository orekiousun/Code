#include<iostream>
using namespace std;
#include<vector>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 先将链表两两合并
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) 
    {
        // 如果ab中任意一个时NULL，就返回不是NULL那个
        // 如果a, b均为NULL，就返回NULL
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) // 当a, b均不为空时
        {
            if (aPtr->val < bPtr->val) 
            {
                tail->next = aPtr; aPtr = aPtr->next;
            } 
            else 
            {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        // 最后将还没有读到末尾的链表全部赋值给tail->next
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    // 分治 两两合并，再合并  --  归并
    ListNode* merge(vector <ListNode*> &lists, int l, int r) 
    {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return merge(lists, 0, lists.size() - 1);
    }
};

int main()
{
    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(2, l1);
    ListNode* l3 = new ListNode(1, l2);

    ListNode* l4 = new ListNode(2);
    ListNode* l5 = new ListNode(1, l4);
    ListNode* l6 = new ListNode(1, l5);

    // ListNode* l7 = new ListNode(6);
    // ListNode* l8 = new ListNode(2, l7);

    lists.push_back(l3);
    lists.push_back(l6);
    // lists.push_back(l8);

    int size = lists.size();

    ListNode* temp;

    // if(size == 0) return NULL;
    // else
    // {
    //     int count = 0;
    //     for(int i = 0; i < size; i++)
    //     {
    //         if(lists[i] == NULL)
    //         {
    //             count++;
    //         }
    //     }
    //     if(count == size) return NULL;
    // }

    while (1)
    {
        int min = 10000, index = 0, count = 0;
        for (int i = 0; i < size; i++)
        {
            if(lists[i] == NULL)
            {
                count++;
            }
            else if(lists[i]->val <= min)
            {
                min = lists[i]->val;
                index = i;
            }
        }
        if(count == size) break;

        temp = new ListNode(min);
        ListNode* first = temp;
        temp = temp->next;

        lists[index] = lists[index]->next;

    }

    
    temp = res;
    while (res != NULL)
    {
        if(res->next->val == 100001)
        res->next = NULL; 
        res = res->next;
    }



    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    

    system("pause");
    return 0;
}