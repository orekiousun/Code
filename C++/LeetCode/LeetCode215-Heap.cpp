#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    int res = -1;
    for(int i = 0; i < k ; i++) {
        pop_heap(nums.begin(), nums.end());
        res = nums.back();
        nums.pop_back();
    }
    return res;
}

int main() {
    vector<int> nums{3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << findKthLargest(nums, k) << endl;
    system("pause");
    return 0;
}