#include <bits/stdc++.h>
using namespace std;
int n, i, m = 0;
int arr[1000001];
int main() {
	scanf("%d", &n);
	for (i=0;i<n;i++) {
		scanf("%d", &arr[i]);
	}
	arr[n] = 0;
	for (i=n-1;i>=0;i--) {
		arr[i] = min(arr[i], 1+arr[i+1]);
	}
	m = 0;
	for (i=0;i<n;i++) {
		m = max(m, arr[i]);
	}
	printf("%d\n", m);
	return 0;
}

