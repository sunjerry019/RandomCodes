#include <bits/stdc++.h>
using namespace std;
#define MAXN 500000
typedef pair<int,int> ii;
vector<ii> adjl[MAXN];
ii dp[MAXN];
bool visited[MAXN];

int n, t, f;

void dfs(int u, int p) {
	//printf("%d %d\n",u,p);
	int max1=0, max2=0;
	for(int i=0;i<(int)adjl[u].size();i++) {
		ii e = adjl[u][i];
		int v = e.first;
		int c = e.second;
		if(v==p)
			continue;
		dfs(v,u);
		int cmax = dp[v].first+c;
		if(cmax>max2) {
			if(cmax>max1) {
				max2 = max1;
				max1 = cmax;
			} else {
				max2 = cmax;
			}
		}
	}
	//printf("%d %d %d,%d\n",u,p,max1,max2);
	dp[u] = ii(max1,max2);
}

int main () {
	scanf(" %d %d %d", &n, &t, &f);
	for (int i = 0; i < t; i++) {
		int a, b, c;
		scanf(" %d %d %d", &a, &b, &c);
		adjl[a].push_back(ii(b, -c));
		adjl[b].push_back(ii(a, -c));
	}
	for (int i = 0; i < f; i++) {
		int a, b, c;
		scanf(" %d %d %d", &a, &b, &c);
		adjl[a].push_back(ii(b, c));
		adjl[b].push_back(ii(a, c));
	}
	dfs(0,-1);
	int max = 0;
	for(int i=0;i<n;i++) {
		//printf("%d: %d,%d\n",i,dp[i].first,dp[i].second);
		int v = dp[i].first + dp[i].second;
		if(v>max)
			max = v;
	}
	printf("%d\n",max);
	return 0;
}
