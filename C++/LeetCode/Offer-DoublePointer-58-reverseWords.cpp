#include<iostream>
using namespace std;
#include<vector>
#include<string>

/*
    题目一：
        输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
        例如输入字符串"I am a student. "，则输出"student. a am I"。

    方法：
        双指针，前指针记录单词头，后指针记录单词尾，当遍历到空格时加入当前单词，重置指针，开始寻找下一个单词。

    题目二：
        字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
        比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
*/

string reverseWords(string s) {
    string res = "";
    if(s.size() == 0) return "";
    s.insert(0, 1, ' ');
    int left = s.size() - 1, right = left;
    for ( ;left > 0; left--) {
        if(s[left] == ' ') right = left - 1;
        if(s[left - 1] == ' ') {
            string temp = s.substr(left, right - left + 1);
            if(temp != "")
                res += temp + " ";
        }
    }
    if (!res.empty()) res.pop_back();
    return res;
}

string reverseLeftWords(string s, int n) {
    string temp = s.substr(0, n);
    s.erase(0, n);
    return s.append(temp);
}

int main(int argc, char const *argv[]) {
    string res = reverseLeftWords("abcdef", 2);
    cout << res << endl;
    return 0;
}