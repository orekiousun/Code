#include<iostream>
using namespace std;
#include<string>
#include<unordered_map>
/*
    在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
    粗暴法：先遍历一遍保存所有出现的次数，再从头遍历找到最前面只出现一次的元素
    优化：有序哈希表，逆序插入（哈希表的顺序会按照插入顺序排序，先插入的在前面，所以要逆序插入），第二次遍历的时候不是遍历字符串，而是遍历哈希表，找到第1个值为1的键
*/

// 粗暴法：
char firstUniqChar(string s, bool flag) {
    if(s == "") return ' ';
    unordered_map<char, int> map;
    for (char c : s) {
        map[c]++;
    }
    for (char c : s) {
        if(map[c] == 1) return c;
    }
    return ' ';
}

// 优化：
char firstUniqChar(string s) {
    if(s == "") return ' ';
    char ans = s[s.length() - 1];
    unordered_map<char, int> map;
    for (int i = s.length() - 1; i >= 0; i--) {
        map[s[i]]++;
    }
    for (auto item : map) {
        if(item.second == 1) return item.first;
    }
    return ' ';
}

int main(int argc, char const *argv[]) {
    cout << firstUniqChar("abaccdeff", true) << endl;
    return 0;
}
