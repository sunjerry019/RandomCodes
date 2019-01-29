#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
int grid[2000][2000];
int main() {
	int x=0,y=0,c=1,n;
	scanf("%d",&n);
	grid[0][0]=c;
	while (c<=n*n) {
		if (y==n-1) {
			x++,c++;
		} else {
			y++,c++;
		}
		grid[x][y]=c;
		while(y>0&&x<n-1) {
			x++,y--,c++;
			grid[x][y]=c;			
		}
		if (x==n-1) {
			y++,c++;
		} else {
			x++,c++;
		}
		grid[x][y]=c;
		while(x>0&&y<n-1) {
			x--,y++,c++;
			grid[x][y]=c;			
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d%c",grid[i][j],(j==n-1)?'\n':' ');
		}
	}
}
