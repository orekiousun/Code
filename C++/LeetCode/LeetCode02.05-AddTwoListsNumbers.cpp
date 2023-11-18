class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) // 当l1，l2中任意全为空时退出循环
        {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            // z位数不足用0填充
            int sum = n1 + n2 + carry;
            if (!head) 
            {
                head = tail = new ListNode(sum % 10);
            } 
            else 
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1 != NULL) 
            {
                l1 = l1->next;
            }
            if (l2 != NULL) 
            {
                l2 = l2->next;
            }
        }
        if (carry > 0) 
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
