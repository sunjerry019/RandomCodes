#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
int n,a[1000005],mem[1000005];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	mem[n-1]=1;
	for (int i=n-2;i>=0;i--) {
		if (a[i]>mem[i+1]) mem[i]=mem[i+1]+1;
		else mem[i]=a[i];
	}
	printf("%d\n",*max_element(mem,mem+n));
}
