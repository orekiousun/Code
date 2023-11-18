#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<unordered_set>

void dfs(string s, vector<string>& ans, int x) {
    if(x == s.size() - 1) {
        ans.push_back(s);                       // 添加排列方案
        return;
    }
    unordered_set<int> st;
    for(int i = x; i < s.size(); i++) {
        if(st.find(s[i]) != st.end()) continue; // 重复，因此剪枝
        st.insert(s[i]);
        swap(s[i], s[x]);                       // 交换，将 s[i] 固定在第 x 位
        dfs(s, ans, x + 1);                     // 开启固定第 x + 1 位字符
        swap(s[i], s[x]);                       // 恢复交换
    }
}

vector<string> permutation(string s) {
    vector<string> ans;
    dfs(s, ans, 0);
    return ans;
}



int main(int argc, char const *argv[]) {
    vector<string> ans = permutation("abc");
    return 0;
}
