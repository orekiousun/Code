#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

bool detectCircle(unordered_map<int, vector<int>>& map) {
    unordered_map<int, int> parent;
    for (auto item : map) {
        if(parent.count(item.first) == 0)
            parent[item.first] = item.first;
        int minParent;
        for(auto num : item.second) {
            if(parent.count(num) == 0)
                parent[num] = num;
            else if(parent[num] == parent[item.first]) return true;
            parent[num] = min(parent[num], parent[item.first]);
            parent[item.first] = min(parent[item.first], parent[num]);
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    string str;
    cin >> str;
    vector<int> nums;
    for (auto c : str) {
        if(c <= '9' && c >= '0') {
            nums.push_back(c - '0');
        }
    }
    if(nums.empty()) {
        cout << "No" << endl;
        return 0;
    }
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < nums.size(); i++) {
        if(map.count(nums[i]) == 0) {
            vector<int> temp{nums[i + 1]};
            map[nums[i]] = temp;
        }
        else {
            map[nums[i]].push_back(nums[i + 1]);
        }
        i++;
    }
    cout << (detectCircle(map) ? "Yes" : "No") << endl;
    return 0;
}
