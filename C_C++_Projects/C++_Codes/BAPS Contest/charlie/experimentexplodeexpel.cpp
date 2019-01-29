#include<bits/stdc++.h>
using namespace std;
char str[20000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tc;
	cin>>str>>tc;
	int len;
	len = strlen(str);
	int mods[15];
	int rmods[15]={0};
	int imods[15]={0};
	for(int i = 0;i<tc;i++)
	{
		cin>>mods[i];
		imods[i] = 1;
	}
	for(int j = len-1;j>=0;j--)
	{
		for(int i = 0;i<tc;i++)
		{
			rmods[i] += (str[j]-'0')*imods[i];
			rmods[i] %= mods[i];
			imods[i] = ((imods[i]<<1)+(imods[i]<<3))%mods[i];
		}
	}
	for(int i = 0;i<tc;i++)
	{
		cout<<rmods[i]<<'\n';
	}
	return 0;
}
