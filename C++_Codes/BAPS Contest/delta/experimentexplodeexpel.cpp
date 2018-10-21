#include<bits/stdc++.h>
#define LARGE_ENOUGH 1<<24
using namespace std;
typedef long long lld;
char BIGINT[LARGE_ENOUGH];
int l,tc;lld ans,smallint;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> BIGINT;
	//scanf("%s",BIGINT);
	l=strlen(BIGINT);
	//scanf("%d",&tc);
	cin >> tc;
	for(int t=0;t<tc;t++){
		ans=0ll;
		cin >> smallint;
		//scanf("%lld",&smallint);
		if(smallint==1){/*puts("0");*/cout<<"0\n";continue;}
		lld multiplier=1;
		for(int i=l-1;i>=0;i--){
			ans+=multiplier*(BIGINT[i]-'0');
			ans%=smallint;
			multiplier*=10;
			multiplier%=smallint;
		}
		cout << ans << "\n";
		//printf("%lld\n",ans);
	}
}

