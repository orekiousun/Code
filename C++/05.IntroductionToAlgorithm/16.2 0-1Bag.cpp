#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

int main()
{
    int capacity = 5;             // 背包容量
    int n = 4;                    // 物品数量
    int v[5] = {0, 1, 2, 3, 4};   // 物品体积
    int w[5] = {0, 2, 4, 4, 5};   // 物品价值
    // 注意这里需要提前在数组中放一个体积为0，价值为0的物体占位
    
    int f[capacity + 1] = {0};          // 代表体积不大于capacity的最优解
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = capacity; j >= v[i]; j--)
        {
            // 从是否选择第i物品个做出抉择
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[capacity] << endl;

    system("pause");
    return 0;
}