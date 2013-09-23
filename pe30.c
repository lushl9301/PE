#include <stdio.h>
#include <string.h>
#include <math.h>

int eqArr[7];

int
check(int sum, int len)
{
	int i;
	char *ans, c;
	//if (sum<500)
	//	printf("%d ", sum);
	sprintf(ans, "%d\0", sum);
	if (strlen(ans) != len)
		return 0;
	for (i=0; i<len; i++)
	{
		c = eqArr[i]+48;
		if (c != eqArr[i])
			return 0;
	}
	return 1;
}

int
calc(int len)
{
	int i, sum = 0;
	for (i=0; i<len; i++)
		if (eqArr[i]!=0)
		{
			sum += (int)pow(eqArr[i],4);
		}
	if (check(sum, len))
	{
		printf("%d\n", sum);
	}
	return 0;
}

int
generateEquation(int k, int len)
{
	int i;
	if (k >= len)
	{
		calc(len);
		return 0;
	}
	for (i=0; i<10; i++)
	{
		eqArr[k] = i;
		generateEquation(k+1, len);
	}
	return 0;
}

int
main()
{
	int l, *p;
	for (l=2; l<4; l++)
	{
		generateEquation(0, l);
	}
	return 0;
}