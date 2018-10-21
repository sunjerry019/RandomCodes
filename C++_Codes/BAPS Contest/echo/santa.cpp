#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
#define ii pair<int,int>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<int> a[105];
vector<pair<int,int> > v;
int n,m,t;
int ans=0;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d",&t);
			a[i].pb(t);
			if (j) a[i][j]+=a[i][j-1];
		}
	}
	for (int j=0;j<m;j++) {
		for (int i=1;i<n;i++) {
			a[i][j]+=a[i-1][j];
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=i;j<n;j++) {
			v.clear();
			for (int k=0;k<m;k++) {
				int x;
				if (i) x=a[j][k]-a[i-1][k];
				else x=a[j][k];
				v.pb(mp(x,k));
				if (x==0) ans=max(ans,(k+1)*(j-i+1));
			}
			sort(all(v));
			int l=0;
			for (int k=1;k<m;k++) {
				if (v[k].first==v[k-1].first) {
					ans=max(ans,(v[k].second-l)*(j-i+1));
				} else {
					l=v[k].second;
				}
			}
		}
	}
	printf("%d\n",ans);
}
