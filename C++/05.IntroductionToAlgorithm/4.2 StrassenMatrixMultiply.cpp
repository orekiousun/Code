#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<math.h>
#define number 16

void matrixAdd(vector<int> matrixA, vector<int> matrixB, vector<int>& s, int aStart, int bStart, int newSize)
{
    int size = (int)sqrt((double)matrixA.size());
    for (int i = 0; i < newSize * newSize; i++)
    {
        s[i] = matrixA[aStart++] + matrixB[bStart++];
        if(aStart % newSize == 0) aStart = aStart - newSize + size;
        if(bStart % newSize == 0) bStart = bStart - newSize + size;
    }
}

void matrixMinus(vector<int> matrixA, vector<int> matrixB, vector<int>& s, int aStart, int bStart, int newSize)
{
    int size = (int)sqrt((double)matrixA.size());
    for (int i = 0; i < newSize * newSize; i++)
    {
        s[i] = matrixA[aStart++] - matrixB[bStart++];
        if(aStart % newSize == 0) aStart = aStart - newSize + size;
        if(bStart % newSize == 0) bStart = bStart - newSize + size;
    }
}

void matrixMultiply(vector<int> matrixA, vector<int> matrixB, vector<int>& matrixC, int aStart, int bStart, int size)
{
    if(size == 1)
    {
        matrixC[0] = matrixA[aStart] * matrixB[bStart];
        return;
    } 
    int newSize = size / 2;
    vector<int> s1(newSize * newSize, 0);
    vector<int> s2(newSize * newSize, 0);
    vector<int> s3(newSize * newSize, 0);
    vector<int> s4(newSize * newSize, 0);
    vector<int> s5(newSize * newSize, 0);
    vector<int> s6(newSize * newSize, 0);
    vector<int> s7(newSize * newSize, 0);
    vector<int> s8(newSize * newSize, 0);
    vector<int> s9(newSize * newSize, 0);
    vector<int> s10(newSize * newSize, 0);

    vector<int> p1(newSize * newSize, 0);
    vector<int> p2(newSize * newSize, 0);
    vector<int> p3(newSize * newSize, 0);
    vector<int> p4(newSize * newSize, 0);
    vector<int> p5(newSize * newSize, 0);
    vector<int> p6(newSize * newSize, 0);
    vector<int> p7(newSize * newSize, 0);
    
    int aIndex1, aIndex2, aIndex3, aIndex4;
    int bIndex1, bIndex2, bIndex3, bIndex4;
    int cIndex1, cIndex2, cIndex3, cIndex4;

    aIndex1 = aStart;
    aIndex2 = aIndex1 + newSize;
    aIndex3 = aIndex1 + newSize * (int)sqrt((double)matrixA.size());
    aIndex4 = aIndex3 + newSize;

    bIndex1 = bStart;
    bIndex2 = bIndex1 + newSize;
    bIndex3 = bIndex1 + newSize * (int)sqrt((double)matrixB.size());
    bIndex4 = bIndex3 + newSize;

    cIndex1 = 0;
    cIndex2 = cIndex1 + newSize;
    cIndex3 = cIndex1 + newSize * (int)sqrt((double)matrixC.size());
    cIndex4 = cIndex3 + newSize;

    matrixMinus(matrixB, matrixB, s1, bIndex2, bIndex4, newSize);   // s1 = b12 - b22
    matrixAdd(matrixA, matrixA, s2, aIndex1, aIndex2, newSize);     // s2 = a11 + a12
    matrixAdd(matrixA, matrixA, s3, aIndex3, aIndex4, newSize);     // s3 = a21 + a22
    matrixMinus(matrixB, matrixB, s4, bIndex3, bIndex1, newSize);   // s4 = b21 - b11
    matrixAdd(matrixA, matrixA, s5, aIndex1, aIndex4, newSize);     // s5 = a11 + a22
    matrixAdd(matrixB, matrixB, s6, bIndex1, bIndex4, newSize);     // s6 = b11 + b22
    matrixMinus(matrixA, matrixA, s7, aIndex2, aIndex4, newSize);   // s7 = a12 - a22
    matrixAdd(matrixB, matrixB, s8, bIndex3, bIndex4, newSize);     // s8 = b21 + b22
    matrixMinus(matrixA, matrixA, s9, aIndex1, aIndex3, newSize);   // s9 = a11 - a21
    matrixAdd(matrixB, matrixB, s10, bIndex1, bIndex2, newSize);    // s10 = b11 + b12

    matrixMultiply(matrixA, s1, p1, aIndex1, 0, newSize);   // p1 = a11 * s1
    matrixMultiply(s2, matrixB, p2, 0, bIndex4, newSize);   // p2 = s2 * b22
    matrixMultiply(s3, matrixB, p3, 0, bIndex1, newSize);   // p3 = s3 * b11
    matrixMultiply(matrixA, s4, p4, aIndex4, 0, newSize);   // p4 = a22 * s4
    matrixMultiply(s5, s6, p5, 0, 0, newSize);              // p5 = s5 * s6
    matrixMultiply(s7, s8, p6, 0, 0, newSize);              // p6 = s7 * s8
    matrixMultiply(s9, s10, p7, 0, 0, newSize);             // p7 = s9 * s10
    
    int sizeC = (int)sqrt((double)matrixC.size());
    for (int i = 0; i < newSize * newSize; i++)
    {
        matrixC[cIndex1++] = p5[i] + p4[i] - p2[i] + p6[i];
        matrixC[cIndex2++] = p1[i] + p2[i];
        matrixC[cIndex3++] = p3[i] + p4[i];
        matrixC[cIndex4++] = p5[i] + p1[i] - p3[i] - p7[i];
        if(cIndex1 % newSize == 0) cIndex1 = cIndex1 - newSize + sizeC;
        if(cIndex2 % newSize == 0) cIndex2 = cIndex2 - newSize + sizeC;
        if(cIndex3 % newSize == 0) cIndex3 = cIndex3 - newSize + sizeC;
        if(cIndex4 % newSize == 0) cIndex4 = cIndex4 - newSize + sizeC;
    }
}

int main()
{
    srand((unsigned int)time(NULL));   // 随机数种子
    vector<int> matrixA(number * number, 0);
    vector<int> matrixB(number * number, 0);
    vector<int> matrixC(number * number, 0);
    vector<int> matrixD(number * number, 0);
    for (int i = 0; i < number * number; i++)
    {
        matrixA[i] = rand() % 2;
        matrixB[i] = rand() % 2;
    }
    cout << "matrix A is: " << endl;
    for (int i = 0; i < number * number; i++)
    {
        cout << matrixA[i] << " ";
        if(i % number == number - 1) cout << endl;
    }
    cout << "matrix B is: " << endl;
    for (int i = 0; i < number * number; i++)
    {
        cout << matrixB[i] << " ";
        if(i % number == number - 1) cout << endl;
    }

    // 直接计算结果
    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number; j++)
        {
            matrixD[i * number + j] = 0;
            for(int k = 0; k < number; k++)
            {
                matrixD[i * number + j] += matrixA[i * number + k ] * matrixB[k * number + j];
            }
        }
    }

    matrixMultiply(matrixA, matrixB, matrixC, 0, 0, number);
    cout << "matrix C is: " << endl;
    for (int i = 0; i < number * number; i++)
    {
        cout << matrixC[i] << " ";
        if(i % number == number - 1) cout << endl;
    }

    cout << "matrix D is: " << endl;
    for (int i = 0; i < number * number; i++)
    {
        cout << matrixD[i] << " ";
        if(i % number == number - 1) cout << endl;
    }
    
    system("pause");
    return 0;
}