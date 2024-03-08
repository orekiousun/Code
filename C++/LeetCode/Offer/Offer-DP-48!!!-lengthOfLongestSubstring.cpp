#include<iostream>
using namespace std;
#include<algorithm>
#include<unordered_map>

/*
    请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
    curSize记录了以i位结尾的最长不包含重复字符的字符串的长度
*/

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int curSize = 0, maxSize = 0;
    for (int i = 0; i < s.length(); i++) {
        // 注意这一步的处理，当新加入的字符在前面的字符中存在时，由于新加入的字符后的长度不可能比cruSize + 1长（如果更长，就一定会出现重复字符），所以要取最小值
        curSize = map.count(s[i]) == 0 ? curSize + 1 : min(curSize + 1, i - map[s[i]]);
        map[s[i]] = i;
        maxSize = max(maxSize, curSize);
    }
    return maxSize;
}

int main(int argc, char const *argv[]) {
    cout << lengthOfLongestSubstring("abba") << endl;
    return 0;
}
