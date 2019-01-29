#include <bits/stdc++.h>

using namespace std;

long long int n, q, k;
long long int grad;
vector<long long int> ft;

long long int ls(long long int x) 
{
	return x & (-x);
}

void fenwick_update(long long int p, long long int v)
{
	for(; p <= n; p+=ls(p))
	{
		ft[p] = ((ft[p]%grad) + v%grad)%grad;
	}
}

long long int fenwick_query(long long int p)
{
	long long int sum = 0;
	for(; p; p -= ls(p)) sum += ft[p];
	return sum;
}

int main()
{
	scanf("%lld%lld%lld", &n, &q, &k);
	for(long long int i=0;i<=n;i++)
	{
		ft.push_back(0);
	}
	grad = pow(2, k);
	
	for(long long int i=0; i<q; i++)
	{
		long long int req, d;
		scanf("%lld%lld", &req, &d);
		if(!req)
		{
			long long int s;
			scanf("%lld", &s);
			fenwick_update(d, s%grad);
		}
		else
		{
			printf("%lld\n", (fenwick_query(d)%grad));
		}
	}
	return 0;
}
