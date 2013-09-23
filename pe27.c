#include <stdio.h>
#define SIZE 30000

int prime[SIZE];
int prime_list[10000];
int n_prime;

int
findPrime()
{
	int i, j;
	int *p;
	p = prime_list;
	for (i=0; i<SIZE; i++)
		prime[i] = 1;
	prime[0] = 0; prime[1] = 0;
	i = 2; *p = 2; j = i*i;
	while (j<SIZE)
	{
		prime[j] = 0;
		j += i;
	}
	for (i=3; i<SIZE; i +=2)
		if (prime[i])
		{
			*(++p) = i;
			j = i*i;
			while (j<SIZE)
			{
				prime[j] = 0;
				j += i;
			}
		}
	n_prime = p - prime_list;
	return 0;
}

int
calcFormula(int a, int b)
{
	int n, tmp;
	for (n=0; n<100; n++)
	{
		tmp = n*n + a*n + b;
		if (!prime[tmp])
		{
			return n;
		}
	}
	return 0;
}

int
main()
{
	int max = 0;
	int a, b, i;
	int now, min_a, num, xa, xb;
	findPrime();
	max = 0;
	for (i=12; i<n_prime; i++)
	{
		b = prime_list[i];
		if (b >= 1000)
			break;
		min_a = -b/40 - 40;
		min_a = min_a < (1-b) ? (1-b) : min_a;
		num = 0;
		for (a=min_a; a<1000; a++)
		{
			now = calcFormula(a, b);
			if (now > max)
			{
				max = now;
				xa = a;
				xb = b;
			}
		}
	}
	printf("%d, %d, %d", max, xa, xb);
	return 0;
}