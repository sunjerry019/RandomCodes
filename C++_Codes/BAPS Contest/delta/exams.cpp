#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned long int n, i, c;
	unsigned long long int result = 0;
	unsigned long int d = 100000;
	unsigned long int * const f = (unsigned long int *)malloc(sizeof(unsigned long int) * 200000);
	for (i = 200000; i--; )
	{
		f[i] = 0;
	}
	scanf("%lu", &n);
	
	while (n--)
	{
		i = d;
		while (i < 200000)
		{
			f[i]++;
			i += (i ^ (i & i - 1));
		}
		scanf("%lu", &c);
		c >= 50 ? d-- : d++;
		i = d - 1;
		while (i)
		{
			result += f[i];
			i &= i - 1;
		}
	}
	
	printf("%llu", result);
	free(f);
	return 0;
}

