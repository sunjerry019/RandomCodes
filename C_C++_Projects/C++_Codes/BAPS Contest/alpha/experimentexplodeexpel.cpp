#include <iostream>

using namespace std;

int main() {
	
	long long n;
	long long i, m, tc;
	
	scanf("%lld%lld", &n, &tc);
	for (i = 0; i < tc; i++) {
		scanf("%lld", &m);
		cout << n%m << "\n";
	}
	
	
	return 0;
}
