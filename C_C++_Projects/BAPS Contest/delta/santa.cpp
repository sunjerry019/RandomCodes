#include <stdio.h>
#include <algorithm>
#include <utility>

int main(void)
{
	unsigned short int height, x, y, z, i;
	
	unsigned long int width, record = 0;
	long int current;
	
	scanf("%hu%lu", &height, &width);
	
	if (height == 1)
	{
		long int v, i = 0, x;
		std::pair<long int, long int> *considers = new std::pair<long int, long int>[width + 1];
		current = 0;
		while (1)
		{
			considers[i] = std::make_pair(current, i);
			if (i++ != width)
			{
				scanf("%li", &v);
				current += v;
			}
			else
			{
				break;
			}
		}
		std::sort(considers, considers + width + 1);
		
		x = 0;
		while (x <= width)
		{
			i = x;
			while (considers[i + 1].first == considers[x].first && i != width)
			{
				i++;
			}
#ifdef TESTING
			if (x != i)
			{
				printf("%hi %hi\n", considers[x].second, considers[i].second);
			}
#endif
			if ((long int)(considers[i].second - considers[x].second) > record)
			{
				record = (long int)(considers[i].second - considers[x].second);
			}
			x = i + 1;
		}
		printf("%li", record);
		return 0;

	}
	long int *value_sums = new long int[width + 1 << 7];
	std::pair<long int, long int> *considers = new std::pair<long int, long int>[width + 1];
#ifdef TESTING
	puts("Checkpoint 0");
#endif
	
	for (x = width; x; x--)
	{
		value_sums[x << 7] = 0;
	}
	value_sums[height] = 0;
	
	for (y = 0; y != height; y++)
	{
		value_sums[y] = 0;
		for (x = 0; x != width; x++)
		{
			scanf("%li", &current);
			value_sums[(x << 7 | y) + 129] = value_sums[x + 1 << 7 | y] + value_sums[x << 7 | y + 1] - value_sums[x << 7 | y] + current;
		}
	}
#ifdef TESTING
	for (y = 0; y <= height; y++)
	{
		for (x = 0; x <= width; x++)
		{
			printf("%i ", value_sums[x << 7 | y]);
		}
		putchar('\n');
	}
#endif
	
	for (z = 1; z <= height; z++)
	{
		for (y = 0; y < z; y++)
		{
			for (x = 0; x <= width; x++)
			{
				considers[x] = std::make_pair(value_sums[x << 7 | z] - value_sums[x << 7 | y], x);
			}
			std::sort(considers, considers + width + 1);
			x = 0;
			while (x <= width)
			{
				i = x;
				while (considers[i + 1].first == considers[x].first && i != width)
				{
					i++;
				}
#ifdef TESTING
				if (x != i)
				{
					printf("%hi %hi %hi %hi\n", considers[x].second, considers[i].second, y, z);
				}
#endif
				if ((long int)(considers[i].second - considers[x].second) * (z - y) > record)
				{
					record = (long int)(considers[i].second - considers[x].second) * (z - y);
				}
				x = i + 1;
			}
		}
	}
	
	printf("%i", record);
	
	free(value_sums);
	free(considers);
	return 0;
}
