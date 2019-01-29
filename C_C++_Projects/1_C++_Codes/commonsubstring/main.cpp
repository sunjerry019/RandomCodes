#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[4001], b[4001];
    scanf("%s", &a);
    scanf("%s", &b);
    short lena = strlen(a), lenb=strlen(b);
    short l[lena][lenb];
    short z = 0;
    for(int i = 0;i<lena;i++)
    {
        for(int j=0;j<lenb;j++)
        {
            if(a[i] == b[j])
            {
                if(!i || !j) l[i][j] = 1;
                else l[i][j] = l[i-1][j-1] + 1;
                z = max(z, l[i][j]);
            }
            else
            {
                l[i][j] = 0;
            }
        }
    }
    printf("%hd", z);
    return 0;
}
