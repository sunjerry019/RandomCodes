#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<pair<int, pair<int, int> > >v;
int best[100005];

int main () {
	scanf("%d%d", &n, &e);
	for (int i = 0; i < e; i++)  {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		pair<int, pair<int, int> >p = v[i];
		int orig = p.second.first, dest = p.second.second;
		int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
		t1 = max(best[dest], best[orig] + 1);
		t2 = max(best[orig], best[dest] + 1);
		best[dest] = t1; best[orig] = t2;
		ans = max(ans, best[dest]);
		ans = max(ans, best[orig]);
	}
	printf("%d\n", ans);
}
