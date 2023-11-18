#include<iostream>
using namespace std;
#include<vector>
#include<string>


int main(int argc, char const *argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    int i = s1.size() - 1, j = s2.size() - 1;
    while (i >= 0 && j >= 0) {
        if(s1[i] == s2[j]) {
            i--;
            j--;
        }
        else {
            i--;
        }
    }
    if(j == -1) cout << i + 2;
    else cout << 0;
    return 0;
}
