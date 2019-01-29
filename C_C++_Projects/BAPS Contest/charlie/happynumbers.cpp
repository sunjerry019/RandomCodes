#include <bits/stdc++.h>
using namespace std;
long long int  mul_inv(long long int  a, long long int  b)
{
	long long int  b0 = b, t, q;
	long long int  x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
long long int ncr(long long int  n,long long int  k)
{
	long long int hi=1,lo=1;
	if(n-k<k)k=n-k;
	for(int i = n;i>n-k;i--)
	{
		hi*=i;
		hi%=1000000007;
	}
	for(int i = 1;i<=k;i++)
	{
		lo*=i;
		lo%=1000000007;
	}
	return (hi*(mul_inv(lo,1000000007)%1000000007))%1000000007;
}
int main() {
	long long int n;
	scanf("%lld",&n);
	printf("%lld\n",ncr(9+n,n));
    return 0;
}
