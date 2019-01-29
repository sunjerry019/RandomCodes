#include <bits/stdc++.h>
using namespace std;
long long arr[1000000];
int r(int x){
    long long ans;
	if(x==0)
	ans=1;
	else if(x<1000000&&arr[x]!=-1)
	return arr[x];
	else if(x%2==1)
	ans=r(x/2);
    else ans=r(x/2)+r(x/2-1);
    if(x<1000000)
    arr[x]=ans;
    return ans;
}
int main(){
	int n,tc;
	scanf("%d %d",&n,&tc);
	int i,j;
	for(int i=0;i<1000000;i++){
	arr[i]=-1;
	}
	//		printf("%d",r(4));

	for(int i=0;i<1000000;i++){
		r(i);
	}
	for (int ii=0;ii<tc;ii++){
		scanf("%d %d",&i,&j);
		if(i==j)
		printf("%d\n",0);
		else if(i==0)
		printf("%d\n",(int)floor(sqrt(r(j))));
		else if(r(j)-r(i)>0)
		printf("%d\n",(int)floor(sqrt(r(j)-r(i))));
		else
		printf("%d\n",(int)-floor(sqrt(r(i)-r(j))));
	}
}
