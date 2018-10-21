#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    int arr[n];
    int start = 0, longest = 0;
    long long int sum = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(sum <= p) longest = max(longest, i-start+1);
        else
        {
            while(sum > p)
            {
                sum -= arr[start];
                start ++;
            }
        }
    }
    printf("%d\n", longest);
    return 0;
}
