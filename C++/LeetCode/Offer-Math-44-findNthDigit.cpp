#include<iostream>
using namespace std;

/*
    数字以123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
    请写一个函数，求任意第n位对应的数字。
    
    1-9 10
    10 - 99 90 * 2
    100 - 999 900 * 3
    1000 - 9999 9000 * 4

    沿着该思路做减即可
*/

int findNthDigit(int n) {
    int count = 0, temp = 10, size = 1;
    while (count < n) {
        int add = temp * 9 / 10 * size; 
        if(count + add < n)
            count += add;
        else 
            break;
        size++;
        temp *= 10;
    }
    int add = (n - count) / size;
    int remain = (n - count) % size;
    count = temp / 10 + add;
    if(remain == 0) return (count - 1)  % 10;
    else {
        size = size - remain;
        while (size--) {
            count /= 10;
        }
        return count % 10;
    }
}

int main(int argc, char const *argv[]) {
    cout << findNthDigit(19) << endl;
    return 0;
}
