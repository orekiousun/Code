#include<iostream>
using namespace std;
#include<string>

// 滑动窗口

int main()
{
    string s = "abcabcbb";
    int size = s.size();
    if(size == 0) return 0;
    if(size == 1) return 1;


    int left = 0;
    int maxLength = 1;
    for (int i = 0; i < size; i++)
    {
        int temp = s.find(s[i], left);
        if(temp != i)
        {
            left = ++temp;
        } 
        if(i - left + 1 > maxLength) maxLength = i - left + 1;
    }

    cout << maxLength << endl;
    


    system("pause");
    return 0;
}