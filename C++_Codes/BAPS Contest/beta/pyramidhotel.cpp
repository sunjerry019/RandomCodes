#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,c=1;
	cin >> a;
	int b[a+2],dp[a+2];
	for (int i=1;i<=a;i++)cin>>b[i];
	dp[a]=1;
	for(int i=1;i<a;i++){
		dp[a-i]=min(dp[a-i+1]+1,b[a-i]);
		c=max(c,dp[a-i]);
	}
	cout << c;
}
