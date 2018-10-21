#include <bits/stdc++.h>
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
int tmp[1000005];
int n,arr[100005];
int mid(int x,int y){return (x+y)/2;}
ll ans=0;
void mergesort(int b, int e) {
	if (e==b) return;
	int m = mid(b,e);
	mergesort(b,m);
	mergesort(m+1,e);
	int x=b,y=m+1,h=b;
	while(y<=e&&x<=m) {
		if (arr[x]<=arr[y]) {
			tmp[h] = arr[x];
			x++,h++;
		} else {
			tmp[h] = arr[y];
			y++,h++;
			ans += m-x+1;
		}
	}
	while(x<=m) {
		tmp[h] = arr[x];
		x++,h++;
	}
	while(y<=e) {
		tmp[h] = arr[y];
		y++,h++;
	}
	for (int i=b;i<=e;i++) {
		arr[i]=tmp[i];
	}
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		if (arr[i]>=50) arr[i]=1;
		else arr[i]=-1;
		if (i) arr[i]+=arr[i-1];
	}
	mergesort(0,n-1);
	for (int i=0;i<n;i++) if (arr[i]<0) ans++;

	printf("%lld\n",ans);
}
