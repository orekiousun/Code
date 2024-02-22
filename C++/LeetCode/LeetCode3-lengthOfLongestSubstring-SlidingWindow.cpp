#include<iostream>
using namespace std;
#include<string>
#include <algorithm>

// 滑动窗口
// 1.向左查找前面的字符串中是否存在当前字符
// 2.
int lengthOfLongestSubstring(string s) {
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
        maxLength = max(maxLength, i - left + 1);
    }

    return maxLength;
}

int main()
{
    string s = "abcabcbb";

    int maxLength = lengthOfLongestSubstring(s);
    cout << maxLength << endl;

    system("pause");
    return 0;
}