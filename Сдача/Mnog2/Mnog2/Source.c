#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "conio.h"

//void main()
//{
//	int** A = NULL;
//	mnog(A); 
//}


int main()
{
	int m = 5;
	int n;
	int i, j;
	int range;
	int num = 0;
	int* A;
	
	printf("Enter range for Matrix:\n");
	scanf_s("%d", &range);
	printf("Enter number of objects:\n");
	scanf_s("%d", &n);
	
	A = (int*)malloc(sizeof(int) * n);
	int** B;
	B = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
	{
		B[i] = (int*)malloc(sizeof(int) * m);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf_s("%d\n", &B[i][j]);
		}
	}

	printf("Matrix\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t", B[i][j]);
		}
		printf("\n");
	}

	int k = 0;
	int p = 0;
	int q = 0;
	int r = 0;
	int max1 = 0;
	int min = 0;
	int max = range;
	int mid = (max + min) / 2;

	max = B[0][0];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (B[i][j] > max)
			{
				max = B[i][j];
			}
			
		}
	}

	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < m; j++)
		{
			if (B[i][j] == max)
			{
				k++;
			}
		}
		if (k > 2)
		{
			A[p] = i;
			p++;
		}
	}



	min = B[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (min > B[i][j])
			{
				min = B[i][j];
			}
			
		}
	}

	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < m; j++)
		{
			if (B[i][j] == min)
			{
				k++;
			}
		}
		if (k > 2)
		{
			A[p] = i;
			p++;
		}
	}

	for (i = 0; i < p; i++)
	{
		printf("A[%d] = %d\n", i, A[i]);
	}
	
	printf("max = %d\n", max);
	printf("min = %d\n", min);

	//if (k >= 2 || p >= 2)
	//{
	//	printf("Unique object found\n");
	//}
	//else
	//	printf("Unique object not found\n");
	//
	//if (q == 5)
	//{
	//	printf("Middle object found\n");
	//}
	//else
	//	printf("Middle object not found\n");
	free(A);
	for (i = 0; i < n; i++)
	{
		free(B[i]);
	}
	free(B);
}