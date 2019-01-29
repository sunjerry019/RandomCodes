#include <bits/stdc++.h>

using namespace std;

long double root5 = sqrt(5);

long double fib(int n, int m)
{
	long double a = ((1/root5)/(1<<n));
	long double b = pow((1+root5), n);
	long double c = pow((1-root5), n);
	long double kek = a*(b - c);
	return kek;
	//cout << kek;
	//long long int ans = kek%(long long int) m;
	//return (int) ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	int X, M, N;
	cin >> X; 
	for (int i = 0; i < X; i++)
	{
		cin >> N >> M;
		cout << root5 << endl;
		cout << fib(N, M) << endl;
	}
	return 0;
}