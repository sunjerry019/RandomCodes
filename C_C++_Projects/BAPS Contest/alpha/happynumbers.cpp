#include <iostream>
#include <cstdio>

#define MOD 1000000007LL

using namespace std;

int main() {
	
	int n, i, j;
	scanf("%d", &n);
	long long dp[2][11], s;
	for (i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}
	int flag = 1;
	for (i = 2; i <= n; i++) {
		s = 0;
		for (j = 9; j >= 0; j--) {
			s = (s%MOD+dp[1-flag][j]%MOD)%MOD;
			dp[flag][j] = s;
		}
		flag = 1-flag;
	}
	
	s = 0;
	for (i = 0; i <= 9; i++) {
		s = (s%MOD+dp[1-flag][i]%MOD)%MOD;
	}
	
	cout << s << "\n";
	
	return 0;
}
