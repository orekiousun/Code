#include<iostream>
using namespace std;
#include<vector>

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    // 每经过a岁，获得x元
    int x = a - 1 + b, age = 0;

    // 如果到不了a岁
    if(c < x) {
        if(c < a) {
            cout << c << endl;
            return 0;
        }
        else {
            cout << a << endl;
            return 0;
        }
    }

    int num = x;
    age = a;
    while (num + x <= c) {
        num += x;
        age += a;
    }

    if(c - num > a)
        age += a;
    else
        age += c - num;


    cout << age << endl;

    system("pause");
    return 0;
}