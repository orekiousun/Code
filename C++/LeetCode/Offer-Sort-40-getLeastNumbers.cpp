#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
    排完序返回即可，也可以考虑使用优先队列
*/

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    vector<int> ans(k);
    for (int i = 0; i < k; i++) {
        ans[i] = arr[i];
    }
    return ans;
}

// K佬快排代码
void quickSort(vector<int>& arr, int l, int r) {
    // 子数组长度为 1 时终止递归
    if (l >= r) return;
    // 哨兵划分操作（以 arr[l] 作为基准数）
    int i = l, j = r;
    while (i < j) {
        while (i < j && arr[j] >= arr[l]) j--;
        while (i < j && arr[i] <= arr[l]) i++;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[l]);
    // 递归左（右）子数组执行哨兵划分
    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
