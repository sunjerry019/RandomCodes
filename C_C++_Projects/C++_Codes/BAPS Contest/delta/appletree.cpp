#include <stdio.h>
#include <algorithm>

int main(void)
{
	unsigned long int n, e, i, a, b, c, record = 0;
	
	scanf("%lu%lu", &n, &e);
	
	unsigned long int *place = new unsigned long int[n];
	unsigned long long int *edge = new unsigned long long int[e];
	
	for (i = e; i--; )
	{
		scanf("%lu%lu%lu", &a, &b, &c);
		edge[i] = (unsigned long long int)c << 34 | (unsigned long long int)b << 17 | a;
	}
	
	for (i = n; i--; )
	{
		place[i] = 0;
	}
	
	std::sort(edge, edge + e);
	
	for (i = 0; i != e; i++)
	{
		b = edge[i] >> 17 & 0x1FFFF;
		a = edge[i] & 0x1FFFF;
		
		if (place[a] == place[b])
		{
			place[b]++;
			if (place[a]++ == record)
			{
				record++;
			}
		}
		else if (place[a] < place[b])
		{
			if ((place[a] = place[b] + 1) > record)
			{
				record++;
			}
		}
		else
		{
			if ((place[b] = place[a] + 1) > record)
			{
				record++;
			}
		}
	}
	
	printf("%lu", record);
	
	delete [] place;
	delete [] edge;
	return 0;
}
