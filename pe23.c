#include <stdio.h>

int
main()
{
	int max_n = 28123, min_n = 12;
	int i, j, now;
	int *p, a[28123], f[28300];
	p = a;
	for (i=0; i<28300; i++)
		f[i] = 0;
	for (i = min_n; i<=max_n; i++)
	{
		now = 1;
		for (j = i/2; j>1; j--)
			if (i%j == 0)
			{
				now += j;
			}
		if (now > i)
		{
			*p = i;
			p += 1;
		}
	}
	int sum = 0;
	int len = p - a;
	for (i=0; i<len; i++)
		for (j=i; j<len; j++)
		{
			now = a[i]+a[j];
			if (now < max_n && !f[now])
			{
				f[now] = 1;
				sum += now;
			}
		}
	sum = max_n*(max_n-1)/2 - sum;
	printf("%d", sum);
}