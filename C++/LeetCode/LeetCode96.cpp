#include<iostream>
using namespace std;
#include<vector>

int func(int size, int result)
{
    if(size == 1 || size == 0)
        return 1;
    if(size == 2)
        return 2;
    for(int i = 0; i < size; i++)
    {
        int left = i - 0;
        int right = size - i - 1;
        int temp = func(left, 0) * func(right, 0);
        result += temp;
    }
    return result;
}

/*
    官方题解：从G[0], G[1], G[2]......逐个计算，后面的可以调用前面计算好了的
    int numTrees(int n) 
    {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i < n + 1; i++) 
        {
            for (int j = 1; j < i + 1; j++) 
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
*/
int main()
{
    int result = func(3, 0);
    cout << result << endl;
    system("pause");
    return 0;
}