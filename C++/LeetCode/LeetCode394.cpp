#include<iostream>
using namespace std;
#include<string>

/*
    给定一个经过编码的字符串，返回它解码后的字符串。
    编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
    你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
    此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
*/

// 也可以用栈来存储最终结果
string decodeString(string s) {
    string res;
    int strStartPos = -1, strEndPos = 0; 
    int leftCount = 0, rightCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == '[') {
            strStartPos = strStartPos == -1 ? i + 1 : strStartPos;
            leftCount++;
        }
        else if(s[i] == ']') {
            rightCount++;
        }
        if(leftCount == rightCount && leftCount != 0 && rightCount != 0) {
            strEndPos = i - 1;
            break;
        }
    }
    // case1:如果没有了括号，直接返回
    if(strStartPos == -1) return s;
    // case2:如果存在括号，则只对第一个检测到的最外层括号进行拓展
    int count = 0, i = strStartPos - 2, mul = 1, num = (int)'0';
    while (i >= 0 && s[i] <= '9' && s[i] >= '0') {
        count += mul * ((int)s[i] - num);
        mul *= 10;
        i--;
    }
    // 将括号前面一段加入结果中
    if(i >= 0) res += s.substr(0, i + 1);
    // 将括号内内容加入结果中
    string temp = decodeString(s.substr(strStartPos, strEndPos - strStartPos + 1));
    for (i = 0; i < count; i++){
        res += temp; 
    }
    // 将括号后面一段加入结果中
    res += decodeString(s.substr(strEndPos + 2, s.size() - strEndPos - 2));
    return res;
}

string solutions(string str) {
    string ret = "";
    stack<char> charStack;
    for (int i = 0; i < str.size(); i++) {
        if(str[i] != ']') {
            charStack.push(str[i]);
        }
        else {
            // 得到string
            string temp = "";
            while (charStack.top() != '[') {
                temp.insert(0, 1, charStack.top());
                charStack.pop();
            }
            charStack.pop(); // 弹出'['

            // 计算前面的数字
            int number = 0, mul = 1;
            while (!charStack.empty() && charStack.top() <= '9' && charStack.top() >= '0') {
                number += ((int)(charStack.top()) - (int)('0')) * mul;
                mul *= 10;
                charStack.pop();
            }

            // 重新放入栈中
            for (int j = 0; j < number; j++) {
                for (char c : temp) {
                    charStack.push(c);
                }
            }
        }
    }
    
    while (!charStack.empty()) {
        ret.insert(0, 1, charStack.top());
        charStack.pop();
    }
    
    return ret;
}

int main() {
    string s = "3[a2[c]]";
    cout << decodeString(s) << endl;
    system("pause");
    return 0;
}