#include<iostream>
using namespace std;
#include<vector>

int main(int argc, char const *argv[]) {
    int m, n;
    cin >> m >> n;
    vector<int> countM(m, 0);
    vector<int> countN(n, 0);
    int nums[m][n];
    int maxM = 0, maxN = 0, maxMIndex, maxNIndex;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
            if(nums[i][j] == 1) {
                countM[i]++;
                if(countM[i] > maxM) {
                    maxM = countM[i];
                    maxMIndex = i;
                }
                countN[j]++;
                if(countN[i] > maxN) {
                    maxN = countN[j];
                    maxNIndex = j;
                }
            }
        }
    }
    vector<pair<int, int>> ans;
    bool flag = true;
    while (flag) {
        ans.push_back(make_pair(maxMIndex + 1, maxNIndex + 1));
        maxM = 0, maxN = 0;
        for (int i = 0; i < m; i++) {
            if(nums[i][maxNIndex] == 1) {
                countM[i]--;
                countN[maxNIndex]--;
                nums[i][maxNIndex] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if(nums[maxMIndex][i] == 1) {
                countM[maxMIndex]--;
                countN[i]--;
                nums[maxMIndex][i] = 0;
            }
        }
        flag = false;
        for (int i = 0; i < m; i++) {
            if(countM[i] != 0) {
                flag = true;
                if(countM[i] >= maxM) {
                    maxM = countM[i];
                    maxMIndex = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if(countN[i] != 0) {
                flag = true;
                if(countN[i] >= maxN) {
                    maxN = countN[i];
                    maxNIndex = i;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto item : ans) {
        cout << item.first << "," << item.second << endl;
    }
    return 0;
}
