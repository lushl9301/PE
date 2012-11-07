#include <stdio.h>

int
leap(year)
{
	if ((year % 100 == 0) && (year % 400 == 0))
		return 1;
	if ((year % 100 != 0) && (year % 4 == 0))
		return 1;
	return 0;
}

int M[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; 
int
main()
{
	int y, m, d, week = 0, ans = 0, monthDay;
	//force to count
	for (y=1900; y < 2001; y++)
	{
		for (m=1; m < 13; m++)
		{
			if (m == 2)
				monthDay = 28 + leap(y);
			else
				monthDay = M[m];
			for (d=0; d < monthDay; d++)
			{
				if ((d == 0) && (week == 6))
					ans ++;
				week = (week + 1) % 7;
			}
		}
	}
	//minus what i added during 1900
	//	problem is asking for from 1901 to 2001. so should minus the addtional part.
	y = 1900;
	for (m=1; m < 13; m++)
	{
		if (m == 2)
			monthDay = 28 + leap(y);
		else
			monthDay = M[m];
		for (d=0; d < monthDay; d++)
		{
			if ((d == 0) && (week == 6))
				ans --;
			week = (week + 1) % 7;
		}
	}
	printf("%d", ans);
}