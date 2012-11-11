#include <stdio.h>

int
main()
{
    int i = 0, now, j;
    int sum = 0;
    int f[10000];
    for (i=1; i<10000; i++)
    {
	now = i;
	f[i] = 1;
	for (j=now/2; j>1; j--)
	    if (now%j == 0)
		f[i] +=j;
    }
    for (i=1; i<10000; i++)
	if ((f[i] < 10000) && (f[f[i]] == i) && (f[i]!=i))
	{
	    sum += i;
	    printf("%d %d\n",i, f[i]);
	}
    printf("%d", sum);
    return 0;
}
