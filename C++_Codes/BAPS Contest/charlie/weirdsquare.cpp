#include <bits/stdc++.h>
#define INF 1000000000
#define MOD 1000000007
/*typedef pair<int, int> ii;
typedef pair<int, ii> iii;*/
typedef long long ll;
using namespace std;
int n, i, j, m, best, t1, t2;
int arr[2000][2000];
int main(void) {
	scanf("%d", &n);
	i=1;
	j=0;
	int k=0;
	bool up = true;
	while (i<=n*n) {
		arr[j][k] = i;
		if (up) {
			if (k == 0) {
				if (j == n-1) {
					k++;
				} else {
					j++;
				}
				up = false;
			} else if (j == n-1) {
				k++;
				up = false;
			} else {
				j++;
				k--;
			}
		} else {
			if (j == 0) {
				if (k == n-1) {
					j++;
				} else {
					k++;
				}
				up = true;
			} else if (k == n-1) {
				j++;
				up = true;
			} else {
				k++;
				j--;
			}
		}
		i++;
	}
	for (i=0;i<n;i++) {
		printf("%d", arr[0][i]);
		for (j=1;j<n;j++) {
			printf(" %d", arr[j][i]);
		}
		printf("\n");
	}
}
