//
// Created by ousun on 2024/8/18.\
// https://leetcode.cn/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150
// 思路：硬编码数字
//

#include <iostream>
using namespace  std;
#include <string>

const string thousands[] = {"", "M", "MM", "MMM"};
const string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

string inToRoman(int num) {
    return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
}

int main() {
    int num = 1996;
    cout << inToRoman(num) << endl;
    return 0;
}