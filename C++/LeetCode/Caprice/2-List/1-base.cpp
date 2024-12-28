//
// Created by cd_ouymh on 2024/12/7.
//

#include <iostream>
using namespace std;
#include <vector>

// 链表结构的定义
struct ListNode {
    int val;                                // 节点上的值
    ListNode* next;                         // 下一个节点
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};

int main() {
    ListNode* node = new ListNode(1);
    return 0;
}
