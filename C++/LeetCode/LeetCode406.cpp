#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
    每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
    请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，
    其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
*/

class MyCompare {
public:
    bool operator()(vector<int>& v1, vector<int>& v2) {
        return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
    }
};

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<int> initVec{-1, -1};
    vector<vector<int>> res(people.size(), initVec);
    sort(people.begin(), people.end(), MyCompare());
    for (vector<int> temp : people) {
        int count = 0, i = 0;
        while (count < temp[1]) {
            if(res[i][0] == -1) count++;
            i++;
        }
        while (res[i][0] != -1) {
            i++;
        }
        res[i] = temp;
    }
    return res;
}

int main() {
    vector<int> v1{7, 0};
    vector<int> v2{4, 4};
    vector<int> v3{7, 1};
    vector<int> v4{5, 0};
    vector<int> v5{6, 1};
    vector<int> v6{5, 2};
    vector<vector<int>> people{v1, v2, v3, v4, v5, v6};
    vector<vector<int>> res = reconstructQueue(people);
    system("pause");
    return 0;
}