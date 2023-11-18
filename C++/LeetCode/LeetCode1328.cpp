#include<iostream>
using namespace std;
#include<string>

void inverse(string &str)
{
    string temp = "";
    for(int i = str.size() - 1; i >= 0; i--)
    {
        temp += str[i];
    }
    str = temp;
}

int main()
{
    string palindrome = "aaaa";
    // if(palindrome.size() == 1) return "";
    
    int count = 0;
    int remain = palindrome.size() % 2;

    for (int i = 0; i < palindrome.size(); i++)
    {
        if(remain == 1 && i == palindrome.size() / 2) count ++;
        else if(palindrome[i] != 'a')
        {
            palindrome[i] = 'a';
            break;
        }
        else
        {
            count++;
        }
    }

    if(count == palindrome.size()) palindrome[palindrome.size() - 1] = 'b';


    // if(!flag || palindrome.size() == 1) return "";
    // else return palindrome;


    cout << palindrome << endl;
    inverse(palindrome);
    cout << palindrome << endl;
    system("pause");
    return 0;
}