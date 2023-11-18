#include<iostream>
using namespace std;
#include<unordered_map>
#include<set>
#include<vector>

int main(int argc, char const *argv[]) {
    int m ,n;
    cin >> m >> n;
    unordered_map<long long, long long> map;
    set<long long> s;
    for (int i = 0; i < m; i++) {
        long long key, count;
        cin >> key >> count;
        long long temp = 0;
        if(count % n != 0)
            temp = (count / n) * 2 * n + count % n;
        else
            temp = (count / n) * 2 * n - n;
        map[key] += temp;
        s.insert(key);

    }
    cout << map.size() << endl;
    for (set<long long>:: iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " " << map[(*it)] << endl;
    }
    return 0;
}
