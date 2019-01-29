#include <bits/stdc++.h>
using namespace std;
int dist[1005][1005], temp[1005][1005];
int main()
{
	int t,r,q;
	scanf("%d%d%d",&t,&r,&q);
	t+=5;
	for(int i = 0;i<=t+1;i++)for(int j = 0;j<=t+1;j++)temp[i][j] = 1000000000;
	for(int i = 0;i<r;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		temp[a][b] = min(temp[a][b],c);
		temp[b][a] = min(temp[b][a],c);
	}
	for(int i = 0;i<=t+1;i++)temp[i][i] = 0;
	for(int i=0;i<=t+1;i++) for(int j=0;j<=t+1;j++) dist[i][j] = temp[i][j];
	for(int k = 0;k<=t+1;k++)
	for(int i = 0;i<=t+1;i++)
	for(int j = 0;j<=t+1;j++)
	{
		dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	}
	for(int i = 0;i<q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",min(dist[a][b],dist[b][a]));
	}
	int t1,t2,l,p;
	scanf("%d%d%d%d",&t1,&t2,&l,&p);
	temp[t1][t2] = min(temp[t1][t2],l);
	temp[t2][t1] = min(temp[t2][t1],l);
	for(int i=0;i<=t+1;i++) for(int j=0;j<=t+1;j++) dist[i][j] = temp[i][j];
	for(int k = 0;k<=t+1;k++)
	for(int i = 0;i<=t+1;i++)
	for(int j = 0;j<=t+1;j++)
	{
		dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	}
	for(int i = 0;i<p;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",min(dist[a][b],dist[b][a]));
	}
	return 0;
}
