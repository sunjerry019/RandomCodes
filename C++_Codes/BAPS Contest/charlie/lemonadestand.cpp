#include <bits/stdc++.h>
using namespace std;
int coins[1000];
int n, k, i;
int nc = 0, canmake = 0;
int main() {
	scanf("%d%d",&n,&k);
	if (k == 1) {
		printf("%d\n", n);
		return 0;
	}
	for (i=0;i<k;i++) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins+k);
	for (i=1;i<k;i++) {
		while (canmake>coins[i]) i++;
		while (canmake<coins[i]-1) {
			if (canmake>=n) {
				printf("%d\n", nc);
				return 0;
			}
			canmake += coins[i-1];
			nc++;
		}
	}
	while (canmake<n) {
		canmake += coins[k-1];
		nc++;
	}
	printf("%d\n", nc);
	return 0;
}

