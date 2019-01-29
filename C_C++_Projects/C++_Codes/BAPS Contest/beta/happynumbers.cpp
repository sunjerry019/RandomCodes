#include <bits/stdc++.h>

using namespace std;
int state[10];
int state2[10];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
	for(int i=0;i<10;i++){
		state[i]=10-i;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<10;j++){
			state2[j]=state[j];
		}
		for(int j=0;j<10;j++){
			int total=0;
			for(int k=j;k<10;k++){
				total+=state2[k];
				total%=1000000007;
			}
			state[j]=total;
		}
	}
	cout<<state[0]<<"\n";
	return 0;
}
