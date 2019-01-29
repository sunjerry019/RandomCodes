#include "funfair.h"
#include <bits/stdc++.h>

using namespace std;

long long int fw[100009][3];
int cv[100009];
int gN;

void update(int x,int v,int i){
	for(;x<100005;x+=x&(-x)){
		fw[x][i]+=(long long)v;
	}
}

long long int q(int x,int i){
	long long int res=0;
	for(;x;x-=x&(-x)){
		res+=fw[x][i];
	}
	return res;
}

long long int rsum(int a,int b,int i){
	if(a==0)return q(b,i);
	return q(b,i)-q(a-1,i);
}

void init(int N, int V[]) {
	for(int i=0;i<N;i++){
		update(i+1,V[i],0);
		update(i+1,V[i]*(i+1),1);
		update(i+1,V[i]*(-(i+1)),2);
		cv[i+1]=V[i];
	}
	gN=N;
	/*for(int i=1;i<=gN;i++){
		printf("%lld ",q(i,0));
	}
	printf("\n");
	for(int i=1;i<=gN;i++){
		printf("%lld ",q(i,2));
	}printf("\n");*/
}

void changeValue(int P, int V) {
	update(P+1,(V-cv[P+1]),0);
	update(P+1,(V-cv[P+1])*(P+1),1);
	update(P+1,(V-cv[P+1])*(-(P+1)),2);
	cv[P+1]=V;
	/*for(int i=1;i<=gN;i++){
		printf("%lld ",q(i,0));
	}
	printf("\n");
	for(int i=1;i<=gN;i++){
		printf("%lld ",q(i,1));
	}
	printf("\n");*/
}
long long visitStalls(int B, int E, int K, long long G) {
	if(B>E){
		long long int csum;
		int st=E,en=B;
		while(st<en){
			int M=(st+en)/2;//B to M
			csum=rsum(M+1,B+1,2)*(long long)K+(long long)((B+1)*(K)+1)*rsum(M+1,B+1,0);
			//printf("%d %d %lld\n",st,en,csum);
			if(csum>G){
				st=M+1;
			}
			else{
				en=M;
			}
		}
		return (rsum(st+1,B+1,2)*(long long)K+(long long)((B+1)*(K)+1)*rsum(st+1,B+1,0));
	}
	long long int csum;
	int st=B,en=E;
	while(st<en){
		int M=(st+en+1)/2;//B to M
		csum=rsum(B+1,M+1,1)*(long long)K-(long long)((B+1)*K-1)*rsum(B+1,M+1,0);
		//printf("%d %d %lld\n",st,en,csum);
		if(csum>G){
			en=M-1;
		}
		else{
			st=M;
		}
	}
	return (rsum(B+1,st+1,1)*(long long)K-(long long)((B+1)*K-1)*rsum(B+1,st+1,0));
}