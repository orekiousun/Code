#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<unordered_map>

struct Node
{
public:
    char c;
    vector<int> rank;
};

class MyCompare {
public:
    bool operator()(Node* n1, Node* n2){
        int i = 0;
        while (i < n1->rank.size() && n1->rank[i] == n2->rank[i]) {
            i++;
        }
        if(i == n1->rank.size()) return n1->c < n2->c;
        else return n1->rank[i] > n2->rank[i];
    }
};

int main(int argc, char const *argv[]) {
    int n = 5;
    cin >> n;
    vector<string> strs(n);
    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<int> temp(strs[0].size(), 0);
    unordered_map<char, vector<int>> map;
    for (auto str : strs) {
        for(int i = 0; i < str.size(); i++) {
            if(map.count(str[i]) == 0)
                map[str[i]] = temp;
            map[str[i]][i]++;
        }
    }
    vector<Node*> vec;
    for(auto item : map) {
        Node* temp = new Node();
        temp->c = item.first;
        temp->rank = item.second;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), MyCompare());
    string ans(strs[0].size(), ' ');
    for (int i = 0; i < vec.size(); i++) {
        ans[i] = vec[i]->c;
    }
    cout << ans << endl;

    return 0;
}
