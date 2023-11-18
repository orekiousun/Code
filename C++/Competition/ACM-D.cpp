#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int left = intervals[0][0], right = intervals[0][1];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); i++) {
        if(right >= intervals[i][0]) {
            if(right <= intervals[i][1])
                right = intervals[i][1];
        }
        else {
            vector<int> temp{left, right};
            res.push_back(temp);
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    vector<int> temp{left, right};
    res.push_back(temp);
    return res;
}


int main(int argc, const char** argv) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m, res = 0, count = 0;
        unordered_map<int, vector<vector<int>>> map;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int key = x1 + y1;
            map[key].push_back({x1, x2});
            count += x2 - x1;
        }
        for (unordered_map<int, vector<vector<int>>>::iterator it = map.begin(); it != map.end(); it++) {
            map[(*it).first] = merge((*it).second);
            for (auto item : map[(*it).first]) {
                res += item[1] - item[0];
            }
        }
        cout << (count == res ? "YES" : "NO") << endl;
        cout << res << endl;
    }
    return 0;
}

