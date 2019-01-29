#include <bits/stdc++.h>
using namespace std;

int n, arr[2005][2005];

int main () {
	scanf("%d", &n);
	int cx = 0, cy = 0;
	arr[cx][cy] = 1;
	bool dir = true;
	for (int i = 0; i < n*n; i++) {
		arr[cx][cy] = i+1;
		if (dir && cy == n-1) {
			dir = false;
			cx++;
		}
		else if (!dir && cx == n-1) {
			dir = true;
			cy++;
		}
		else if (dir && cx == 0) {
			dir = false;
			cy++;
		}
		else if (!dir && cy == 0) {
			dir = true;
			cx++;
		}
		else if (dir) {
			cx--;
			cy++;
		} else {
			cx++;
			cy--;
		}
		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) printf("%d ", arr[i][j]);
		printf("%d\n", arr[i][n-1]);
	}
}
