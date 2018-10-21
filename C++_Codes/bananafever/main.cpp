#include <bits/stdc++.h>

using namespace std;

vector<int> adjlist[1000005];
int bananas[1000005];
int n;
int maxbananas = 0, current=0;

int main()
{
    scanf("%d", &n);
    for(int i=0;i<(n-1);i++)
    {
        int temp1, temp2;
        scanf("%d%d", &temp1, &temp2);
        adjlist[temp1].push_back(temp2);
        adjlist[temp2].push_back(temp1);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d", &bananas[i]);
    }
    for(int i=0;i<n;i++)
    {
        current += bananas[i];
        int sz = adjlist[i].size();
        for(int j=0;j<n;j++)
        {
            if(j != i)
            {
                if((upper_bound(adjlist[i].begin(), adjlist[i].end(), j) - adjlist[i].begin()) == sz) current += bananas[j];
            }
        }
        maxbananas = max(maxbananas, current);
    }

    printf("%d\n", maxbananas);
    return 0;
}
