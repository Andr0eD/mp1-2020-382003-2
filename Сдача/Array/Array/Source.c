#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
//Number 21
//int main()
//{
//	int n, m = 0;
//	int i, j;
//	int A[100];
//	int B[100];
//
//	printf("Enter N:\n");
//	scanf_s("%d", &n);
//	printf("Enter Array\n");
//	
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", &A[i]);
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		printf("A[%d] = %d\n", i, A[i]);
//	}
//	
//	for (i = 0; i < n; i++)
//	{
//		for (j = 2; j < A[i]; j++)
//		{
//			if (A[i] % j == 0)
//			{
//				A[i] = 1;
//			}
//		}
//			
//	}
//	
//	printf("\n");
//	
//	for (i = 0; i < n; i++)
//	{
//		if (A[i] != 1)
//		{
//			B[m] = i;
//			printf("Number = %d\n", B[m]);
//			m++;
//		}
//		
//	}
//}


//Number 36d

void main()
{
	double a[100];
	double b[100];
	int i, j, Number, First_point, Second_point;
	double distance;
	i = 0;
	distance = 0;
	First_point = -1;
	Second_point = -1;
	printf("Enter numbers of massive:");
	scanf_s("%d", &Number);
	printf("Enter first massive element:");
	for (i = 0; i < Number; i++)
	{
		scanf_s("%lf", &a[i]);
	}
	printf("Enter second massive element:");
	for (i = 0; i < Number; i++)
	{
		scanf_s("%lf", &b[i]);
	}
	for (i = 0; i < Number; i++)
		for (j = i + 1; j < Number; j++)
		{
			if (sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j])) > distance)
			{
				distance = sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]));
				First_point = i;
				Second_point = j;
			}
		}
	if (Second_point != -1)
	{
		printf("Fist dot=%d,Second dot=%d", First_point, Second_point);
	}
	else printf("All right!");
}