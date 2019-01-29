#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
#define ii pair<int,int>
string f(int k) {
	string x;
	if (k==2) return "2";
	if (k==1) return "2(0)";
	if (k==0) return "0";
	for (int i=20;i>=2;i--) {
		if (k&(1<<i)) {
			x+="2("+f(i)+")+";
		}
	}
	if (k&2) x+="2+";
	if (k&1) x+="2(0)+";
	x.erase(sz(x)-1);
	return x;
}
int main() {
	int n;
	cin>>n;
	string s=f(n);
	cout<<s<<endl;
}

