#include<iostream>
using namespace std;

// 暴力法
int countSubstrings(string s, int flag) {
    int size = s.size();
    int ret = size;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int left = i, right = j;
            while (left < right && s[left] == s[right]) {
                left++;
                right--;
            }
            if(left >= right) ret++;
        }
    }
    return ret;
}

// 巧妙法
int countSubstrings(string s) {
    int size = s.size();
    int ret = 0;

    for (int i = 0; i < size; i++) {
        int left = i, right = i;
        while (left >= 0 && right < size && s[left] == s[right] ){
            ret++;
            left--;
            right++;
        }
    }

    for (int i = 0; i < size; i++) {
        int left = i, right = i + 1;
        while (left >= 0 && right < size && s[left] == s[right] ){
            ret++;
            left--;
            right++;
        }
    }

    return ret;
}



int main() {
    string s = "aaabaaa";
    cout << countSubstrings(s) << endl;
    system("pause");
    return 0;
}