#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
#include "lightson.h"
int ft1[500005],ft0[500005],n,m;
int cnt=1,total0=0,total1=0;
int lastcol[500005];
bool statecol[500005];
int lastrow[500005];
bool staterow[500005];
void update1(int p,int v){
	for (int b=p;b<=500003;b+=(b&(-b))) ft1[b]+=v;
	total1+=v;
}
int query1(int p) {
	int r=0;
	for (int b=p;b>0;b-=(b&(-b))) r+=ft1[b];
	return r;
}
void update0(int p,int v){
	for (int b=p;b<=500003;b+=(b&(-b))) ft0[b]+=v;
	total0+=v;
}
int query0(int p) {
	int r=0;
	for (int b=p;b>0;b-=(b&(-b))) r+=ft0[b];
	return r;
}
void flat(int N, int M) {
    n=N;
	m=M;
	memset(lastcol,-1,sizeof(lastcol));
	memset(lastrow,-1,sizeof(lastrow));
}
void setFloor(int N, bool S) {
	lastrow[N]=cnt;
	staterow[N]=S;
	cnt++;
    return;
}

void setUnit(int N, bool S) {
	if (lastcol[N]!=-1) {
		if (statecol[N]) {
			update0(lastcol[N],-1);
		} else {
			update1(lastcol[N],-1);
		}
	}
	lastcol[N]=cnt;
	statecol[N]=S;
	if (S) {
		update0(cnt,1);
	} else {
		update1(cnt,1);
	}
	cnt++;
}

int countLights(int N) {
	if (lastrow[N]==-1) return total0;
	else if (staterow[N]==false) {
		return total0-query0(lastrow[N]);
	} else {
		int x=total1-query1(lastrow[N]);
		return m-x;
	}
}


