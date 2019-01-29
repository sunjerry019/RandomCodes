#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!(i%2))
            {
                if(!(j%2)) printf("o");
                else printf("x");
            }
            else
            {
                if(!(j%2)) printf("x");
                else printf("o");
            }
        }
        printf("\n");
    }
    return 0;
}
