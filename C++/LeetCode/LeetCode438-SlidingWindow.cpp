#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<unordered_map>

vector<int> findAnagrams(string s, string p) {
    int sLen = s.size(), pLen = p.size();
    vector<int> ret;
    if(sLen < pLen) return ret;
    vector<int> sCount(26, 0);
    vector<int> pCount(26, 0);

    for(int i = 0; i < pLen; i++) {
        pCount[p[i] - 'a'] ++;
        sCount[s[i] - 'a'] ++;
    }
    if(sCount == pCount) ret.push_back(0);

    // 开始查找
    for(int i = 0; i < sLen - pLen; i++) {
        sCount[s[i] - 'a']--;
        sCount[s[i + pLen] - 'a']++;
        if(sCount == pCount) ret.push_back(i + 1);
    }
    return ret;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = findAnagrams(s, p);
    system("pause");
    return 0;
}