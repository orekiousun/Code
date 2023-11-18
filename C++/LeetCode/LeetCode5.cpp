#include<iostream>
using namespace std; 
#include<string>

// 从中心向两边扩散

int main()
{
    string s = "bbbb";
    int leftCenter = 0;
    int rightCenter = 0;
    int resultbegindex = 0;
    int resultLength = 1;
    int size = s.size();

    // if(size == 2)
    // {
    //     if(s[0] == s[1]) return s;
    //     else return s.substr(resultbegindex, resultLength);
    // }

    for(int i = 1; i < size - 1; i++)
    {
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
            resultbegindex = ++leftCenter;
        }
    }

    cout << s.substr(resultbegindex, resultLength) << endl;

    system("pause");
    return 0;
}