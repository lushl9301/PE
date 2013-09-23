#include <stdio.h>

int toggle(int *x, int *y)
{
	int z;
	z = *x;
	*x = *y;
	*y = z;
}

int
countLength(int x, int y)
{
	x += y;
	while (y>0)
	{
		x /= 10;
		y /= 10;
	}
	if (x>0)
		return 1;
	return 0;
}

int
main()
{
	int i;
	int ans = 0;
	int numerator = 1, denominator = 2;
	for (i=0; i<50; i++)
	{
		numerator += 2*denominator;
		toggle(&numerator, &denominator);
		if (countLength(numerator, denominator))
		{
			ans++;
			printf("%d %d\n", numerator+denominator, denominator);
		}
	}
	printf("%d\n", ans);
}