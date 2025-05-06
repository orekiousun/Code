#include<iostream>
using namespace std;
#include<vector>

int main() {
    int n;
    cin >> n;
    if(n < 6) {
        cout << 1 << endl;
        return 0;
    }
    int k = 2, num = 0;
    int minus = 0;
    while (num < n) {
        num = (1 + k) * (1 + k) * k / 2;
        minus += k*(k - 1);
        num -= minus + 1;
        if(num > n) break;
        else k++;
    }
    cout << k - 1 << endl;

    system("pause");
    return 0;
}