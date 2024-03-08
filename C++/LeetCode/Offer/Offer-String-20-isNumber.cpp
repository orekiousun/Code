#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<unordered_map>

/*
    判断一个字符串是否表示一个数值
    数值规则：
        整数：+/- 至少一位数字，如 +100
        小数：
            至少一位数字，后面跟着一个点 '.'，如 1.
            至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字，如12.1
            一个点 '.' ，后面跟着至少一位数字，如.12
    科学计数法：一个'e'或'E'后面接一个整数，可以为负数
*/

#pragma region 将数字看作一种格式
// 起始的空格 符号位 整数部分 左侧有整数的小数点||左侧无整数的小数点（根据前面的第二条额外规则，需要对左侧有无整数的两种小数点做区分） 小数部分 字符 指数部分的符号位 指数部分的整数部分 末尾的空格

bool scanUnsignedInteger(const string s, int& index){

    int befor = index;
    while(index != s.size() && s[index] >= '0' && s[index] <= '9')
        index ++;

    return index > befor;
}

// 整数的格式可以用[+|-]B表示, 其中B为无符号整数
bool scanInteger(const string s, int& index){

    if(s[index] == '+' || s[index] == '-')
        index++;

    return scanUnsignedInteger(s, index);
}

bool isNumber(string s) {

    if(s.size() == 0)
        return false;
    int index = 0;

    //字符串开始有空格，可以返回true
    while(s[index] == ' ')
        index++;

    //找到整数
    bool numeric = scanInteger(s, index);

    // 如果出现'.'，接下来是数字的小数部分
    if(s[index] == '.'){

        index++;

        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666
        numeric = scanUnsignedInteger(s, index) || numeric;
    }

    // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
    if(s[index] == 'e' || s[index] == 'E'){

        ++index;

        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        numeric = numeric && scanInteger(s ,index);
    }

    //字符串结尾有空格，可以返回true
    while(s[index] == ' ')
        ++index;

    return numeric && index == s.size();
}
#pragma endregion

#pragma region 看作状态机，进行状态转移，当作数电来做
class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else if (ch == ' ') {
            return CHAR_SPACE;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {
                STATE_INITIAL, {
                    {CHAR_SPACE, STATE_INITIAL},
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            }, {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }, {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_END, {
                    {CHAR_SPACE, STATE_END}
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};
#pragma endregion


int main(int argc, char const *argv[]) {
    string s = ".12e+24";
    cout << isNumber(s) << endl;
    return 0;
}
