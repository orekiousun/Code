#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>

/*
bool wordBreak(string s, vector<string>& wordDict) 
{
    if(s.size() == 0) return true;
    for (int i = 0; i < wordDict.size(); i++)
    {
        int len = wordDict[i].size();
        if(wordDict[i][0] == s[0] && s.size() >= len)
        {
            if(s.substr(0, len) == wordDict[i])
            {
                string temp = s;
                temp.erase(0, len);
                if(wordBreak(temp, wordDict)) return true;
            }
        }
    }
    return false;
}

*/
bool checkInWordDict(string s, vector<string>& wordDict)
{
    if(s.size() < wordDict[0].size() || s.size() > wordDict[wordDict.size() - 1].size()) return false;
    for (int i = 0; i < wordDict.size(); i++)
    {
        if(s == wordDict[i]) return true;
    }
    return false;
}
bool operator()(string s1, string s2)
{
    return s1.size() < s2.size();
}
bool wordBreak(string s, vector<string>& wordDict) 
{
    int size = s.size();
    sort(wordDict.begin(), wordDict.end(), Solution());
    vector<bool> v(size, 0);
    vector<vector<bool>> record(size, v);

    for (int len = 1; len <= size; len++)
    {
        for (int i = 0; i < size - len + 1; i++)
        {
            if(checkInWordDict(s.substr(i, len), wordDict))
            {
                record[i][i + len - 1] = true;
            }
            else
            {
                for (int j = 0; j < len - 1; j++)
                {
                    record[i][i + len - 1] = record[i][i + j] && record[i + j + 1][i + len - 1];
                    if(record[i][i + len - 1]) break;
                }
            }
        }
    }
    return record[0][size - 1];
}

int main()
{
    string s = "catsanddog";
    vector<string> wordDict{"cats","dog","sand","and","cat"};
    cout << wordBreak(s, wordDict) << endl;
    system("pause");
    return 0;
}


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());;
        // 利用哈希值存储，有更高的查找效率

        vector <bool> dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                // 如果到j能够查找到且j后面的到i的子串在字符串数组中
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) 
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
