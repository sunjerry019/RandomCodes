#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	int n,m;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int arr[n+1][m+1];
	memset(arr, 0, sizeof(arr));
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			cin>>arr[i][j];
		}
	}
	int sum[n+1][m+1];
	memset(sum,0,sizeof(sum));
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+arr[i][j];
		}
	}
	int art=0;
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			for (int k=1; k<=m; k++) {
				for (int l=k; l<=m; l++) {
					if (sum[j][l]-sum[j][k-1]-sum[i-1][l]+sum[i-1][k-1]==0)
					{
						art=max(art,(j-i+1)*(l-k+1));
					}
				}
			}
		}
	}
	cout<<art<<endl;
}
