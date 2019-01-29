#include <bits/stdc++.h>

using namespace std;

vector<long int> p;
vector<long int> p2;
long int n, k;

long int power(long int q)
{
	for(long int i = 1; i <= q; i++)
	{
		p.push_back(((p[i-1]%1000000007)*2)%1000000007);
	}
	return p[q]%1000000007;
}

long int power2(long int q, long int pow)
{
	if(pow < 0) return 1/power2(q, abs(pow));
	//q is base
	for(long int i = 1; i <= (pow); i++)
	{
		p2.push_back(((p2[i-1]%1000000007)*q)%1000000007);
	}
	return p2[pow]%1000000007;
}

int main()
{
	scanf("%ld%ld", &n, &k);
	p.push_back(1);
	p2.push_back(1);
	long int ans = power2(power(k), n-1) ;
	printf("%ld\n", ans);
	return 0;
}
