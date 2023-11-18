#include<iostream>
using namespace std;
#include<vector>

// 归并排序

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> vLeft;
    vector<int> vRight;
    for (int i = left; i <= mid; i++) {
        vLeft.push_back(nums[i]);
    }
    for(int i = mid + 1; i <= right; i++) {
        vRight.push_back(nums[i]);
    }
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if(i == vLeft.size()) 
            nums[k] = vRight[j++];
        else if(j == vRight.size())
            nums[k] = vLeft[i++];
        // 也可以在数组尾部放一个无穷大的数作为哨兵牌避免数组索引越界
        else if(vLeft[i] < vRight[j]) {
            nums[k] = vLeft[i];
            i++;
        }
        else {
            nums[k] = vRight[j];
            j++;
        }
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    int mid = (left + right) / 2;
    if(left == right) {
        return;
    } 
    else {
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}

void printVector(const vector<int> nums) {
    for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums{5, 2, 4, 6, 1, 3};
    cout << "before sort:" << endl;
    printVector(nums);
    mergeSort(nums, 0 ,nums.size() - 1);
    cout << "after sort:" << endl;
    printVector(nums);
    system("pause");
    return 0;
}