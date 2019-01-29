#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
#define ii pair<int,int>
#define M 1000000007
vector<int> v[1000005];
int n,k,b;
int mem[1000005];
int start[1000005];
int main() {
	scanf("%d%d%d",&n,&k,&b);
	int bar,p;
	for (int i=0;i<n;i++) {
		scanf("%d%d",&bar,&p);
		v[bar-1].pb(p);
	}
	start[0]=0;
	sort(all(v[0]));
	for (int i=1;i<b;i++) {
		start[i]=start[i-1]+sz(v[i-1]);
		sort(all(v[i]));
	}
	for (int i=0;i<b;i++) {
		if (v[i].empty()) {
			printf("0\n");
			return 0;
		}
	}
	
	mem[0]=1;
	for (int i=1;i<sz(v[0]);i++) {
		mem[i]=mem[i-1]+1;
	}
	for (int i=1;i<b;i++) {
		for (int j=0;j<sz(v[i]);j++) {
			int idx=start[i]+j;
			int x;
			if (v[i-1].back()<v[i][j]-k) {
				mem[idx]=0;
			} else if (v[i-1][0]>v[i][j]+k) {
				mem[idx]=0;
			} else {
				x=lower_bound(all(v[i-1]),v[i][j]-k)-v[i-1].begin()+start[i-1];
				int y;
				y=upper_bound(all(v[i-1]),v[i][j]+k)-v[i-1].begin()+start[i-1];
				--y;
				if (x==start[i-1]) mem[idx]=mem[y];
				else mem[idx]=mem[y]-mem[x-1];
			}
			mem[idx]+=M;
			mem[idx]%=M;
			if (j) {
				mem[idx]+=mem[idx-1];
				mem[idx]%=M;
			}
		}
	}
	printf("%d\n",mem[n-1]);
}
