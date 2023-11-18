#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

string func(int x, int y, int z) {
    int size = x + y + z + 2;
    char str[size];
    int i = 2;
    if(size == 2) return "-1";
    if(y + z > 0) {
        str[0] = 'm';
        str[1] = 'h';
    }
    for (; i < z + 2; i++) {
        if(i % 3 == 0) str[i] = 'm';
        else if(i % 3 == 1) str[i] = 'h';
        else str[i] = 'y';
    }
    for (; i < z + y + 1; i++) {
        str[i] = str[i - 2];
    }
    str[i] = str[i - 1];
    for (; i < size; i++) {
        str[i] = str[i - 1];
    }
    string res = "";
    for (i = 0; i < size; i++)
    {
        res += str[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int nums[n][3];
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0];
        cin >> nums[i][1];
        cin >> nums[i][2];
    }
    for (int i = 0; i < n; i++){
        string str = func(nums[i][0], nums[i][1], nums[i][2]);
        cout << str << endl;
    }
    system("pause");
    return 0;
}