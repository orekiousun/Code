//
// Created by ousun on 2024/11/30.
// 区间和：https://www.programmercarl.com/kamacoder/0058.%E5%8C%BA%E9%97%B4%E5%92%8C.html#%E6%80%9D%E8%B7%AF
// 区间和：https://kamacoder.com/problempage.php?pid=1070
//

#include <iostream>
using namespace std;
#include <vector>

// 构造前缀和
vector<int> makePrefixSum(vector<int>& arr) {
    int size = arr.size();
    vector<int> prefixSum(size + 1, 0);
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
        prefixSum[i + 1] = sum;
    }

    return prefixSum;
}

// acm输入
int main() {
    // 第一行：表示元素个数
    // 接下来n行：表示元素
    // 接下来m行：表示要计算的区间
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> prefixSum = makePrefixSum(arr);
    // 构造前缀和
    int x, y;
    while (cin >> x >> y) {
        cout << prefixSum[y + 1] - prefixSum[x] << endl;
    }
    return 0;
}