// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<string>
using namespace std;

/*
    数组
    1.概念：一个集合，存放了相同类型的数据元素
        每个数据元素都是相同的数据类型
        数组是由连续的内存空间组成的
    2.一维数组的三种定义方法
        数据类型 数组名[数组长度];
        数据类型 数组名[数组长度] = {值1, 值2, 值3, ...};   // 定义数组的同时赋予了一个初值，如果在初始化数据时没有全部填满，会用0来填补数据
        数据类型 数组名[] = {值1, 值2, 值3, ...};   // 先把值写进去后会自动计算
        注意，直接使用 数组名[]; 的方式是无法定义数组的，因为不知道数组的长度，定义数组时，必须有一个初始的长度
        字符串数组末尾会有一个标志结尾符\0
        初始化数组：
            数据类型 数组名[数组长度] = {0};
    3.一维数组数组名的用途
        可以统计整个数组在内存中的长度
        可以获取数组在内存中的首地址
        也可以通过&arr[i]的方式获取第i个元素的地址
        注意：数组名是一个常量，不可以进行赋值操作
    4.二维数组的四种定义方法
        数据类型 数组名[行数][列数];
        数据类型 数组名[行数][列数] = {{数据1, 数据2, ...}, 
                                        {数据1, 数据2, ...}, 
                                        ...};   // 更直观
        数据类型 数组名[行数][列数] = {数据1, 数据2, 数据3, 数据4, ...};
        数据类型 数组名[][列数] = {数据1, 数据2, 数据3, 数据4, ...};  // 可以根据列数推算行数，但是不能规定行数让其推算列数
    5.二维数组数组名的用途
        查看二维数组所占内存空间
        获取二维数组首地址
*/

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "sizeof arr: " << sizeof(arr) << endl;
    cout << "sizeof arr[0]: " << sizeof(arr[0]) << endl;
    cout << "the element amout of array: " << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "the position of first element: " << &arr[0] << endl;
    cout << "the position of first element: " << arr << endl;
    
    int arr2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    for(int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "sizeof arr2: " << sizeof(arr2) << endl;
    cout << "sizeof arr2[0]: " << sizeof(arr2[0]) << endl;   // arr2[0]表示第一行
    cout << "sizeof arr2[0][0]: " << sizeof(arr2[0][0]) << endl;  
    cout << "the element amout of array: " << sizeof(arr2) / sizeof(arr2[0][0]) << endl;
    cout << "the row of the array: " << sizeof(arr2) / sizeof(arr2[0]) << endl << "the column of the array: " << sizeof(arr2[0]) / sizeof(arr2[0][0]) << endl;
    cout << "the position of first element: " << arr2 << endl;
    cout << "the position of first element: " << arr2[0] << endl;
    cout << "the position of fourth element: " << arr2[1] << endl;
    cout << "the position of first element: " << &arr2[0][0] << endl;
    
    int arr3[2][3] = {1, 2, 3, 4, 5, 6};
    for(int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}