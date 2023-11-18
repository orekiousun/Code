#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<algorithm>
#include<time.h>


#define SIZE 500


void merge(int (&x)[SIZE], int a, int b,int c)
{
	if(a == c)
	{
		return;
	}

	// 左半边数量
	int n1;
	n1 = b - a + 1;
	// 右半边数量
	int n2;
	n2 = c - b;

	// 存储左半边数据
	int x1[n1];
	// 存储右半边数据
	int x2[n2];

	int i = 0;
	int j, k;

	// 左数组末索引
	j = n1 - 1;

	// 右数组末索引
	k = n2 - 1;

	// 为左半边数组赋值
	for(i = 0; i < n1; i++)
	{
		x1[i] = x[i + a];
	}

	// 为右半边数组赋值
	for(i = 0; i < n2; i++)
	{
		x2[i] = x[i + b + 1];
	}



	for(i = c; i >= a; i --)
	{
		if(x1[j] >= x2[k])
		{
			x[i] = x1[j];
			x1[j] = 0;
			if(j >= 1) j--;
			
			
		}
		else
		{
			x[i] = x2[k];
			x2[k] = 0;
			if(k >= 1) k--;

		}
	}

	return;
}

void merge_sort(int (&x)[SIZE], int a, int c)  // a初索引，c末索引
{
	int b;
	b = (a + c) / 2;
	if(a == b || b == c)
	{
		merge(x, a, b, c);
		return;
	}
	else
	{
		merge_sort(x ,a ,b);
		merge_sort(x, b + 1, c);
		merge(x, a, b, c);
		return;
	}
}




int main()
{
	int i = 0;
	int x[SIZE];
	srand((unsigned)time(NULL));
	for(i = 0; i < SIZE; i++)
	{
		x[i] = rand() % 1000;   // 0-999
	}
	for(i = 0; i < SIZE; i++)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
	merge_sort(x, 0, (SIZE-1));
	for(i = 0; i < SIZE; i++)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
	return 0;
} 
