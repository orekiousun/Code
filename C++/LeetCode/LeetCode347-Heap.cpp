#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>

class MyCompare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> countMap;
    vector<pair<int, int>> numCount;
    vector<int> res;
    for(int num : nums) {
        if(countMap.find(num) == countMap.end()) 
            countMap[num] = 1;
        else 
            countMap[num] += 1;
    }
    for (pair<int, int> it : countMap) {
        numCount.push_back(it);
    }
    make_heap(numCount.begin(), numCount.end(), MyCompare());
    while (res.size() < k) {
        res.push_back(numCount[0].first);
        pop_heap(numCount.begin(), numCount.end() - res.size() + 1, MyCompare());
    }
    return res;
}

int main() {
    vector<int> nums{1, 1, 1, 2, 2, 3};
    vector<int> res = topKFrequent(nums, 2);
    system("pause");
    return 0;
}