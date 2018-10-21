#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int dp[50005], h[50005];
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &h[i]);
    }
    dp[0] = 0;
    h[0] = 1000000000;
    h[n+1]=0;
    for(int i = 1; i <= (n+1); i ++)
    {
        int mini = 10000000;
        for(int j=0;j<i;j++)
        {
            if(h[j] >= h[i])
            {
                mini = min(dp[j] + (i-j)*(i-j),mini);
            }
        }
        dp[i]=mini;
    }
    printf("%d\n", dp[n+1]);
    return 0;
}
