#include<iostream>
using namespace std;
#include<vector>

void printVector(const vector<int> v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it ++)    
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int a = 2, b = 6, c = 5;
    int result = 1;
    int count = 1;
    while(a > result || b > result || c > result)
    {
        result *= 2;
        count ++;
    } 

    result = 0;
    int tempA;
    int tempB;
    int tempC;

    for(int i = 0; i < count; i++)
    {
        tempA = a % 2; 
        tempB = b % 2; 
        tempC = c % 2; 

        if(tempC == 1)
        {
            if(tempA == 1 || tempB == 1)
                result += 0;
            else
                result += 1;
        }
        else
        {
            if(tempA == 0 && tempB == 0)
                result += 0;
            else
                result += tempA + tempB;
        }

        a /= 2;
        b /= 2;
        c /= 2;
    }



    cout << result << endl;
    

    system("pause");
    return 0;
}