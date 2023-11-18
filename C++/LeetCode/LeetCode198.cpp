#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int rob(vector<int>& nums) {
    int size = nums.size();
    if(size == 1) return nums[0];
    
    vector<int> pre(nums.size(), 0);
    
    pre[0] = nums[0];
    pre[1] = nums[1];

    bool previsited = 0;
    for (int i = 2; i < nums.size(); i++){
        pre[i] = i >= 3 ? max(pre[i - 2], pre[i - 3]) + nums[i] : pre[i - 2] + nums[i];
    }
    return max(pre[size - 2], pre[size - 1]);
}

int main()
{
    vector<int> nums{2, 7, 9 ,3, 1};
    cout << rob(nums) << endl;
    system("pause");
    return 0;
}