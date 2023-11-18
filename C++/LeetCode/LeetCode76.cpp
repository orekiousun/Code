#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>

string minWindow(string s, string t) {
    unordered_map<char, int> tmap, smap;
    int left = 0, correct = 0;
    string res = s + "initialize a max string";
    // 对于t制作字符出现数的字典
    for (auto item : t) 
        tmap[item]++;

    for (int right = 0; right < s.size(); ++right) {
        // smap维护的是当前窗口内的字符出现数的字典
        smap[s[right]]++;
        // 当前right对应s的字符是在t中出现的，并且数量上还没有达到冗余，是一次有效添加
        if (tmap[s[right]] >= smap[s[right]])
            correct++;
        // 字符串最短是空串 && 如果left对应的字符是冗余，那么进行右移删除
        while (left < right && smap[s[left]] > tmap[s[left]])
            smap[s[left++]]--;
        if (correct == t.size()){
            // 窗口内已经满足t串的所有字符
            if (right - left + 1 < res.size())
                res = s.substr(left, right - left + 1);
        }

    }
    return res == s + "initialize a max string" ? "" : res;
}

int main(int argc, const char** argv) {
    string s = "bba", t = "ab";
    cout << minWindow(s, t) << endl;
    system("pause");
    return 0;
}