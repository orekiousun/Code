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

// 数组/vector方法
void merge(vector<int>& arr, int begin, int mid, int end)
{
    vector<int> res;
    int first = begin, second = mid + 1;
    while (first != mid + 1 && second != end + 1)
    {
        if(arr[first] <= arr[second])
        {
            res.push_back(arr[first]);
            first++;
        }
        else
        {
            res.push_back(arr[second]);
            second++;
        }
    }
    if(first != mid + 1)
    {
        while (first != mid + 1)
        {
            res.push_back(arr[first]);
            first++;
        }
    }
    else if(second != end + 1)
    {
        while (second != end + 1)
        {
            res.push_back(arr[second]);
            second++;
        }
    }

    for(int i = begin, j = 0; i != end + 1; i++)
    {
        arr[i] = res[j];
        // cout << res[j] << " ";
        j++;
    }
    // cout << endl;
}
void mergeSort(vector<int>& arr, int begin, int end)
{
    if(begin == end)
    {
        return;
    }
    else
    {
        int mid = (begin + end) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
        return;
    }
}
// int main()
// {
//     ListNode* l3 = new ListNode(3);
//     ListNode* l2 = new ListNode(1, l3);
//     ListNode* l1 = new ListNode(2, l2);
//     ListNode* head = new ListNode(4, l1);
//     ListNode* temp = head;
//     vector<int> arr;
//     while (temp != NULL)
//     {
//         cout << temp->val << " ";
//         arr.push_back(temp->val);
//         temp = temp->next;
//     }
//     cout << endl;
//     mergeSort(arr, 0, arr.size() - 1);
//     for(int i = 0; i < arr.size(); i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     system("pause");
//     return 0;
// }

// List方法
ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
{
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    ListNode* left = l1;
    ListNode* right = l2;
    while (left != NULL && right != NULL)
    {
        if(left->val <= right->val)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    if(left != NULL)
    {
        tail->next = left;
    }
    else if(right != NULL)
    {
        tail->next = right;
    }
    return head->next;
}

ListNode* mergeSortList(ListNode* head, ListNode* tail)
{
    if(head == NULL) return head;
    // 如果head和tail是相邻的，就将head的next设置为NULL，拆分链表
    if(head->next == tail)
    {
        head->next = NULL;
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != tail)
    {
        fast = fast->next;
        slow = slow->next;
        if(fast != tail)
            fast = fast->next;
    }
    
    ListNode* mid = slow;
    return mergeTwoList(mergeSortList(head, mid), mergeSortList(mid, tail));
}

int main()
{
    ListNode* l3 = new ListNode(3);
    ListNode* l2 = new ListNode(1, l3);
    ListNode* l1 = new ListNode(2, l2);
    ListNode* head = new ListNode(4, l1);

    head = mergeSortList(head, NULL);
    ListNode* temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    system("pause");
    return 0;
}