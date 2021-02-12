#include "math.h"
#include "stdlib.h"
#include "stdio.h"

typedef double (*FunctionF)(double);
typedef double (*FunctionN)(double);


int factorial(int n)
{
	int i, k = 1;
	for (i = 0; i <= n; i++)
	{
		k = k * i;
		return k;
	}
}
double LnF(double x)
{
	return x;
}

double LnN(double x, int i)
{
	return ((-1) * x * (i - 1) / (i));
}

double ChF(double x)
{
	return 1;
}

double ChN(double x, int i)
{
	return x * x / factorial(2 * i);
}

double CosF(double x)
{
	return 1;
}

double CosN(double x, int i)
{
	return ((pow(-1, i) * pow(x, 2 * i)) / fact(2 * i));
}

double sum(FunctionF first, FunctionN next, double x, int kmax, double ideal, double* diff, int* i, double EPS)
{
	double elem, elemN, sum;
	*i = 1;
	elem = first(x);
	sum = elem;
	*diff = fabs(sum - ideal);
	while ((*i < kmax) && (*diff > EPS))
	{
		elemN = elem * next(x, *i);
		sum += elemN;
		elem = elemN;
		*diff = fabs(sum - ideal);
		(*i)++;
	}

	return sum;
}

int menu()
{
	printf(" 1. ln(1 + x)\n");
	printf(" 2. ch(x)\n");
	printf(" 3. sin(x)\n");
	printf(" 0. Exit\n");
}

int main()
{
	int n, i, k;
	double x, y;
	double diff;
	double EPS;

	k = 1;
	i = 0;

	

	while (k != 0)
	{
		menu();
		scanf_s("%d", &k);

		switch (k)
		{
		case 1:
			printf(" 1. ln(1 + x) \n");
			scnaf_s("%lf", &x);
			scnaf_s("%d", &n);
			scnaf_s("%lf", &EPS);
			double ideal = log(1 + x);
			double y = sum(LnF, LnN, x, n, ideal, &diff, &i, EPS);
			printf("Ideal: %.5f\n", ideal);
			printf("value: %.5f\n", y);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", i);
			break;

		case2: 
			printf(" 2. ch(x) \n");
			scnaf_s("%lf", &x);
			scnaf_s("%d", &n);
			scnaf_s("%lf", &EPS);
			double ideal = cosh(x);
			double y = sum(ChF, ChN, x, n, ideal, &diff, &i, EPS);
			printf("Ideal: %.5f\n", ideal);
			printf("value: %.5f\n", y);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", i);
			break;

		case 3:
			printf(" 3. sin(x)\n");
			scnaf_s("%lf", &x);
			scnaf_s("%d", &n);
			scnaf_s("%lf", &EPS);
			double ideal = sin(x);
			double y = sum(CosF, CosN, x, n, ideal, &diff, &i, EPS);
			printf("Ideal: %.5f\n", ideal);
			printf("value: %.5f\n", y);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", i);
			break;
			
		default:
			printf("Please, enter number 1 to 3");
		}
	}
}
