#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int main()
{
	char s[80];
	char s0[80];
	char s2[80];
	int i = 0;
	int l, j;
	int l1 = 0;
	char C;
	printf("Enter first string\n");
	gets(s);
	printf("Enter second string\n");
	gets(s0);
	printf("Enter symbol\n");
	scanf_s("%c", &C);
	l = strlen(s);

	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == C)
		{
			s2[l1++] = C;
			for (j = 0; s0[j] != 0; j++)
			{
				s2[l1++] = s0[j];
			}
		}
		s2[l1++] = s[i];
	}
	for(i = 0; i < l1; i++)
	printf("%c", s2[i]);
	
}