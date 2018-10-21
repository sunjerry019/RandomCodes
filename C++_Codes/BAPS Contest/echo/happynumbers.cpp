#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
#define M 1000000007ll
int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
vector<int> x,y;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=9;i++) y.pb(i);
	for (int i=0;i<9;i++) x.pb(n-i+9);
	for (int i=0;i<9;i++){
		for (int j=0;j<9;j++) {
			int g=gcd(x[j],y[i]);
			x[j]/=g;
			y[i]/=g;
		}
	}
	ll ans=1ll;
	for (int i=0;i<9;i++) {
		ans*=(ll)x[i];
		ans%=M;
	}
	printf("%lld\n",ans);
	
}
