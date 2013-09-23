#include <stdio.h>

int main(void)
{
  int results[1000] = {0}, a, b, c;

  for (a = 0; a < 1000; a++)
    for (b = 0; b < a; b++)
      for (c = 0; c < 1000; c++)
        if (a+b+c < 1000)
          if (a*a + b*b == c*c)
          {
            if (a+b+c == 840)
              printf("%d %d %d\n", a, b, c);
            results[a+b+c]++;
          }

  b = 0;
  for (a = 0; a < 1000; a++)
    if (results[a] > b)
    {
      b = results[a];
      c = a;
    }

  printf("%d  %d\n", b, c);
}