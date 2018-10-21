#include <cstdio> //the compiler at home doesn't let me use <bits/stdc++.h>, so
#include <utility>
#include <algorithm>
#define LARGE_ENOUGH 2222222
#define FOR(x,y) for(lld y(0);y<x;y++)
#define FOR3(z,x,y) if(x>z)for(lld y(z);y<x;y++)
//headers are shorter this time round because it's a christmas miracle or something like that
using namespace std;
typedef long long lld;

char S[LARGE_ENOUGH];
lld N,M;
int main(){
	scanf("%lld",&N);
	scanf("%lld",&M);
	FOR(N,i){
		scanf("%s",S+M*i);
	}
	if (N^1){
		FOR(N,i){
			FOR(M,j){
				switch(S[i*M+j]){ //man it's been at least a year since I used a switch case let's hope I don't screw up
					case '.':S[i*M+j]=0;
					break;
					case 'D':S[i*M+j]=1;
					break;
					case 'v':S[i*M+j]=2;
					break;
					case '^':S[i*M+j]=4;
					break;
					case '<':S[i*M+j]=8;
					break;
					case '>':S[i*M+j]=16;
					break;
					default: printf("%d\n",(int)S[i*M+j]);
				}
			}
		}
		lld T=max(N,M);
		FOR(T,t){

			FOR(N,i){
				FOR(M,j){
					if(S[i*M+j]==1){
//						printf("prop %lld %lld\n",i,j);
						if(i&&S[i*M+j-M]==0)S[i*M+j-M]=1;
						if(j&&S[i*M+j-1]==0)S[i*M+j-1]=1;
						if(i<N-1&&S[i*M+j+M]==0)S[i*M+j+M]=33;
						if(j<M-1&&S[i*M+j+1]==0)S[i*M+j+1]=33;
					}
					S[i*M+j]&=31;
				}
			}
			FOR(N,i){
				FOR(M,j){
					//then you do the arrow thing
					if(S[i*M+j]&4){
						S[i*M+j]-=4;
						if(i){
							S[i*M+j-M]^=S[i*M+j-M]&1;
							S[i*M+j-M]|=4;
						}
					}
					if(S[i*M+j]&8){
						S[i*M+j]-=8;
						if(j){
							S[i*M+j-1]^=S[i*M+j-1]&1;
							S[i*M+j-1]|=8;
						}
					}
					lld i2=N-1-i,j2=M-1-j;
					if(S[i2*M+j2]&2){
						S[i2*M+j2]-=2;
						if(i2<N-1){
							S[i2*M+j2+M]^=S[i2*M+j2+M]&1;
							S[i2*M+j2+M]|=2;
						}
					}
					if(S[i2*M+j2]&16){
						S[i2*M+j2]-=16;
						if(j2<M-1){
							S[i2*M+j2+1]^=S[i2*M+j2+1]&1;
							S[i2*M+j2+1]|=16;
						}
					}
				}
			}

			//BEGIN DEBUGGING CODE
			// FOR(N,i){
			// 	FOR(M,j){
			// 		printf("%02d ",(int)S[i*M+j]);
			// 	}
			// 	printf("\n");
			// }
			// printf("\n");
			//END DEBUGGING CODE
		}
		char ans=0;
		FOR(N,i){
			FOR(M,j){
				ans|=S[i*M+j];
			}
		}
		printf("%c\n",ans?'Y':'N');
	}else{
		bool derekkuflag=false;
		FOR(M,i){
			if(S[i]=='>'&&!derekkuflag){
				printf("N\n"); return 0;
			}
			if(S[i]=='D'){
				derekkuflag=1;
			}
			if(S[i]=='<'&&derekkuflag){
				printf("N\n"); return 0;
			}
		}
		printf("Y\n");
	}
}
