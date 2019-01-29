#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int i, n, k, a[1005], c = 1, p = 0;
	scanf("%d%d", &n, &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+k);
	int ans = 1;
	while (c < n) {
		if (p != k-1 && c < a[p+1]-1) {
			c += a[p];
			ans++;
		}
		else if (p == k-1) {
			c += a[p];
			ans++;
		}
		else p++;
	}
	
	cout << ans << "\n";
	
	return 0;
}
