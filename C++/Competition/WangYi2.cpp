#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

int main(int argc, const char** argv) {
    int C, N;     // C表示无人机数量，N请求次数
    cin >> C >> N;
    vector<pair<int, int>> vec(N, make_pair(0, 0));
    queue<pair<int, int>> waitQueue;     // 指定执行失败的队列
    queue<pair<int, int>> cancelQueue;   // 派遣指令成功，等待返回的队列
    unordered_set<int> returnSet;        // 返回指令失败，表示派遣指令等待返回
    int remain = C;
    for (int i = 0; i < N; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    for (int i = 0; i < N; i++) {
        int ans;
        // 如果为派遣指令
        if(vec[i].first >= 0) {
            if(vec[i].second <= remain) {   // 表示当前仓库中飞机数量足够此次派遣
                ans = vec[i].second;
                remain -= vec[i].second;
                cancelQueue.push(vec[i]);   // 派遣指令执行成功，加入到等到返回的队列中
            }
            else if(vec[i].second > C && remain == C) {   // 表示当前仓库中所有无人机均未被派遣，且需要升级仓库
                ans = vec[i].second;
                remain = 0;
                C = vec[i].second;
                cancelQueue.push(vec[i]);   // 派遣指令执行成功，加入到等到返回的队列中
            }
            else {
                ans = 0;
                waitQueue.push(vec[i]);     // 否则，派遣失败
            }
        }
        else { // 如果为返回指令
            ans = 0;
            if(vec[i].second == cancelQueue.front().first) {   // 表示返回的是返回队列中的第一个指令，直接返回即可
                remain += cancelQueue.front().second;   // 返回无人机，已经唤醒
                cancelQueue.pop();
            }
            else {  // 否则，表示之前有指令未返回，加入到睡眠状态
                returnSet.insert(vec[i].second);
            }
        }

        // 检测返回队列
        while (returnSet.find(cancelQueue.front().first) != returnSet.end()) {
            remain += cancelQueue.front().second;
            returnSet.erase(cancelQueue.front().first);
            cancelQueue.pop();
        }
        while (!waitQueue.empty()) {
            pair<int, int> temp = waitQueue.front();
            if(temp.second <= remain) {   // 表示当前仓库中飞机数量足够此次派遣
                ans += temp.second;
                remain -= temp.second;
                cancelQueue.push(temp);   // 派遣指令执行成功，加入到等到返回的队列中
            }
            else if(temp.second > C && remain == C) {   // 表示当前仓库中所有无人机均未被派遣，且需要升级仓库
                ans += temp.second;
                remain = 0;
                C = temp.second;
                cancelQueue.push(temp);   // 派遣指令执行成功，加入到等到返回的队列中
            }
            else {
                break;
            }
            waitQueue.pop();
        }
        cout << ans << endl;
    }
    return 0;
}