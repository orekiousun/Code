#include<iostream>
using namespace std;
#include<string>

string GetBinary(int num)
{
    string result = "";
    while (num != 0)
    {
        result += to_string(num % 2);
        num = num / 2;
    }

    return result;
}

bool IsSubStr(string str, string substr)
{
    if(str.rfind(substr) != -1) return true;
    else return false;
}

string InverseStr(string str)
{
    string temp = "";
    for(int i = str.size() - 1 ; i >= 0; i--)
    {
        temp += str[i];
    }
    return temp;
}

int main()
{
    string str = "000";
    int n = 2;
    str = InverseStr(str);
    cout << str << endl;
    string substr;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        substr = GetBinary(i + 1);
        if(IsSubStr(str, substr))
            count ++;
    }
    cout << count << endl;

    system("pause");
    return 0;
}