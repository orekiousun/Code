//
// Created by cd_ouymh on 2025/4/8.
// 复原ip地址：https://www.programmercarl.com/0093.%E5%A4%8D%E5%8E%9FIP%E5%9C%B0%E5%9D%80.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 复原ip地址：https://leetcode.cn/problems/restore-ip-addresses/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>

void backtrack(vector<string>& ret, vector<string>& tmpNums, const string& str, int idx) {
    if (tmpNums.size() > 4) return;
    if (idx == str.size()) {
        if (tmpNums.size() == 4) {
            string retStr = tmpNums[0] + "." + tmpNums[1] + "." + tmpNums[2] + "." + tmpNums[3];
            cout << retStr << endl;
            ret.push_back(retStr);
        }
        return;
    }

    for (int i = idx; i < str.size(); ++i) {
        string subStr = str.substr(idx, i - idx + 1);
        int num;
        // stoi 可能转换失败
        try {
            num = stoi(subStr);
        } catch(const out_of_range& e) {
            num = -1;
        }
        if (subStr.size() == 1) {
            tmpNums.push_back(subStr);
            backtrack(ret, tmpNums, str, i + 1);
            tmpNums.pop_back();
        }
        else if (subStr[0] != '0' && num >= 0 && num <= 255 && tmpNums.size() < 4) {
            tmpNums.push_back(subStr);
            backtrack(ret, tmpNums, str, i + 1);
            tmpNums.pop_back();
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    vector<string> tmpNums;
    backtrack(ret, tmpNums, s, 0);
    return ret;
}

int main() {
    string s = "25525511135";
    restoreIpAddresses(s);
    return 0;
}