#include <bits/stdc++.h>

using namespace std;
vector<int> adjlist[1000005];
int bananas[1000005];
int dparr[2][1000005];
int dp(int node,int type,int parent)
{
    if(dparr[type][node]!=-1)return dparr[type][node];
    if(type==0)
    {
        int sum=0;
        for(int i = 0;i<adjlist[node].size();i++)
        {
            if(adjlist[node][i]!=parent)
            sum+=max(dp(adjlist[node][i],0,node),dp(adjlist[node][i],1,node));
        }
        return dparr[type][node]=sum;
    }
    else
    {
        int sum=0;
        for(int i = 0;i<adjlist[node].size();i++)
        {
            if(adjlist[node][i]!=parent)
            sum+=dp(adjlist[node][i],0,node);
        }
        return dparr[type][node]=(sum+bananas[node]);
    }
}
vector<int> mis;
int printdp(int node,int type,int parent)
{
    if(type==0)
    {
        int sum=0;
        for(int i = 0;i<adjlist[node].size();i++)
        {
            if(adjlist[node][i]!=parent)
            {
                int f = dp(adjlist[node][i],0,node);
                int s = dp(adjlist[node][i],1,node);
                if(f>s)
                {
                    sum+=f;
                    printdp(adjlist[node][i],0,node);
                }
                else
                {
                    sum+=s;
                    mis.push_back(adjlist[node][i]);
                    printdp(adjlist[node][i],1,node);
                }
            }
        }
        return sum;
    }
    else
    {
        int sum=0;
        for(int i = 0;i<adjlist[node].size();i++)
        {
            if(adjlist[node][i]!=parent)
            sum+=printdp(adjlist[node][i],0,node);
        }
        return sum+bananas[node];
    }
}
int main()
{
    memset(dparr,-1,sizeof(dparr));
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    for(int i = 0;i<n;i++)scanf("%d",&bananas[i]);
    int a = dp(0,0,-1);
    int b = dp(0,1,-1);
    if(a>b)
    {
        printdp(0,0,-1);
        printf("%d\n%d\n",a,mis.size());
        for(int i = 0;i<mis.size();i++)
        {
            printf("%d",mis[i]);
            if(i!=mis.size()-1)printf(" ");
        }
        printf("\n");
    }
    else
    {
        printdp(0,1,-1);
        mis.push_back(0);
        printf("%d\n%d\n",b,mis.size());
        for(int i = 0;i<mis.size();i++)
        {
            printf("%d",mis[i]);
            if(i!=mis.size()-1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
