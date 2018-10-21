#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
#define ii pair<int,int>
#include "ants.h"
#define HEAVY 1
#define ROOT 0
#define LIGHT 0
using namespace std;
int parent[100005],n,m;
vector<ii> chil[100005];
bitset<100005> state;
int depth[100005];
int skip[100005],value[100005]={0},length[100005];
int pre[100005],cnt=1,end[100005];
int lca(int a, int b) {
	while(skip[a]!=skip[b]) {
		if (depth[skip[a]]<depth[skip[b]]) b=parent[skip[b]];
		else a=parent[skip[a]];
	}
	if (depth[a]<depth[b]) return a;
	else return b;
}
void dfs(int u) {
	pre[u]=cnt++;
	if(u!=ROOT) depth[u]=depth[parent[u]]+1;
	end[u]=pre[u];
	for (int i=0;i<sz(chil[u]);i++) {
		if (chil[u][i].first!=parent[u]) {
			parent[chil[u][i].first]=u;
			dfs(chil[u][i].first);
			end[u]=max(end[u],end[chil[u][i].first]);
		}
	}
}
int hldecomp(int u) {
	if (chil[u].empty()) {
		return 1;
	} else {
		int total=1;
		int m=0,t=0;
		for (int i=0;i<sz(chil[u]);i++) {
			if (chil[u][i].first==parent[u]) continue;
			int tmp = hldecomp(chil[u][i].first);
			total += tmp;
			if (tmp>t) {
				t=tmp;
				m=i;
			}
		}
		state[chil[u][m].first]=HEAVY;
		length[u]=length[chil[u][m].first]+1;
		for (int i=0;i<sz(chil[u]);i++) {
			if (chil[u][i].first==parent[u]) continue;
			if (i!=m) state[chil[u][i].first]=LIGHT;
		}
		return total;
	}
}
void construct(int u) {
	if (state[u]==LIGHT) skip[u]=u;
	else skip[u]=skip[parent[u]];
	for (int i=0;i<sz(chil[u]);i++) {
		if (chil[u][i].first==parent[u]) continue;
		construct(chil[u][i].first);
	}
}


using namespace std;
class fenwick {
public:
	int ft[100005];
	void update(int p,int v) {
		for (int b=p;b<=100003;b+=(b&(-b))) ft[b]+=v;
	}
	int query(int p) {
		int r=0;
		for (int b=p;b>0;b-=(b&(-b))) r+=ft[b];
		return r;
	}
	int query(int a,int b) {
		return query(b)-query(a-1);
	}
};
fenwick dist;
void formdist(int v,int d) {
	dist.update(pre[v],d);
	dist.update(pre[v]+1,-d);
	for (int i=0;i<sz(chil[v]);i++) {
		if (chil[v][i].first==parent[v]) continue;
		formdist(chil[v][i].first,d+chil[v][i].second);
	}
}
void tree(int _N, int _E, int A[], int B[], int D[]) {
	n=_N;
	for (int i=0;i<n;i++) {
		chil[A[i]].pb(mp(B[i],D[i]));
		chil[B[i]].pb(mp(A[i],D[i]));
	}
	parent[ROOT]=-1;
	dfs(ROOT);
	state[ROOT]=LIGHT;
	hldecomp(ROOT);
	construct(ROOT);
	formdist(0,0);
}
void adjust(int e, int v) {
    return;
}

void safe(int e) {
    return;
}

void dangerous(int e) {
    return;
}

int energy(int x, int y) {
    return dist.query(pre[y])-dist.query(pre[x]);
}


