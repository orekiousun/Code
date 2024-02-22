#include<iostream>
using namespace std; 
#include<string>

// 从中心向两边扩散
// 最长回文子串
string longestPalindrome(string s) {
    int leftCenter = 0;
    int rightCenter = 0;
    int resultBeginIndex = 0;
    int resultLength = 1;
    int size = s.size();

    // if(size == 2)
    // {
    //     if(s[0] == s[1]) return s;
    //     else return s.substr(resultBeginIndex, resultLength);
    // }

    for(int i = 1; i < size - 1; i++)
    {
        // 预处理，找到所有和中心节点相同的字符
        int currentLength = 1;
        if((s[i - 1] != s[i] && s[i + 1] != s[i]))
        {
            leftCenter = i - 1;
            rightCenter = i + 1;
        }
        else if(s[i - 1] != s[i] && s[i + 1] == s[i])
        {
            leftCenter = i - 1;
            rightCenter = i + 2;
            currentLength++;
        }
        else if(s[i - 1] == s[i] && s[i + 1] != s[i])
        {
            leftCenter = i - 2;
            rightCenter = i + 1;
            currentLength++;
        }
        else
        {
            leftCenter = i - 1;
            rightCenter = i + 1;
            while (leftCenter >= 0 && s[leftCenter] == s[i])
            {
                leftCenter--;
                currentLength++;
            }
            while (rightCenter < size && s[rightCenter] == s[i])
            {
                rightCenter++;
                currentLength++;
            }
        }

        while(leftCenter >= 0 && rightCenter < size)
        {
            if(s[leftCenter] == s[rightCenter])
            {
                currentLength += 2;
                leftCenter--;
                rightCenter++;
            }
            else
            {
                break;
            }
        }
        if(currentLength > resultLength)
        {
            resultLength = currentLength;
            resultBeginIndex = ++leftCenter;
        }
    }

    return s.substr(resultBeginIndex, resultLength);
}


int main()
{
    string s = "bbbb";

    cout << longestPalindrome(s) << endl;

    system("pause");
    return 0;
}