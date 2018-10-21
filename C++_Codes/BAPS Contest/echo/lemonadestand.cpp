#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int coin[1000];
int memo[5000];

int dp(int a){
	
	if (a >= n + 1) return 0;
	
	if (memo[a] != 0){
	    return memo[a];
	}
	
	int maxi = 1000000000;
	
	for (int i = 0; i < k; i++){
		if (coin[i] <= a) {
			maxi = min(maxi, 1 + dp(coin[i] + a));
		} else {
			break;
		}
	}
	
	return memo[a] = maxi;
	
}


int main(){
	
	cin >> n >> k;
	
	for (int i = 0; i < k; i++){
		cin >> coin[i];
	}
	
	sort(coin, coin + k);
	
	cout << dp(1) << endl;
	
}
