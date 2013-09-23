#include <stdio.h>

int
calcFactorial(int n)
{
	int fac=1;
	for (; n>1; n--)
		fac *= n;
	return fac;
}

int
main()
{
	int i, x;
	int ans=0, sum;
	for (i=145; i<1000000; i++)
	{
		sum = 0;
		for (x=i; x>0; x /=10)
			sum += calcFactorial(x%10);
		if (sum == i)
			ans += i;
	}
	printf("%d\n", ans);

	return 0;
}