#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint_least32_t *stored_ways;

unsigned long int find_ways(unsigned long int x)
{
	return x >> 20 ? x & 1 ? find_ways(x >> 1) : find_ways(x >> 1) + find_ways((x >> 1) - 1) : stored_ways[x];
}

int main(void)
{
	unsigned long int remaining_cases, i, j, l, h, m;
	signed long int v;
	stored_ways = (uint_least32_t *)malloc(1048576 * sizeof(uint_least32_t));
	
	scanf("%*lu%lu", &remaining_cases);
	
	stored_ways[0] = 1;
	stored_ways[1] = 1;
	for (i = 2; i != 1048576; i++)
	{
		stored_ways[i] = stored_ways[i >> 1];
		if (!(i & 1))
		{
			stored_ways[i] += stored_ways[(i >> 1) - 1];
		}
	}
	
/*	while (remaining_cases--)
	{
		scanf("%lu", &i);
		printf("%lu\n", find_ways(i));
	}*/
	while (remaining_cases--)
	{
		scanf("%lu%lu", &i, &j);
		v = (signed long int)find_ways(j) - (signed long int)find_ways(i);
		if (v < 0)
		{
			putchar('-');
			v = -v;
		}
		l = 0;
		h = 1024;
		while (h - l != 1)
		{
			m = h + l >> 1;
			if (m * m > v)
			{
				h = m;
			}
			else
			{
				l = m;
			}
		}
		printf("%lu\n", l);
	}
	
	free(stored_ways);
	return 0;
}
