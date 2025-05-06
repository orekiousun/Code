#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

int M, N, Q;
string ok = "OK!";
string fail = "Fail!";

int opQ(vector<int>& seats) {
    int begin, end;
    cin >> begin >> end;
    int res = N;
    for(int i = begin; i < end; i++) {
        res = min(res, N - seats[i]);
    }
    return res;
}

int opQ(vector<int>& seats, int begin, int end) {
    int res = N;
    for(int i = begin; i < end; i++) {
        res = min(res, N - seats[i]);
    }
    return res;
}

string opB(vector<int>& seats, vector<vector<int>>& buyRecord) {
    int begin, end, count;
    cin >> begin >> end >> count;
    if(opQ(seats, begin, end) >= count) {
        for (int i = begin; i < end; i++) {
            seats[i] += count;
        }
        buyRecord[begin][end] += count;
        return ok;
    }
    else return fail;
}

string opR(vector<int>& seats, vector<vector<int>>& buyRecord) {
    int begin, end, count;
    cin >> begin >> end >> count;
    if(buyRecord[begin][end] >= count) {
        buyRecord[begin][end] -= count;
        for (int i = begin; i < end; i++) {
            seats[i] -= count;
        }
        return ok;
    }
    else return fail;
}

void op() {
    vector<int> seats(M, 0);
    vector<int> temp(N, 0);
    vector<vector<int>> buyRecord(M, temp);
    for(int i = 0; i < Q; i++) {
        char temp;
        cin >> temp;
        if(temp == 'Q') cout << opQ(seats) << endl;
        else if(temp == 'B') cout << opB(seats, buyRecord) << endl;
        else cout << opR(seats, buyRecord) << endl;
    }
}

int main(int argc, char const *argv[]) {
    cin >> M >> N >> Q;
    op();
    return 0;
}
