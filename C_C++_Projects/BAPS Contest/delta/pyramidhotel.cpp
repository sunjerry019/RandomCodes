#include <bits/stdc++.h>
using namespace std;

int N, h[1000100], mx, m[1000100];

int main() {
	//freopen("in", "r", stdin);
	scanf("%i", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%i", &h[i]);
	}
	if (h[N - 1] > 0){ 
		m[N - 1] = 1;
		mx = 1;
	}
	for (int i = N - 2; i >= 0; --i) {
		if (h[i] > m[i + 1]) {
			m[i] = m[i + 1] + 1;
		} else if (h[i] == m[i + 1]) {
			m[i] = m[i + 1];
		} else {
			m[i] = h[i];
		}
		mx = max(mx, m[i]);
	}
	printf("%i\n", mx);
	return 0;
}
