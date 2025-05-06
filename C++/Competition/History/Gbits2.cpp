#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>

#define maxInt 0x7ffffff

int Prim(unordered_map<int, unordered_map<int, int>>& map, int s) {
    unordered_map<int, int> distance;
    unordered_map<int, bool> visited;
    for (auto item : map[s]) {
        distance[item.first] = item.second;
    }
    int count = 0, ans = 0;
    while (count != map.size()) {
        int minDistance = maxInt;
        for (auto item : distance) {
            if(!visited[item.first] && item.second < minDistance)
                minDistance = item.second;
                s = item.first;
        }
        ans += minDistance;
        visited[s] = true;
        for (auto item : map[s]) {
            if(!visited[item.first]) {
                distance[item.first] = distance[item.first] == 0 ? item.second : min(item.second, distance[item.second]);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
