#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*
    给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
    你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
    要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
    文本的最后一行应为左对齐，且单词之间不插入额外的空格。

    注意:
    单词是指由非空格字符组成的字符序列。
    每个单词的长度大于 0，小于等于 maxWidth。
    输入单词数组 words 至少包含一个单词。
 */


vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    int left = 0, right = 0;
    int curLen = 0;
    vector<string> ret;
    while (right < n) {
        curLen = 0;
        while (right < n && curLen + words[right].size() + right - left <= maxWidth) {
            curLen += words[right].size();
            right++;
        }

        string str = "";
        if (right != n) {
            int i = right - 1, interval = maxWidth - curLen;

            while (i >= left) {
                str.insert(0, words[i]);
                int temp = i == left ? 0 : interval / (i - left);
                interval -= temp;
                string nullStr(temp, ' ');
                str.insert(0, nullStr);
                i--;
            }

        }
        else {
            for (int i = left; i < right; ++i) {
                str += words[i];
                str += " ";
            }
            str.erase(str.size() - 1, 1);
        }
        string nullStr(maxWidth - str.size(), ' ');
        str += nullStr;
        left = right;
        ret.push_back(str);
    }

    return ret;
}

int main() {
    vector<string> words{"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    int maxWidth = 16;
    vector<string> ret = fullJustify(words, maxWidth);
    return  0;
}