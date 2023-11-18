#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

void myPrint(string v)
{
    cout << v << " ";
}
int main()
{
    vector<int> nums;
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(7);
    
    vector<string> result;
    if(nums.size() == 0) return result;
    vector<int>::iterator it = nums.begin();
    int flag = 0;
    for(; it != --nums.end() && it != nums.end();)
    {
        if(*it + 1 != *(it + 1))
        {
            result.push_back(to_string(*it)); 
            it ++;
        } 
        else
        {
            int front = *it;
            while (it != --nums.end() && *it + 1 == *(it + 1))
            {
                it ++;
                if (it == --nums.end())
                    flag = 1;
            }
            result.push_back(to_string(front) + "->" + to_string(*it));
            it ++;
        }
    }
    if(!flag) result.push_back(to_string(* --nums.end())); 
    for_each(result.begin(), result.end(), myPrint);
    cout << endl;
    system("pause");
    return 0;
}