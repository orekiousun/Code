#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool Cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second > p2.second)
        return true;
    else if(p1.second == p2.second)
        return p1.first > p2.first;
    else
        return false;
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<pair<int, float>> pictures(N, make_pair(0, 0.0));
    for (int i = 0; i < N; i++) {
        cin >> pictures[i].first >> pictures[i].second;
    }
    // 处理N = 1
    if(N == 1)
        return pictures[0].second;

    sort(pictures.begin(), pictures.end(), Cmp);
    float ans = 0;
    int currentMaxWidth = 512;
    int remain = 1024 * 1024;
    for (int i = 0; i < N; i++) {
        if(pictures[i].first <= currentMaxWidth) {
            if(remain == pictures[i].first * pictures[i].first && i != N-1) {
                pictures[i].first /= 2;
                ans += pictures[i].second / 4;
            }
            else {
                ans += pictures[i].second;
            }
        }
        else {
            int temp = pictures[i].first / currentMaxWidth;
            pictures[i].first = currentMaxWidth;
            ans += pictures[i].second / (temp * temp);
        }
        remain -= pictures[i].first * pictures[i].first;
        while (currentMaxWidth * currentMaxWidth > remain && currentMaxWidth != 1) {
            currentMaxWidth /= 2;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}