#include<iostream>
using namespace std;
#include<algorithm>
#include<string>

// 快速幂
// unsigned long long function(int p, int t) {
//     unsigned long long res = p;
//     unsigned long long mul = 10;
//     int num = 1;
//     while (num <= t) {
//         int temp = t & num;
//         if(temp != 0)
//             res *= mul;
//         num *= 2;
//         if(num > t) break;
//         mul *= mul;
//     }
//     return res;
// }

string function(int p, int t) {
    string res = to_string(p);
    res.insert(res.size(), t, '0');
    return res;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, t;
        cin >> p >> t;
        cout << function(p, t) << endl;
    }
    return 0;
}