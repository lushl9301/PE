#include <stdio.h>
#include <stdlib.h>
int f[20000000];
int
find_len(m)
{
    int times = 0;
    int n = m;
    while (n>1)
    {
	if (f[n] != 0)
	{
	    times += f[n];
	    return times;
	}
	if (n % 2 == 0)
	    n = n / 2;
	else n= n * 3 + 1;
	times++;
    }
    f[m] = times;
    return(times);
}


int
main()
{
    
    int max = 1, x = 0;
    int now = 0, i;
    for (i=0;i<1000000;i++)
	f[i] = 0;
    f[1] = 1;
    for (i=1000; i>0;i--)
    {
	now = find_len(i);
	if (max<now)
	{
	    max = now;
	    x = i;
	}
	//printf("%d %d\n", i ,now);
    }
    printf("%d %d\n", x, max);
}
