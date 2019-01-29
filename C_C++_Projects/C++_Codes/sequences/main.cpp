#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int lis[1000005] = {0};
    int l= 0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d", &tmp);
        int pos = lower_bound(lis, lis+l, tmp)-lis;
        lis[pos] = tmp;
        l = max(l, pos+1);
    }
    printf("%d", l);
}
