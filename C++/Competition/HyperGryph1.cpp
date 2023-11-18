#include<iostream>
using namespace std;
#include<vector>

/*
    小火龙打monster
*/

int methodsOfKillingMonster(vector<vector<int>>& Ifrits, vector<int>& monster) {
    long size = Ifrits.size(), ans = 0, num = 1;
    long count = 0;
    for(auto item : Ifrits) {
        if (item[0] == monster[0] || item[1] == monster[1]) {
            count++;
            num *= 3;
        }
        else {
            num *= 4;
        }
    }
    if (count == 0) return 0;

    // return 4 ^ (size - count) * (4 ^ count - 3 ^ count);

    long temp = 1;
    for (int i = 0; i < count; i++) {
        // 只有i个指向怪物时
        temp *= count - i;
        temp /= i + 1;
        num /= 3;
        ans += temp * num;
    }
    return ans % 1000000007;
}

int main(int argc, const char** argv) {
    vector<int> v1{2, 7};
    vector<int> v2{5, 2};
    vector<int> v5{7, 6};
    vector<int> monster{5, 6};
    vector<vector<int>> Ifrits{v1, v2, v5};
    cout << methodsOfKillingMonster(Ifrits, monster) << endl;
    system("pause");
    return 0;
}