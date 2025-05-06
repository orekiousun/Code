#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    int size = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
        
    }
    
    return 0;
}