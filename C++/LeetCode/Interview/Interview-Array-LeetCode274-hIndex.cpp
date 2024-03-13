#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
    给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
    根据维基百科上 h 指数的定义：h 代表“高引用次数”
    一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数 是其中最大的那个。


 */

int hIndex(vector<int>& citations) {
    // 思路：遍历算出每次可以接受的最大的h指数
    sort(citations.begin(), citations.end(), greater<int>());
    int hMax = 0;
    for (int i = 0; i < citations.size(); ++i) {
        int h = i + 1;
        if (citations[i] >= h)
            hMax = max(hMax, h);
    }
    return hMax;
}

int main() {
    vector<int> citations{4,4,6,6,1,5};
    cout << hIndex(citations) << endl;
    return 0;
}