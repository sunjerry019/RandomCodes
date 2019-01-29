#include <bits/stdc++.h>
using namespace std;
bitset<500005> visited;
vector <pair<int,int> > node[500005];
int dist[3005][3005];
int curr;
int m=0;

void dfs(int v)
{
	visited[v]=true;
	for (int i=0; i<(int)node[v].size(); i++)
	{
		if (!visited[node[v][i].second]) {
		dist[curr][node[v][i].second]=dist[curr][v]+node[v][i].first;
		m=max(m,dist[curr][node[v][i].second]);
		dfs(node[v][i].second);
		}
	}
}

int main() {
	//freopen("hi.txt","r",stdin);
	int n,t,f;
	scanf("%d%d%d",&n,&t,&f);
	int a,b,c;
	for(int i=0;i<t;i++){
		scanf("%d%d%d",&a,&b,&c);
		node[a].push_back(make_pair(-c,b));
		node[b].push_back(make_pair(-c,a));
	}
	for(int i=0;i<f;i++){
		scanf("%d%d%d",&a,&b,&c);
		node[a].push_back(make_pair(c,b));
		node[b].push_back(make_pair(c,a));
	}
	if(n>3000){
		int start;
		for(int i=0;i<n;i++){
			if(node[i].size()==1){
				start=i;
				break;
			}
		}
		int arr[n];
		visited.reset();
		for (int i=0; i<n-1; i++)
		{
			for (int j=0; j<node[start].size(); j++)
			{
				if (!visited[node[start][j].second]) {
					visited[node[start][j].second]=true;
					arr[i]=node[start][j].first;
					start=node[start][j].second;
				}
			}
		}
		int currmax=0;
		int sum=0;
		for(int i=0;i<n-1;i++){
			sum+=arr[i];
			if (sum<0) sum=0;
			currmax=max(currmax,sum);
		}
		printf("%d",currmax);
		
		return 0;
	}
    for(int i=0;i<n;i++){
		visited.reset();
		dist[i][i]=0;
		curr=i;
		dfs(i);
	}
	printf("%d\n", m);
}
