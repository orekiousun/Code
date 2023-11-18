#include<iostream>
using namespace std;
#include<vector>

/*
    题目一：一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
    方法：
        两个相同的数字异或结果为0，题目中有两个数字没有出现两次，假设为x，y，则最终将数组中所有数字异或结果就为 x^y
        为了找到x和y，将计算结果分别对 1, 2, 4, 8... 进行按位与，如果与出来结果为1，说明x和y在该位上的数字一个为1，一个为0
        则可将此位作为一个筛选器，如果数字遇上该位为1就分为一类，为0分为另一类，一次筛选出x和y

    题目二：在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
    方法：
        将每一个数字中每一位出现的次数加起来得到一个数组，最后的数组中哪些位不是3的倍数就是结果
*/

vector<int> singleNumbers(vector<int>& nums) {
    int x = 0, y = 0, n = 0, m = 1;
    for(int num : nums)         // 1. 遍历异或
        n ^= num;
    while((n & m) == 0)         // 2. 循环左移，计算 m，找出 x 和 y 的二进制中第一个不一样位，利用该位对数组进行分组
        m <<= 1;
    for(int num : nums) {       // 3. 遍历 nums 分组
        if(num & m) x ^= num;   // 4. 当 num & m != 0
        else y ^= num;          // 4. 当 num & m == 0
    }
    return vector<int> {x, y};  // 5. 返回出现一次的数字
}

int singleNumber3(vector<int>& nums) {
    vector<int> count(32, 0);
    for(int num : nums){
        for(int j = 0; j < 32; j++){
            count[j] += num & 1;
            num >>= 1;
        }
    }
    int res = 0, m = 3;
    for(int i = 0; i < 32; i++){
        res <<= 1;
        res |= count[31 - i] % m == 0 ? 0 : 1;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
