#include<iostream>
using namespace std;
#include<vector>

int main(int argc, const char** argv) {
    int n, r;
    cin >> n >> r;
    int pos[n][3];
    int origin[3];
    for (int i = 0; i < n; i++) {
        cin >> pos[i][0] >> pos[i][1] >> pos[i][2];
    }
    cin >> origin[0] >> origin[1] >> origin[2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = (pos[i][0] - origin[0]) * (pos[i][0] - origin[0]) +
        (pos[i][1] - origin[1]) * (pos[i][1] - origin[1]) +
        (pos[i][2] - origin[2]) * (pos[i][2] - origin[2]);
        if(temp < r * r)
            ans++;
    }
    cout << ans;
    return 0;
}