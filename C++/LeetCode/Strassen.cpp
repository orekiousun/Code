#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>

#define size 8

void Merge_Matrix(int *a,int *b,int *c,int *d,int* c0,int rows)
{
	int i=0;
	int j=0;
	for(i=0;i<(rows*rows);i++)
	{
		if((i%rows==0)&&i!=0)
		{
			j=(rows*2)*(i/rows);
			c0[j]=a[i];
			j++;
		}
		else
		{
			c0[j]=a[i];
			j++;
		}
	}
	j=rows;
	for(i=0;i<(rows*rows);i++)
	{
		if((i%rows==0)&&i!=0)
		{
			j=(rows*2)*(i/rows)+rows;
			c0[j]=b[i];
			j++;
		}
		else
		{
			c0[j]=b[i];
			j++;
		}
	}
	j=rows*2*rows;
	for(i=0;i<(rows*rows);i++)
	{
		if((i%rows==0)&&i!=0)
		{
			j=rows*2*rows+(rows*2)*(i/rows);
			c0[j]=c[i];
			j++;
		}
		else
		{
			c0[j]=c[i];
			j++;
		}
	}
	j=rows*2*rows+rows;
	for(i=0;i<(rows*rows);i++)
	{
		if((i%rows==0)&&i!=0)
		{
			j=rows*2*rows+rows+(rows*2)*(i/rows);
			c0[j]=d[i];
			j++;
		}
		else
		{
			c0[j]=d[i];
			j++;
		}
	}
}


void Matrix_ADD(int* x,int* y,int* c0,int loca,int locb,int rows)
{
	int i=0;
	int j=loca;
	int k=locb;
	for(i=0;i<(rows*rows);i++)
	{
		if(i%rows==0&&i!=0)
		{
			j=loca+rows*2*(i/rows);
			k=locb+rows*2*(i/rows);
			c0[i]=x[j]+y[k];
			j++;
			k++;
		}
		else
		{
			c0[i]=x[j]+y[k];
			j++;
			k++;
		}
	}
}


void Matrix_SUB(int* x,int* y,int* c0,int loca,int locb,int rows)
{
	int i=0;
	int j=loca;
	int k=locb;
	for(i=0;i<(rows*rows);i++)
	{
		if(i%rows==0&&i!=0)
		{
			j=loca+rows*2*(i/rows);
			k=locb+rows*2*(i/rows);
			c0[i]=x[j]-y[k];
			j++;
			k++;
		}
		else
		{
			c0[i]=x[j]-y[k];
			j++;
			k++;
		}
	}
}


void Matrix_Multiply(int* x,int* y,int* c0,int loca,int locb,int rows)
{
	int loca11, loca12, loca21, loca22;
	int locb11, locb12, locb21, locb22;
	int newrows = rows / 2;

	int c11[newrows * newrows];
	int c12[newrows * newrows];
	int c21[newrows * newrows];
	int c22[newrows * newrows];

	int s1[newrows * newrows];
	int s2[newrows * newrows];
	int s3[newrows * newrows];
	int s4[newrows * newrows];
	int s5[newrows * newrows];
	int s6[newrows * newrows];
	int s7[newrows * newrows];
	int s8[newrows * newrows];
	int s9[newrows * newrows];
	int s10[newrows * newrows];

	int p1[newrows * newrows];
	int p2[newrows * newrows];
	int p3[newrows * newrows];
	int p4[newrows * newrows];
	int p5[newrows * newrows];
	int p6[newrows * newrows];
	int p7[newrows * newrows];

	int temp1[newrows * newrows];
	int temp2[newrows * newrows];
	

	if(rows == 1)
	{
		c0[0] = x[(loca)] * y[(locb)];
	}
	else
	{

		loca11 = loca;
		loca12 = loca + (rows / 2);
		loca21 = loca + (size * (rows / 2));
		loca22 = loca + (size * (rows / 2)) + (rows / 2);

		locb11 = locb;
		locb12 = locb + (rows / 2);
		locb21 = locb + (size * (rows / 2));
		locb22 = locb + (size * (rows / 2)) + (rows / 2);

		// 为S赋值
		Matrix_SUB(y,y,s1,locb12,locb22,newrows);   // S1 = B12 - B22
		Matrix_ADD(x,x,s2,loca11,loca12,newrows);   // S2 = A11 + A12
		Matrix_ADD(x,x,s3,loca21,loca22,newrows);   // S3 = A21 + A22
		Matrix_SUB(y,y,s4,locb21,locb11,newrows);   // S4 = B21 - B11
		Matrix_ADD(x,x,s5,loca11,loca22,newrows);   // S5 = A11 + A22
		Matrix_ADD(y,y,s6,locb11,locb22,newrows);   // S6 = B11 + B22
		Matrix_SUB(x,x,s7,loca12,loca22,newrows);   // S7 = A12 - A22
		Matrix_ADD(y,y,s8,locb21,locb22,newrows);   // S8 = B21 + B22
		Matrix_SUB(x,x,s9,loca11,loca21,newrows);   // S9 = A11 - A21
		Matrix_ADD(y,y,s10,locb11,locb12,newrows);  // S10 = B11 + B12
		
		// 为P赋值
		Matrix_Multiply(x,s1,p1,loca11,0,newrows);   // P1 = A11 * S1
		Matrix_Multiply(s2,y,p2,0,locb22,newrows);   // P2 = S2 * B22
		Matrix_Multiply(s3,y,p3,0,locb11,newrows);   // P3 = S3 * B11
		Matrix_Multiply(x,s4,p4,loca22,0,newrows);   // P4 = A22 * S4
		Matrix_Multiply(s5,s6,p5,0,0,newrows);       // P5 = S5 * S6
		Matrix_Multiply(s7,s8,p6,0,0,newrows);       // P6 = S7 * S6
		Matrix_Multiply(s9,s10,p7,0,0,newrows);      // P7 = S9 * S10
		
		// C11 = P5 + P4 - P2 + P6
		Matrix_ADD(p5,p6,temp1,0,0,newrows);
		Matrix_SUB(p4,p2,temp2,0,0,newrows);
		Matrix_ADD(temp1,temp2,c11,0,0,newrows);
		
		// C12 = P1 + P2
		Matrix_ADD(p1,p2,c12,0,0,newrows);
		
		// C21 = P3 + P4
		Matrix_ADD(p4,p3,c21,0,0,newrows);

		// C22 = P5 - P3 + P1 - P7
		Matrix_SUB(p5,p3,temp1,0,0,newrows);
		Matrix_SUB(p1,p7,temp2,0,0,newrows);
		Matrix_ADD(temp1,temp2,c22,0,0,newrows);
		
		Merge_Matrix(c11,c12,c21,c22,c0,newrows);
	}
}


int main()
{
	int i=0;
	int* a=NULL;
	int* b=NULL;
	int* c=NULL;
	a=(int *)malloc(size*size*sizeof(int));
	b=(int *)malloc(size*size*sizeof(int));
	c=(int *)malloc(size*size*sizeof(int));
	srand((unsigned)time(NULL));
	for(i=0;i<(size*size);i++)
	{
		a[i]=rand()%10;
		b[i]=rand()%10;
	}
	printf("A matrix is:\n\n");
	for(i=0;i<(size*size);i++)
	{
		if(((i+1)%size)==0)
		{
			printf("%5d\n",a[i]);
		}
		else
		{
			printf("%5d",a[i]);
		}
	}
	printf("B matrix is:\n\n");
	for(i=0;i<(size*size);i++)
	{
		if(((i+1)%size)==0)
		{
			printf("%5d\n",b[i]);
		}
		else
		{
			printf("%5d",b[i]);
		}
	}
	Matrix_Multiply(a,b,c,0,0,size);
	printf("C matrix is:\n\n");
	for(i=0;i<(size*size);i++)
	{
		if(((i+1)%size)==0)
		{
			printf("%5d\n",c[i]);
		}
		else
		{
			printf("%5d",c[i]);
		}
	}
	free(a);
	free(b);
	free(c);
	return 0;
}
