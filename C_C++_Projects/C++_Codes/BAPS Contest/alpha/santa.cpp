#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[105][3005];
int vsum[105][3005];
vector<pair<int, int> >sums;

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
	
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			vsum[j][i] = vsum[j-1][i] + arr[j-1][i];
		}
	}
	
	int ans = 0;
	
	for (int i = 0; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			int tot = 0;
			for (int k = 0; k < m; k++) {
				tot += (vsum[j][k] - vsum[i][k]);
				sums.push_back(make_pair(tot, k));
			}
			sums.push_back(make_pair(0, 0));
			sort(sums.begin(), sums.end());
			int cur = 0, low, best=0;
			for (int k = 0; k < m; k++) {
				if (cur == sums[k].first) best = max(best, sums[k].second - low + 1);
				else {
					cur = sums[k].first;
					low = sums[k].second;
				}
			}
			ans = max(ans, (best-1)*(j-i));
			sums.clear();
		}
	}
	printf("%d\n", ans);
}
