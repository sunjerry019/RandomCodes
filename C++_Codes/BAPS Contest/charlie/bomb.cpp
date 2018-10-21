#include <bits/stdc++.h>
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef pair<ll, ii> llii;
int n, i, j, m, best;
ll t1;
li arr[100000];
int matches = 1;
/*int id[100000];
int forests;
int find(int x) {
	if (x == id[x]) return x;
	return id[x] = find(id[x]);
}
int join(int x, int y) {
	//
}*/
ii groups[100000];
struct cmpre {
	bool operator()(ii a, ii b) {
		return a.second<b.first;
	}
} cmpator;
vector<ii> intervals;
int main(void) {
	scanf("%d", &n);
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	for (i=0;i<n;i++) {
		scanf("%lld", &t1);
		arr[i] = li(t1, i);
	}
	sort(arr, arr+n);
	ll cur = arr[0].first;
	int st = arr[0].second;
	for (i=1;i<n;i++) {
		if (arr[i].first != cur) {
			intervals.push_back(ii(st, arr[i-1].second));
			st = arr[i].second;
			cur = arr[i].first;
		}
	}
	intervals.push_back(ii(st, arr[i-1].second));
	groups[0] = intervals[0];
	int ed = 1;
	int l;
	for (i=1;i<(int)intervals.size();i++) {
		l = lower_bound(groups, groups+ed, intervals[i], cmpator)-groups;
		groups[l] = ii(min(groups[l].first, intervals[i].first), max(groups[ed-1].second, intervals[i].second));
		ed = l+1;
	}
	printf("%d\n", ed);
	return 0;
}
