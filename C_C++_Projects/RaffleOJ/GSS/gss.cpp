#include <cstdio>

using namespace std;

int num[101];

void fshift(int s, int l)
{
	for(int k=l; k >= s; k--)
	{
		int t = num[k];
		num[k+1] = t;
	}
}

//insertion sort
int main()
{
	int n = 0;
	int tt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if(i == 0) num[i] = temp;
		else if(temp > num[0])
		{
			fshift(0,i);
			num[0] = temp;
		}
		else if(temp < num[i-1]) num[i] = temp;
		else
		{
			for(int j = 0; j < i; j++)
			{
				if(num[j] >= temp && num[j+1] <= temp)
				{
					fshift(j+1,i);
					num[j+1] = temp;
					break;
				}
			}
		}
	}
	int o = n%4;
	int p = n/4;
	for(int m = 0; m < p; m++)
	{
		tt += num[m*4]
		   += num[m*4+1]
		   += num[m*4+2];
	}
	for(int m = 0; m < o; m++)
	{
		tt += num[p*4+m];
	}
	printf("%d", tt);
	return 0;
}