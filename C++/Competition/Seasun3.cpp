#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include <unordered_map>
#include <string>

/*

 */

void dfs(vector<vector<int>>& connectedArray, vector<bool>& visited, int i) {
    if (visited[i] == true)
        return;

    visited[i] = true;
    for (int j = 0; j < connectedArray[i].size(); ++j) {
        if (connectedArray[i][j] == 1) {
            dfs(connectedArray, visited, j);
        }
    }
}

int getIsLandGroupCount(vector<vector<int>>& connectedArray) {
    int res = 0, size = connectedArray.size();
    vector<bool> visited(size, false);

    for (int i = 0; i < size; ++i) {
        if (visited[i] == false) {
            res += 1;
            dfs(connectedArray, visited, i);
        }
    }

    return res;
}

void backtrack(vector<string>& elements, unordered_map<char, vector<int>>& map, vector<int>& record, int pos, string& destStr, vector<int>& res) {
    if (pos == destStr.size()) {
        res = record;
        return;
    }

    vector<int> temp = map[destStr[pos]];
    for (int i = 0; i < temp.size(); ++i) {
        string str = elements[temp[i]];
        string subStr = destStr.substr(pos, str.size());
        if (str == subStr) {
            record.push_back(temp[i]);
            backtrack(elements, map, record, pos + str.size(), destStr, res);
            record.pop_back();
        }
    }
}

// "e9cebd4395",["4395", "e9", "e903", "cebd"]
// 思路：回溯（找得到就继续找，找不到就回溯）
vector<int> StringAssemble(string destStr, vector<string>& elements) {
    // 记录首字母
    unordered_map<char, vector<int>> map;
    for (int i = 0; i < elements.size(); ++i) {
        map[elements[i][0]].push_back(i);
    }

    vector<int> record;
    vector<int> res;
    backtrack(elements, map, record, 0, destStr, res);
    return res;
}

int main(int argc, char const *argv[]) {
    string destStr = "e9cebd4395";
    vector<string> elements{"4395", "e9", "e903", "cebd"};
    vector<int> res = StringAssemble(destStr, elements);
    return 0;
}
