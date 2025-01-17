//
// Created by cd_ouymh on 2025/1/17.
// 反转字符串：https://www.programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html
// 反转字符串：https://leetcode.cn/problems/reverse-string/
//

#include <iostream>
using namespace std;
#include <vector>

void reverseString(vector<char>& s) {
    int len = s.size();
    for (int i = 0; i < len / 2; ++i) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int main() {
    return 0;
}


