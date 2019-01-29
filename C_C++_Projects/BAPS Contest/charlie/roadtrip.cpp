#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, t, f, i, j, t1, t2, t3;
int dp[500000][2];
vector<ii> adjList[500000];
void rc(int here, int parent) {
	//if (dp[here][0] != -1) return;
	int b = 0;
	int sb = 0;
	int cur;
	for (int i=0;i<(int)adjList[here].size();i++) {
		if (adjList[here][i].first != parent) {
			rc(adjList[here][i].first, here);
			cur = dp[adjList[here][i].first][0]+adjList[here][i].second;
			if (cur > b) {
				sb = b;
				b = cur;
			} else if (cur > sb) {
				sb = cur;
			}
		}
	}
	dp[here][0] = b;
	dp[here][1] = sb;
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%d", &t);
	scanf("%d", &f);
	for (i=0;i<t;i++) {
		scanf("%d", &t1);
		scanf("%d", &t2);
		scanf("%d", &t3);
		adjList[t1].push_back(ii(t2, -t3));
		adjList[t2].push_back(ii(t1, -t3));
	}
	for (i=0;i<f;i++) {
		scanf("%d", &t1);
		scanf("%d", &t2);
		scanf("%d", &t3);
		adjList[t1].push_back(ii(t2, t3));
		adjList[t2].push_back(ii(t1, t3));
	}
	for (i=0;i<n;i++) {
		dp[i][0] = -1;
	}
	rc(0, 0);
	int m = 0;
	for (i=0;i<n;i++) {
		//printf("%d\n", dp[i][0]+dp[i][1]);
		m = max(m, dp[i][0]+dp[i][1]);
	}
	printf("%d\n", m);
	return 0;
}

