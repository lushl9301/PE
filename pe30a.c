#include <stdio.h>
#include <math.h>

int
main()
{
	int i, x, now, ans, t;
	ans = 0;
	for (i=11; i<500000; i++)
	{
		x = i;
		now =0;
		while (x>0)
		{
			t = x%10;
			now += pow(t,5);
			x /= 10;
		}
		if (now == i)
		{
			printf("%d\n", i);
			ans += i;
		}
	}
	printf("%d\n", ans);
}