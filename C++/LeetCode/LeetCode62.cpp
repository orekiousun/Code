#include<iostream>
using namespace std;
#include<vector>

// 计算Cxx
int calculateC(int up, int down)
{
    long result = 1;
    up = up < down / 2 ? up : down - up;
    for (int i = 0; i < up; i++)
    {
        result = result * down / (i + 1);
        down--;
    }
    return result;
}

int uniquePaths(int m, int n)
{
    if(m < n)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    // 将m设置为默认大的值
    int res = 0;
    if(n == 1) return 1;
    for (int i = n - 1; i > 0; i--)
    {
        res += calculateC(i, m) * calculateC(i - 1, n - 2);
    }
    return res;
}

int main()
{
    cout << uniquePaths(51, 9) << endl;
    system("pause");
    return 0;
}