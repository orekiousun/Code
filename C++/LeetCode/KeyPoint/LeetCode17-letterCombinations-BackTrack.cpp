#include<iostream>
using namespace std;
#include<vector>
#include<string>

// 普通算法
// int main()
// {
//     string digits = "237";
//     string num2 = "abc";
//     string num3 = "def";
//     string num4 = "ghi";
//     string num5 = "jkl";
//     string num6 = "mno"; 
//     string num7 = "pqrs";
//     string num8 = "tuv";
//     string num9 = "wxyz";

//     int size = digits.size();
//     int resSize = 1;
//     string nullString = "";

//     for (int i = 0; i < size; i++)
//     {
//         nullString += " ";
//         if(digits[i] != '7' && digits[i] != '9') resSize *= 3;
//         else resSize *= 4;
//     }
//     vector<string> res(resSize, nullString);
//     // if(size == 0) return res;

//     int number = resSize;
//     for(int i = 0; i < size; i++)
//     {
//         string temp;
//         switch (digits[i])
//         {
//             case '2':
//                 temp = num2;
//                 break;
//             case '3':
//                 temp = num3;
//                 break;
//             case '4':
//                 temp = num4;
//                 break;
//             case '5':
//                 temp = num5;
//                 break;
//             case '6':
//                 temp = num6;
//                 break;
//             case '7':
//                 temp = num7;
//                 break;
//             case '8':
//                 temp = num8;
//                 break;
//             case '9':
//                 temp = num9;
//                 break;
//         }
//         number /= temp.size();
//         for(int j = 0; j < resSize; j++)
//         {
//             int index = (j / number) % temp.size();
//             res[j][i] = temp[index];
//         }
//     }
//     for (int i = 0; i < resSize; i++)
//     {
//         cout << res[i] << " ";
//     }
//     cout << endl;
//     system("pause");
//     return 0;
// }

// 回溯函数
void backTrack(int level, int index, vector<string> nums, vector<string>& res, string& tempString)
{
    tempString[level] = nums[level][index];
    if(level == nums.size() - 1)
    {
        res.push_back(tempString);
        index++;
        while(index / nums[level].size() == 1)
        {
            level--;
            if(level == -1) return;
            index = nums[level].find(tempString[level]) + 1;
        } 
    }
    else
    {
        level++;
        index = 0;
    }
    backTrack(level, index, nums, res, tempString);
}

int main()
{
    string digits = "237";
    string num2 = "abc";
    string num3 = "def";
    string num4 = "ghi";
    string num5 = "jkl";
    string num6 = "mno"; 
    string num7 = "pqrs";
    string num8 = "tuv";
    string num9 = "wxyz";
    vector<string> nums;
    vector<string> res;
    string nullString = "";
    int size = digits.size();
    int resSize = 1;
    for (int i = 0; i < size; i++)
    {
        nullString += " ";
        string temp;
        switch (digits[i])
        {
            case '2':
                temp = num2;
                break;
            case '3':
                temp = num3;
                break;
            case '4':
                temp = num4;
                break;
            case '5':
                temp = num5;
                break;
            case '6':
                temp = num6;
                break;
            case '7':
                temp = num7;
                break;
            case '8':
                temp = num8;
                break;
            case '9':
                temp = num9;
                break;
        }
        nums.push_back(temp);
        resSize *= temp.size();
    }
    int level = 0;
    int index = 0;
    backTrack(level, index, nums, res, nullString);
    for (int i = 0; i < resSize; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

// 官方回溯题解  --  比较标准的回溯
class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> combinations;
        if (digits.empty()) 
        {
            return combinations;
        }
        unordered_map<char, string> phoneMap
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) 
    {
        if (index == digits.length()) 
        {
            combinations.push_back(combination);
        }
        else 
        {
            char digit = digits[index];   // 获取电话本上的数字
            const string& letters = phoneMap.at(digit);   // 获取数组对应的字符串
            for (const char& letter: letters) 
            {
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};