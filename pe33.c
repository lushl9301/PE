#include <stdio.h>
#include <math.h>

int
main()
{
	int i, j;
	float original_value, a1, a2, b1, b2;
	for (i=11; i<100; i++)
		if (i%10 != 0)
			for (j=i+1; j<100; j++)
				if (j%10 != 0 && i!=j)
				{
					original_value = i*1.0/j;
					a1 = (i/10)*1.0; a2 = 1.0*(i%10);
					b1 = (j/10)*1.0; b2 = 1.0*(j%10);
					if (a1==a2 && b1==b2)
						continue;
					if (fabs(original_value-a1/b1)<1e-6 && fabs(a2-b2)<1e-6
						|| fabs(original_value-a1/b2)<1e-6 && fabs(a2-b1)<1e-6
						|| fabs(original_value-a2/b1)<1e-6 && fabs(a1-b2)<1e-6
						|| fabs(original_value-a2/b2)<1e-6 && fabs(a1-b1)<1e-6)
						printf("%d/%d  %f\n", i, j, original_value);
				}
	return 0;
}