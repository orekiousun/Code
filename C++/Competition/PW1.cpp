#include<iostream>
using namespace std;
#include<string>
#include<stack>

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
        if(charStack.top() >= '0' && charStack.top() <= '9') {
            charStack.pop();
        }
        else {
            ret.insert(0, 1, charStack.top());
            charStack.pop();
        }
    }
    
    return ret;
}

int main() {
    string str = "3";
    cout << solutions(str) << endl;
    system("pause");
    return 0;
}