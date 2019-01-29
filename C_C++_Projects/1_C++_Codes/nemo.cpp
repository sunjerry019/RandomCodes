#include <bits/stdc++.h>
#include <tuple>
using namespace std;
class UnionFind{
	private:vector<int> p, rank;
	public:
	UnionFind(int N){rank.assign(N,0);
	p.assign(N,0);for(int i = 0;i<N;i++)
	p[i]=i;}
	int findSet(int i){return (p[i]==i)?i:(p[i]=findSet(p[i]));}
	bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
	void unionSet(int i,int j)
	{
		if(!isSameSet(i,j))
		{
			int x=findSet(i),y=findSet(j);
			if(rank[x]>rank[y])p[y]=x;
			else{p[x]=y;if(rank[x]==rank[y])rank[y]++;}
		}
	}};
vector<pair<int, int> > query;
vector<tuple<int, int, int, int, int> >all;
int main()
{
    int n,e;
    scanf("%d%d",&n,&e);
    int maxo=0;
    int minc=INT_MAX;
    for(int i = 0;i<e;i++)
    {
        int a,b,o,c;
        scanf("%d%d%d%d",&a,&b,&o,&c);
        maxo = max(maxo,o);
        minc = min(minc,c);
        all.push_back(tuple<int, int, int, int, int>(o,-2000000000,a,b,0));
        all.push_back(tuple<int, int, int, int, int>(c,2000000000,a,b,1));
    }
    int tc;
    scanf("%d",&tc);
    for(int i = 0;i<tc;i++)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        all.push_back(tuple<int, int, int, int, int>(t,i,x,y,2));
    }
    sort(all.begin(),all.end());
    UnionFind ufds1(n+1);
    for(int i = 0;i<all.size();i++)
    {
        if(get<4>(all[i])==1)break;
        else if(get<4>(all[i])==0)
        {
            ufds1.unionSet(get<2>(all[i]),get<3>(all[i]));
        }
        else if(get<4>(all[i])==2)
        {
            query.push_back(make_pair(get<1>(all[i]),ufds1.isSameSet(get<2>(all[i]),get<3>(all[i]))));
        }
    }
    UnionFind ufds2(n+1);
    for(int i = all.size()-1;i>=0;i--)
    {
        if(get<0>(all[i])<=minc || get<4>(all[i])==0 || (get<0>(all[i])<=minc && get<4>(all[i])==2))break;
        else if(get<4>(all[i])==1)
        {
            ufds2.unionSet(get<2>(all[i]),get<3>(all[i]));
        }
        else if(get<4>(all[i])==2)
        {
            query.push_back(make_pair(get<1>(all[i]),ufds2.isSameSet(get<2>(all[i]),get<3>(all[i]))));
        }
    }
    sort(query.begin(),query.end());
    printf("%c\n",query[0].second?'Y':'N');
    for(int i = 1;i<query.size();i++)
    {
        if(query[i].first!=query[i-1].first)
        printf("%c\n",query[i].second?'Y':'N');
    }
    return 0;
}