#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>


int main()
{
    string input = "a\n\taa\n\t\taaa\n\t\t\tfile1.txt\naaaaaaaaaaaaaaaaaaaaa\n\tsth.png";
    if(input.find('.', 0) == -1) return 0;

    int begin = 0;
    int end = input.find('\n');

    if(end == -1) return input.size();

    string result = "";
    vector<string> v;

    string first = input.substr(begin, end - begin);
    if(first.find('.', 0) == -1)
        v.push_back(first);
    else
        v.push_back("");   

    int maxSize = 0;
    int levelNow = 0;   // v[0] = dir
    while (input.find('\n', begin) != -1)
    {
        int count = 0;   // 记录\t数量
        begin = input.find('\n', begin);
        while ( input.find('\t', begin + 1) - begin == 1 )
        {
            count ++;
            begin ++;
        }
        levelNow = count;
        if(v.size() <= levelNow)
            v.push_back("");

        begin = begin + 1;
        end = input.find('\n', begin);
        string temp = input.substr(begin, end - begin);
        v[levelNow] = temp;

        if(temp.find('.', 0) != -1)
        {
            string tempResult = "";
            for(int i = 0; i <= levelNow; i ++)
            {
                tempResult += v[i];
                tempResult += "/";
                cout << tempResult << endl;
            }
            if(tempResult.size() > maxSize)
            {
                maxSize = tempResult.size();
                result = tempResult;
            }

        }
    }
    cout << result << endl;

    system("pause");
    return 0;
}