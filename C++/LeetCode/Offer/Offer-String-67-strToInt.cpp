#include<iostream>
using namespace std;
#include<vector>
#include<string>

/*
    写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
    首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
    当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
    该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
    注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
    在任何情况下，若函数不能进行有效的转换时，请返回 0。

    说明：
    假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 
*/

int strToInt(string str) {
    int INT_MAX = 0X7fffffff, INT_MIN = -INT_MAX - 1;
    bool sign = true;   //默认为正数
    //先舍弃开头可能存在的空格
    int i = 0;
    while(i < str.size() && str[i] == ' ') i++;
    
    //接着判断首个字符是否为正负号
    if(str[i] == '-') {
        sign = false;  //该字符串片段为负数
        i++;          //移至下一个字符接着判断
    }
    else if(str[i] == '+') i++;   //如果首个字符为‘+’则sign已经默认为true而无须更改，直接移动到下一位即可

    //下面开始对非正负符号位进行判断
    if(str[i] < '0' || str[i] > '9') return 0;  //如果第一个正负号字符后的首个字符就不是数字字符(也可能第一个字符就不是正负号)，那么直接返回0
    int res = 0;   //这里res用的int型，需要更加仔细考虑边界情况，但如果用long的话可以省去一些麻烦
    int num;       //用来单独存储单个字符转换而成的数字
    int border = INT_MAX / 10;  //用来验证计算结果是否溢出int范围的数据
    while(i < str.size()){
        if(str[i] < '0' || str[i] > '9') break;  //遇到非数字字符则返回已经计算的res结果
        if(res > border || res == border && str[i] > '7')  //注意这句话要放在字符转换前，因为需要验证的位数比实际值的位数要少一位
//这里比较巧妙的地方在于 1. 用低于int型数据长度一位的数据border判断了超过int型数据长度的值 2. 将超过最大值和低于最小值的情况都包括了
            return sign == true ? INT_MAX : INT_MIN;
        //开始对数字字符进行转换
        num = str[i] - '0';
        res = res * 10 + num;
        i++;
    }
    //最后结果根据符号添加正负号
    return sign == true ? res : -res;
}

int main(int argc, char const *argv[]) {
    cout << 0x7fffffff << endl;
    cout << strToInt("-2147483648") << endl;
    return 0;
}
