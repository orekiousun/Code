#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>

int main(int argc, char const *argv[]) {
    int size;
    cin >> size;
    int nums[size + 1];
    for (int i = 1; i <= size; i++) {
        int temp;
        cin >> temp;
        nums[i] = temp;
    }
    unordered_map<int, int> map;
    int res = size + 1;
    for (int i = 1; i <= size; i++) {
        if(map[nums[i]] == 0)
            map[nums[i]] = i;
        else {
            res = min(i - map[nums[i]] + 1, res);
            map[nums[i]] = i;
        }
    }
    cout << (res == size + 1 ? -1 : res) << endl;
    system("pause");
    return 0;
}