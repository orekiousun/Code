#include<iostream>
using namespace std;
#include<vector>


/*
    给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

    方法：
        1.维护两两个数组，分别记录前缀积和后缀积
        2维护一个数组，剩下的一个在执行过程中迭代
*/

// 维护两个数组
vector<int> constructArr(vector<int>& a, bool flag) {
    int size = a.size();
    if(size == 0) return a;
    vector<int> pre(size, 1);
    vector<int> back(size, 1);
    pre[0] = a[0], back[size - 1] = a[size - 1];
    for (int i = 1; i < size; i++) {
        pre[i] = pre[i - 1] * a[i];
        back[size - i - 1] = back[size - i] * a[size - i - 1];
    }
    for (int i = 0; i < size; i++) {
        a[i] = (i - 1 < 0 ? 1 : pre[i - 1]) * (i + 1 >= size ? 1 : back[i + 1]);
    }
    return a;    
}

// 维护一个数组
vector<int> constructArr(vector<int>& a) {
    int size = a.size();
    if(size == 0) return a;
    vector<int> res(size, 1);
    res[size - 1] = a[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        res[i] = res[i + 1] * a[i];
    }
    int mul = 1;
    for (int i = 0; i < size - 1; i++) {
        res[i] = mul * res[i + 1];
        mul *= a[i];
    }
    res[size - 1] = mul;
    return res;
}

int main(int argc, char const *argv[]) {
    vector<int> a{1, 2, 3, 4, 5};
    a = constructArr(a);
    return 0;
}