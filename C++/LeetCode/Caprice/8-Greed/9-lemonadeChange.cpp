//
// Created by ousun on 2025/5/1.
// 柠檬水找零：https://www.programmercarl.com/0860.%E6%9F%A0%E6%AA%AC%E6%B0%B4%E6%89%BE%E9%9B%B6.html
// 柠檬水找零：https://leetcode.cn/problems/lemonade-change/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool lemonadeChange(vector<int>& bills) {
    array<int, 3> arr;
    arr.fill(0);
    for (int i = 0; i < bills.size(); ++i) {
        if (bills[i] == 5) {
            arr[0] += 1;
        }
        else if (bills[i] == 10) {
            // 找一张5元的
            if (arr[0] <= 0) return false;
            arr[0] -= 1, arr[1] += 1;
        }
        else {
            // 优先退10元的
            if (arr[1] >= 1 && arr[0] >= 1) arr[1] -= 1, arr[0] -= 1;
            else if(arr[0] >= 3) arr[0] -= 3;
            else return false;
            arr[2] += 1;
        }
    }
    return true;
}

int main() {
    vector<int> bills{5,5,5,10,20};
    lemonadeChange(bills);
    return 0;
}
