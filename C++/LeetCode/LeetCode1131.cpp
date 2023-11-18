#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);

    vector<int> arr2;
    arr2.push_back(-1);
    arr2.push_back(4);
    arr2.push_back(5);
    arr2.push_back(6);

    int size = arr1.size();

    // (arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j)
    // (-arr1[i] + arr2[i] + i) - (-arr1[j] + arr2[j] + j)
    // (arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)
    // (arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)


    int temp1 = arr1[0] + arr2[0] + 0;
    int temp2 = temp1;
    for (int i = 1; i < size; i++)
    {
        if(arr1[i] + arr2[i] + i > temp1) temp1 = arr1[i] + arr2[i] + i;
        if(arr1[i] + arr2[i] + i < temp2) temp2 = arr1[i] + arr2[i] + i;
    }
    int res1 = temp1 - temp2;

    temp1 = -arr1[0] + arr2[0] + 0;
    temp2 = temp1;
    for (int i = 1; i < size; i++)
    {
        if(-arr1[i] + arr2[i] + i > temp1) temp1 = -arr1[i] + arr2[i] + i;
        if(-arr1[i] + arr2[i] + i < temp2) temp2 = -arr1[i] + arr2[i] + i;
    }
    int res2 = temp1 - temp2;

    temp1 = arr1[0] - arr2[0] + 0;
    temp2 = temp1;
    for (int i = 1; i < size; i++)
    {
        if(arr1[i] - arr2[i] + i > temp1) temp1 = arr1[i] - arr2[i] + i;
        if(arr1[i] - arr2[i] + i < temp2) temp2 = arr1[i] - arr2[i] + i;
    }
    int res3 = temp1 - temp2;

    temp1 = arr1[0] + arr2[0] - 0;
    temp2 = temp1;
    for (int i = 1; i < size; i++)
    {
        if(arr1[i] + arr2[i] - i > temp1) temp1 = arr1[i] + arr2[i] - i;
        if(arr1[i] + arr2[i] - i < temp2) temp2 = arr1[i] + arr2[i] - i;
    }
    int res4 = temp1 - temp2;

    cout << max(max(res1, res2), max(res3, res4)) << endl;

    system("pause");
    return 0;
}