#include<iostream>
using namespace std;
#include<vector>

/*
    输入是一个无符号整数（以二进制串的形式）
    返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量)

    对于一个二进制数 n = 101010000
    n = 101010000
    n = 101001111

    n & (n - 1) = 101000000 消去一个1，一直消去直到为0
*/

int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n != 0) {
        n = (n - 1) & n;
        cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    cout << hammingWeight(72);
    return 0;
}
