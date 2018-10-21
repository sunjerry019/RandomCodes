#include "ballgame.h"
#include <cstdio>
using namespace std;

int main() {
	int N, L, D;
	scanf("%d%d%d", &N, &L, &D);
	int H[N], C[N];
	for (int i = 0; i < N; ++i) scanf("%d%d", &H[i], &C[i]);
	printf("%d\n", ballgame(N, L, D, H, C));
}
