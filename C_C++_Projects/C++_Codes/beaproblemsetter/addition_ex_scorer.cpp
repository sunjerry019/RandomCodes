#include <bits/stdc++.h>

using namespace std;
int t, ok;
int cnt = 0;
char c;
double score = 0.0;
int main () {
	scanf("%d%d", &t, &ok);
	if (ok != 100) printf("0\n");
	else {
		FILE* f = fopen("ans.cpp", "r");
		while (fscanf(f, "%c", &c) == 1)
		{
			if(c == ';') 
			{
				score = -1;
				break;
			}
			++cnt;
		}
		cnt --;
		//printf("%d\n", cnt);
		if(score > -1)
		{
			score = cnt > 0 ? pow(78.0/(double)cnt, 4.0)*100.0 : 0.0;
			score = score > 100.0 ? 100.0 : score;
			score = score < 1.0 ? 0.0 : score;
		}
		else score = 0;
		printf("%.2lf\n", score);
	}
}
