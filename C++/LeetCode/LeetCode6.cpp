#include<iostream>
using namespace std;
#include<vector>

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string res = "";
    if(s.size() <= numRows || numRows == 1) res = s;

    int numColumns = (s.size() / (numRows + numRows - 2) + 1) * (numRows - 1);
    
    
    char arr[numRows][numColumns];
    int pos = 0;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            arr[i][j] = '0';
        }
        cout << endl;
    }


    for(int i = 0;  ;i = i + numRows - 1)
    {
        for(int j = 0; j < numRows; j++)
        {
            cout << s[pos] << " ";
            arr[j][i] = s[pos++];
            if(pos == s.size()) break;
        }
        int k = 1;
        if(pos == s.size()) break;
        for (int j = numRows - 2; j > 0; j--)
        {
            cout << s[pos] << " ";
            arr[j][i+k] = s[pos++];
            k++;
            if(pos == s.size()) break;
        }
        if(pos == s.size()) break;
    }
    cout << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            if(arr[i][j] != '0') res += arr[i][j];
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << res << endl;

    system("pause");
    return 0;
}