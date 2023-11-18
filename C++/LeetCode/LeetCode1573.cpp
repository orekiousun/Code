#include<iostream>
using namespace std;
#include<vector>

int main()
{
    string s = "0000";
    vector<int> v;
    int res;
    
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            v.push_back(i);
        }
    }
    if(v.size() % 3 != 0) 
    {
        res = 0;
    }
    else if(v.size() == 0)
    {
        res = (s.size() - 1) * (s.size() - 2)/ 2;
    }
    else
    {
        int group = v.size() / 3;
        res = (v[group] - v[group - 1]) * (v[group * 2] - v[group * 2 - 1]);
    }
    cout << res << endl; 
    system("pause");
    return 0;
}