#include "graphcraft.h"
#include <bits/stdc++.h>

using namespace std;

int multiply(int item, int factor, int it[])
{
    int sz = it.size();
    for(int i=0;i<sz;i++)
    {
        it[i] = (it[i]%1000000007 * factor%1000000007)%1000000007;
    }
    return it;
}


int graphcraft(int n, int c, vector< pair<int, int> > v[]) {

    int visited[n];
    int items[n][n] = {0};

    //make sense of the data
    for(int i=1;i<n;i++)
    {
        int sz = v[i].size();
        for(int j=0;j<sz;j++)
        {
            //for item i, I need vi.second of vi.first
            items[i][v[i].first] = v[i].second;
        }
    }

    //starting from item c;
    visited[c] = 1;
    for(int i = 1; i < n; i++)
    {
        if(items[c][i] > 0) items[i] = multiply(i, items[c][i], items[i]);
    }

    return 0;
}
