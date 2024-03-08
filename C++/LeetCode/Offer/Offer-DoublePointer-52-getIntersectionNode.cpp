#include<iostream>
using namespace std;
#include<vector>

/*
    输入两个链表，找出它们的第一个公共节点。

    方法：很重要！！！
        考虑构建两个指针A和B
        假设链表A长度为a，链表B长度为b，两链表公共部分长度为c
        ·指针A先遍历链表A，再遍历链表B，当第二次遍历到第一个公共节点处时，A走过的长度为 a + b - c
        ·指针B先遍历链表B，再遍历链表A，当第二次遍历到第一个公共节点处时，B走过的长度为 b + a - c
        -- 所以两个指针在公共节点处相遇
        如果两个链表没有公共节点，则它们会同时 = nullptr并返回
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA, *b = headB;
    while (a != b) {
        a = a == nullptr ? headB : a->next;
        b = b == nullptr ? headA : b->next;
    }
    return a;
}

int main(int argc, char const *argv[]) {
    ListNode* l1 = new ListNode(1); 
    ListNode* l2 = new ListNode(2); 
    ListNode* l3 = new ListNode(3); 
    ListNode* l4 = new ListNode(4); 
    ListNode* l5 = new ListNode(5); 
    ListNode* l6 = new ListNode(6); 
    ListNode* l7 = new ListNode(7); 

    ListNode* l8 = new ListNode(8);
    ListNode* l9 = new ListNode(9);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;

    l9->next = l8;
    l8->next = l3;

    ListNode* root = getIntersectionNode(l8, l1);
    return 0;
}
