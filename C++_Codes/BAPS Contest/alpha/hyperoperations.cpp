#include <cstdio>


long long repsq(int a,int b,int m) {
	long long res = 1;
	//printf("%d %d\n",b,res);
	while(b) {
		if(b&1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		b>>=1;
		//printf("%d %d\n",b,res);
	}
	return res;
}
long long reptet(int a,int b,int m) {
	
	/*long long k = 1;
	long long t = 1;
	while(true) {
		t *= a;
		t %= m;
		if(t==0 || t==1)
			break;
		k++;
		printf("%d %d\n",t,k);
	}*/
	
	long long res = 1;
	while(b) {
		/*
		if(t==0&&res>=k) {
			res = 1;
			continue;
		} else if(t==1) {
			res %= k;
		}*/
		res = repsq(a,res,m);
		b--;
	}
	return res;
}
int main() {
	int tc;
	scanf("%d",&tc);
	for(int i=0;i<tc;i++) {
		long long t,a,b,m;
		scanf(" %lld %lld %lld %lld",&t,&a,&b,&m);
		long long res;
		switch(t) {
		case 1:
			res = (a+b)%m;
			break;
		case 2:
			res = (a*b)%m;
			break;
		case 3:
			res = (int)repsq(a,b,m);
			break;
		case 4:
			res = (int)reptet(a,b,m);
			break;
		default:
			res = 1;
		}
		res %= m;
		printf("%lld\n",res);
	}
	return 0;
}
