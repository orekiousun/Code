#include<iostream>
using namespace std;
#include<vector>


int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";

    while(s.find(part) != -1)
    {
        int pos = s.find(part);
        s = s.erase(pos, part.size());
    } 
    cout << s << endl;

    system("pause");
    return 0;
}