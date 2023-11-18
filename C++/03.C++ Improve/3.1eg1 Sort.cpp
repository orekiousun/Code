#include<iostream>
using namespace std;
#include<string>

// 实现通用对数组进行排序
// 采用选择排序，利用char和int数组测试
template<typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
// call of overloaded is ambiguous: 说明C++自带该函数的重载，发生了歧义

template<typename T>
// 数组名通过指针传入函数时自动退化为一个指针，不能在函数里求数组长度
// 但是通过引用传入数组可以在函数内部实现求数组长度
void sort(T* array, int num)
{
    for (int i = 0; i < num; i++)
    {
        int min = i;
        for (int  j = i; j < num; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            mySwap(array[min], array[i]);
            
        }
    }
}

int main()
{
    int array1[10] = {1, 3, 9, 2, 7, 5, 8, 0, 4, 6};
    char array2[] = "beaifcdgh";
    sort(array1, sizeof(array1) / sizeof(array1[0]));   // 数组名即可代表数组首地址
    for (int i = 0; i < sizeof(array1) / sizeof(array1[0]) ; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
    sort(array2, sizeof(array2) / sizeof(array2[0]) - 1);   
    // 字符串数组末尾有一个占位符为\0，所以进行字符串排序时长度减去1
    cout << array2 << endl;
    system("pause");
    return 0;
}