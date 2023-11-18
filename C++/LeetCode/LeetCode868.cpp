#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    int n = 22;
    vector<int> v;
    int i = 0;
    while( n / 2 != 0)
    {
        int number = n % 2;
        if(number == 1) v.push_back(i); 
        n = n / 2;
        i++;
    }
    v.push_back(i);
    int result = 0;
    for (vector<int>::iterator it = v.begin(); it != --v.end(); it++)
    {
        int temp = *(it + 1) - *it;
        cout << temp<< " ";
        if(temp >= result) result = temp;
    }
    cout << result << endl;
    system("pause");
    return 0;
}