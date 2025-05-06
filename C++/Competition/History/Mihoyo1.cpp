#include<iostream>
using namespace std;
#include<string>

int main() {
    int level = 3, p = 1000000007;

    string str = "AABABAB";

    int res = 1;
    int count = 1;
    for (int i = 1; i < level; i++) {
        count *= 2;
    }
    count--;
    for (int i = 0; i < count; i++) {
        if(str[i * 2 + 1] != str[i * 2 + 2])
            res *= 2;
    }

    res = res % p;

    cout << res << endl;
    system("pause");
    return 0;
}