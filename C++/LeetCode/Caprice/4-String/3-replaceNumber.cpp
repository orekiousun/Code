//
// Created by cd_ouymh on 2025/1/17.
// 替换数字：https://www.programmercarl.com/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.html#%E6%80%9D%E8%B7%AF
// 替换数字：https://kamacoder.com/problempage.php?pid=1064
//

#include <iostream>
using namespace std;
#include <string>

string replaceNumber(string s, string replaceStr) {
    int numberCnt = 0;
    for (auto c : s) {
        if (c >= '0' && c <= '9') numberCnt++;
    }
    if (numberCnt == 0) return s;
    int newLen = s.size() + (replaceStr.size() - 1) * numberCnt;
    int idx = 0;
    string retStr(newLen, ' ');
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            for (int j = 0; j < replaceStr.size(); ++j) {
                retStr[idx++] = replaceStr[j];
            }
        }
        else retStr[idx++] = s[i];
    }

    return retStr;
}

int main() {
    cout << replaceNumber("aaa1bbb1", "xxx") << endl;
    return 0;
}