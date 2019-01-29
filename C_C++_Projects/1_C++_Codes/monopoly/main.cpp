#include <bits/stdc++.h>

using namespace std;

int getidx(int q, char w, int e)
{
    int r = (w - 'A')*(q-1) + e;
    if(w == 'D' && e == (q-1)) r = 0;
    return r;
}

int main()
{
    int n;
    scanf("%d", &n);
    int hexa[400005] = {0};
    hexa[0] = 1;
    hexa[1] = 1;
    hexa[2] = 2;
    hexa[3] = 4;
    hexa[4] = 8;
    hexa[5] = 16;
    hexa[6] = 32;
    for(int i=7;i<400005;i++)
    {
        for(int j = 1; j < 7; j++)
        {
            hexa[i] = (hexa[i]%1000000007 + hexa[i-j]%1000000007)%1000000007;
        }
    }
    for(int i=0;i<n;i++)
    {
        int a, c;
        char b;
        scanf("%d%s%d",&a,&b,&c);
        int idx = getidx(a, b, c);
        printf("%d\n", hexa[idx]);
    }
    return 0;
}
