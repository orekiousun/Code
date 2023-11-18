#include<iostream>
using namespace std;
#include<vector>

vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> left, right;
    left.resize(size, 1);
    right.resize(size, 1);
    for(int i = 1; i < size; i++) {
        left[i] = left[i - 1] * nums[i - 1];
        right[size - i - 1] = right[size - i] * nums[size - i];
    }
    for(int i = 0; i < size; i++) {
        left[i] = left[i] * right[i]; 
    }
    return left;
}

void printVector(vector<int>& nums) {
    vector<int>::iterator it = nums.begin();
    while (it != nums.end()) {
        cout << *(it) << " ";
        it++;
    }
    cout << endl;
}

int main() {
    vector<int> nums{1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums); 
    printVector(res);
    system("pause");
    return 0;
}