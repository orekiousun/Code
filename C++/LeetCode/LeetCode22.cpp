#include<iostream>
using namespace std;
#include<vector>
#include<string>

bool checkRepeat(vector<string> s, string& str)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if(str == s[i]) return false;
    }
    return true;
}

void merge(vector<string>& res, vector<string>& s1, vector<string>& s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        string temp = s1[i];
        for (int pos = 0; pos <= s1[i].size(); pos++)
        {
            for (size_t j = 0; j < s2.size(); j++)
            {
                s1[i].insert(pos, s2[j]);
                if(checkRepeat(res, s1[i])) 
                    res.push_back(s1[i]);
                s1[i] = temp;
            }            
        }
    }
}

void divide(vector<string>& res, int n)
{
    if(n == 1) 
    {
        res.push_back("()");
        return;
    }
    else if(n == 2)
    {
        res.push_back("()()");
        res.push_back("(())");
        return;
    }
    else if(n == 3)
    {
        res.push_back("((()))");
        res.push_back("(()())");
        res.push_back("(())()");
        res.push_back("()(())");
        res.push_back("()()()");
        return;
    }
    for(int i = 1; i <= n / 2; i++)
    {
        vector<string> s1;
        divide(s1,i);
        vector<string> s2;
        divide(s2, n - i);
        merge(res, s1, s2);
    }
}

int main()
{
    int n = 5;
    vector<string> res;
    divide(res, n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

class Solution 
{
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) 
    {
        if (cur.size() == n * 2) 
        {
            ans.push_back(cur);
            return;
        }
        if (open < n) 
        {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) 
        {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};