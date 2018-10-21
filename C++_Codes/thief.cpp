#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100005];
int main() {
    int n;
    scanf("%d\n",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);
    int lis=0;
    int l[100005] = {0};
	for(int i = 0;i<n;i++)
	{
		int position;
		position = lower_bound(l,l+lis,-a[i].second)-l;
		l[position] = -a[i].second;
		lis=max(lis,position+1);
	}
    printf("%d\n", lis);
    return 0;
}