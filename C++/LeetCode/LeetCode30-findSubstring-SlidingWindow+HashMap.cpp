#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>

/*
    给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
    s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
    例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
    返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
*/

bool compareMap(map<string, int>& originMap, map<string, int>& recordMap) {
    for (map<string, int>::iterator it = originMap.begin(); it != originMap.end() ; it++) {
        if (recordMap[it->first] != originMap[it->first]) return false;
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
    int wordsCnt = words.size(), wordsLen = words[0].size();
    vector<int> res;
    map<string, int> wordsMap;
    for (auto str : words) {
        wordsMap[str] += 1;
    }

    // 滑动窗口，根据wordsLen的次数进行滑动
    for (int i = 0; i < wordsLen; ++i) {
        map<string, int> recordMap;
        int curBeginIndex = i, curIndex = i;

        // 初始化滑动窗口
        for (int j = 0; j < wordsCnt - 1; j++) {
            string subStr = s.substr(curIndex, wordsLen);
            recordMap[subStr] += 1;
            curIndex += wordsLen;
        }

        // 开始窗口滑动
        while (curBeginIndex + wordsCnt * wordsLen <= s.size()) {
            recordMap[s.substr(curBeginIndex + (wordsCnt - 1) * wordsLen, wordsLen)] += 1;
            if(compareMap(wordsMap, recordMap))
                res.push_back(curBeginIndex);
            recordMap[s.substr(curBeginIndex, wordsLen)] -= 1;
            curBeginIndex += wordsLen;
        }
    }

    return res;
}

int main() {
    // s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
    string s = "barfoothefoobarman";
    vector<string> words{"foo","bar"};
    vector<int> res = findSubstring(s, words);
    for (vector<int>::iterator it = res.begin(); it != res.end() ; it++) {
        cout << *it << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}