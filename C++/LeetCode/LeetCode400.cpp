#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
#include<vector>

int main()
{
    int n = 1000;
    
    long result = 9, count = 1;
    while(1)
    {
        if(n - result * count <= 0)
            break;
        n = n - result * count;
        result = result * 10;
        count++;
    }
    result = 1;
    for(int i = 0; i < count - 1; i++)
    {
        result = result * 10;
    }
    result = result + n / count;
    if(n % count == 0) cout << (result - 1) % 10 << endl;
    else
    {
        string temp = to_string(result);
        cout << (int)temp[(n % count) - 1] - 48 << endl;
    }

    system("pause");
    return 0;
}
