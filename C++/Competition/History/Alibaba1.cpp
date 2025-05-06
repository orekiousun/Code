#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

bool detectNumber(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if(num % i == 0) return true;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int res = 0;
        string temp;
        cin >> temp;
        unordered_map<char, int> map;
        for (auto item : temp) {
            map[item]++;
            res = max(res, map[item]);
        }
        cout << (detectNumber(res) ? "YES" : "NO") << endl;
    }
    return 0;
}
