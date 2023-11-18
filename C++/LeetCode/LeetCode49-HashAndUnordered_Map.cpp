#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

bool isTheSameChar(string& s1, string s2)
{
    if(s1.size() == 0)
    {
        if(s2.size() == 0) return true;
        else return false;
    } 
    if(s1.size() != s2.size()) return false;
    for (int i = 0; i < s1.size(); i++)
    {
        int pos = s2.find(s1[i]);
        if(pos != -1)
        {
            s2[pos] = ' ';
        }
        else
        {
            return false;
        }
    }
    return true;
}

// int main()
// {
//     vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
//     vector<vector<string>> res;
//     vector<string>::iterator it;
//     while (!strs.empty())
//     {
//         it = strs.begin();
//         vector<string> newVector;
//         newVector.push_back(strs[0]);
//         for (int j = 1; j < strs.size(); )
//         {
//             if(isTheSameChar(strs[0], strs[j]))
//             {
//                 newVector.push_back(strs[j]);
//                 strs.erase(it+j);
//             }
//             else
//             {
//                 j++;
//             }
//         }
//         strs.erase(it);
//         res.push_back(newVector);
//     }

//     for (int i = 0; i < res.size(); i++)
//     {
//         for (int j = 0; j < res[i].size(); j++)
//         {
//             cout << res[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
//     system("pause");
//     return 0;
// }

int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    unordered_map<string, vector<string>> mp;
    for (string& str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        // 通过map[key].emplace_back(str)可以在键值后面再插入元素
        mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) 
    {
        ans.emplace_back(it->second);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;

}