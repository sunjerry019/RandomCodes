#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    int sum = 0, maxi =0;
    for(int i=0;i<n;i++)
    {
        char c = getchar();
        if(c=='M') c = -2;
        else c -= '0';

        sum += c;
        sum=sum<0?0:sum;
        maxi=max(sum,maxi);
    }
    printf("%d", maxi);
    return 0;
}
