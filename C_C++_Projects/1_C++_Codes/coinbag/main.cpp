#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int valatweight[100005] = {-1};
    valatweight[0] = 0;
    for(int i=0;i<n;i++)
    {
        int w,v;
        scanf("%d%d", &w, &v);
        for(int j=m;j>=0;j--)
        {
            if(valatweight[j] > -1)
            {
                if((j+w) <= m) valatweight[j+w] = max(valatweight[j+w], valatweight[j] + v);
            }
        }
    }
    printf("%d", valatweight[m]);
    return 0;
}
