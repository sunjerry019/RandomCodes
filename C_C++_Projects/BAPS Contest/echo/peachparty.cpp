#include "peachparty.h"
#include <bits/stdc++.h>
#define INF 2000000000
#define mp make_pair
#define ll long long
using namespace std;
#define ep 10E-6
void sharepeach(long long a, long long b, long long c, long long p, long long f, long long* out){
	for(int i = 0; i < 5; i++) out[i] = -1;
	ll peaches = p;
	peaches -= f;
	ll xmult = 1 + b + a;
	ll ymult = 1 + c;
	for(ll i = 1; i <= floor(peaches/xmult); i++){
		ll remainder = peaches - i*xmult;
		if(remainder <= 0) break;
		if(floor(remainder/ymult) * ymult == remainder){
			out[0] = remainder/ymult;
			out[1] = i;
			out[2] = a*i;
			out[3] = b*i;
			out[4] = c * out[0];
		}
	}
}

int maxpeach(int n, int m, int d, const int g[][1000]){
	int a[1000][1000];
	memset(a,0,sizeof a);
	for(int i = 0; i < m; i++) a[0][i] = g[0][i];
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = -d; k <= d; k++){
				if(j+k < 0 || j+k >= m) continue;
				a[i][j+k] = max(a[i][j+k],a[i][j+k] + g[i][j]);
			}
		}
	}
	int high = 0;
	for(int i = 0; i < m; i++){
		high = max(high,a[n-1][i]);
	}
	return high;
}

void peachroutes(int n, int m, int d, const int g[][1000], int* out) {
    
}
