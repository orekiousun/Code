#include<iostream>
using namespace std;
#include<stack>
#include<string>

bool isValid(string s) {
    if(s.size() == 0) return true;
    string type1 = "()", type2 = "{}", type3 = "[]";
    int count1 = 0, count2 = 0, count3 = 0;
    stack<char> stringStack;
    for(char c : s) {
        if(c == type1[0] || c == type2[0] || c == type3[0]) {
            stringStack.push(c);
        }
        else if(c == type1[1]) {
            while (!stringStack.empty() && stringStack.top() != type1[0]) {
                char temp = stringStack.top();
                if(temp == type1[0]) count1++;
                else if(temp == type2[0]) count2++;
                else if(temp == type3[0]) count3++;
                else if(temp == type1[1]) count1--;
                else if(temp == type2[1]) count2--;
                else if(temp == type3[1]) count3--;
                stringStack.pop();
            }
            if(stringStack.empty() || count1 != 0 || count2 != 0 || count3 != 0)
                return false;
            stringStack.pop();
        }
        else if(c == type2[1]) {
            while (!stringStack.empty() && stringStack.top() != type2[0]) {
                char temp = stringStack.top();
                if(temp == type1[0]) count1++;
                else if(temp == type2[0]) count2++;
                else if(temp == type3[0]) count3++;
                else if(temp == type1[1]) count1--;
                else if(temp == type2[1]) count2--;
                else if(temp == type3[1]) count3--;
                stringStack.pop();
            }
            if(stringStack.empty() || count1 != 0 || count2 != 0 || count3 != 0)
                return false;
            stringStack.pop();
        }
        else if(c == type3[1]) {
            while (!stringStack.empty() && stringStack.top() != type3[0]) {
                char temp = stringStack.top();
                if(temp == type1[0]) count1++;
                else if(temp == type2[0]) count2++;
                else if(temp == type3[0]) count3++;
                else if(temp == type1[1]) count1--;
                else if(temp == type2[1]) count2--;
                else if(temp == type3[1]) count3--;
                stringStack.pop();
            }
            if(stringStack.empty() || count1 != 0 || count2 != 0 || count3 != 0)
                return false;
            stringStack.pop();
        }
        count1 = 0, count2 = 0, count3 = 0;
    }
    if(stringStack.empty()) 
        return true;
    else
        return false;
}

int main() {
    string s = "()[())]{}";
    cout << isValid(s) << endl;
    system("pause");
    return 0;
}