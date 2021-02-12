#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"

int check(char* s)
{
	char* afterspace[] = ".,:;?!)}]";
	char* beforespace[] = "({[";
	char space = ' ';
	int i, j, k, las, lbs, len;
	char tmp;
	len = strlen(s) - 1;
	las = strlen(afterspace);
	lbs = strlen(beforespace);
	 
}