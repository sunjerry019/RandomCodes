#include <bits/stdc++.h>
using namespace std;

int n, arr[1000005], dp[1000005];

int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int ans = 0;
	dp[n-1] = 1;
	for (int i = 2; i <= n; i++) {
		int cur = n-i;
		if (arr[cur] > dp[cur+1]) {
			dp[cur] = dp[cur+1]+1;
		} else {
			dp[cur] = 1;
		}
		ans = max(ans, dp[cur]);
	}
	printf("%d\n", ans);
}
