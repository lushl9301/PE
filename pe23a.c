#include <stdio.h>

int f[28300];

int
isSumOf2Abu(int n)
{
	int i;
	for (i=0; i<=n; i++)
		if (f[i] && f[n-i])
			return 1;
	return 0;		
}
int
main()
{
	int max_n = 28123, min_n = 12;
	int i, j, now;
	for (i=0; i<28300; i++)
		f[i] = 0;
	for (i = min_n; i<max_n; i++)
	{
		now = 1;
		for (j = i/2; j>1; j--)
			if (i%j == 0)
			{
				now += j;
			}
		if (now > i)
			f[i] = 1;
	}
	int sum = 0;
	for (i=0; i<max_n; i++)
		if (!isSumOf2Abu(i))
			sum +=i;
	//sum = max_n*(max_n-1)/2 - sum;
	printf("%d", sum);
}