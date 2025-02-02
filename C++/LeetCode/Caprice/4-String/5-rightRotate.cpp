//
// Created by ousun on 2025/2/2.
// 右旋字符串：https://www.programmercarl.com/kamacoder/0055.%E5%8F%B3%E6%97%8B%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
// 右旋字符串：https://kamacoder.com/problempage.php?pid=1065
//

#include <iostream>
using namespace std;
#include <vector>

// 翻转字符串的前k个元素
void reverseString(string &s, int left, int right) {
    for (int i = 0; i < (right - left + 1) / 2; ++i) {
        char c = s[left + i];
        s[left + i] = s[right - i];
        s[right - i] = c;
    }
}

// 先将整个全部翻转一遍，再翻转前k个
string rightRotate(string s, int k) {
    reverseString(s, 0, s.size() - 1);
    reverseString(s, 0, k - 1);
    reverseString(s, k, s.size() - 1);
    return s;
}

int main() {
    cout << rightRotate("abcdefg", 2) << endl;
    return 0;
}
