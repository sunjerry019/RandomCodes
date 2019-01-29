#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, v;
    scanf("%d%d", &n, &v);
    vector<int> values;
    values.push_back(0);
    for(int i=0;i<v;i++)
    {
        values.push_back(1000000000);
    }
    for(int i=0;i<n;i++)
    {
        int currCoin;
        scanf("%d", &currCoin);
        for(int j=0;j<=v;j++)
        {
            if(j+currCoin <= v && values[j] != 1000000000) values[j + currCoin] = min(values[j + currCoin], (values[j] + 1));
        }
    }
    values[v] = (values[v] == 1000000000)?-1:values[v];
    printf("%d\n", values[v]);
    return 0;
}
