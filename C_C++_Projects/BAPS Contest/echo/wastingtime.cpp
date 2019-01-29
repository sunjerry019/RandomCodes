#include <iostream>
#include <stdlib.h>
using namespace std;

long long combi(long long a, long long b){
	long long answer = 1;
	if (a == 0) return 1;
	if (b == 0 || b == a) return 1;
	for (long long i = 0; i < b; i++){
		answer = answer * (a - i);
		answer = answer/(i + 1);
		answer = answer%1000000007;
	}
	
	return answer;
}

long long test(long long a, long long b, long long c, long long d){
	long long answer = 1;
	answer = answer*combi(a + b + c + d, a);
	answer = answer%1000000007;
	answer = answer*combi(b + c + d, b);
	answer = answer%1000000007;
	answer = answer*combi(c + d, c);
	answer = answer%1000000007;
	return answer;
}

int main(){
	
	long long tc;
	cin >> tc;
	
	long long n, a, b;
	long long totalup;
	long long totaldown;
	long long totalright;
	long long totalleft;
	long long answer;
	
	for (long long i = 0; i < tc; i++){
		cin >> n >> a >> b;
		if ((llabs(a) + llabs(b))%2 == 1){
			cout << 0 << endl;
			continue;
		}
		
		if (llabs(a) + llabs(b) > 2*n){
			cout << 0 << endl;
			continue;
		}
		
		totalup = 0;
		totaldown = 0;
		totalleft = 0;
		totalright = 0;
		answer = 0;
		
		if (a < 0 && b < 0){
			totalleft = 0 -(a);
			totaldown = 0 -(b);
			
			for (long long i = 0; i <= n - ((totalleft + totaldown)/2); i++){
				answer = answer + test(totalup + i, totaldown + i, totalleft + n - ((totalleft + totaldown)/2) - i, totalright + n - ((totalleft + totaldown)/2) - i);
				answer = answer % 1000000007;
			}
			
			cout << answer << endl;
			continue;
			
		} else if (a < 0 && b >= 0){
			
			totalleft = -(a);
			totalup = b;
			
			for (long long i = 0; i <= n - ((totalleft + totalup)/2); i++){
				answer = answer + test(totalup + i, totaldown + i, totalleft + n - ((totalleft + totalup)/2) - i, totalright + n - ((totalleft + totalup)/2) - i);
				answer = answer % 1000000007;
			}
			cout << answer << endl;
			continue;
			
			
		} else if (a >= 0 && b < 0){
			
			totalright = a;
			totaldown = -(b);
			
			for (int i = 0; i <= n - ((totalright + totaldown)/2); i++){
				answer = answer + test(totalup + i, totaldown + i, totalleft + n - ((totalright + totaldown)/2) - i, totalright + n - ((totalright + totaldown)/2) - i);
				answer = answer % 1000000007;
			}
			
			cout << answer << endl;
			continue;
			
		} else {
			
			totalright = a;
			totalup = b;
			
			for (long long i = 0; i <= n - ((totalright + totalup)/2); i++){
				answer = answer + test(totalup + i, totaldown + i, totalleft + n - ((totalright + totalup)/2) - i, totalright + n - ((totalright + totalup)/2) - i);
				answer = answer % 1000000007;
			}
			
			cout << answer << endl;
			continue;
			
		}
		
	}
	
	
	
	
}