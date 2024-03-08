#include<iostream>
using namespace std;

/*
    利用%20替代字符串中的空格
    首先计算空格个数，重新初始化一个字符串，预先设定好长度，再设定新字符串的值
*/

string replaceSpace(string s) {
    int size = s.size();
    int cnt = 0;
    int pos = 0;
    // 计算空格个数
    while (1) {
        pos = s.find(' ', pos);
        if(pos != -1) {
            cnt++;
            pos++;
        }
        else break;
    }
    // for(char c : s) {
    //     if(c == ' ') cnt++;
    // }
    string ans;
    ans.resize(size + cnt * 2);
    int i = 0, j = 0;
    // 设定字符串的值
    while (j < size) {
        if(s[j] == ' ') {
            ans[i++] = '%';
            ans[i++] = '2';
            ans[i++] = '0';
            j++;
        }
        else {
            ans[i++] = s[j++];
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    string s = "We are happy.";
    cout << replaceSpace(s) << endl;
    return 0;
}
