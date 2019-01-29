#include<stdio.h>

int main(){
	int Height, Width;
	scanf("%d%d ", &Height, &Width);
	if(Height == 1){
		char C; int Derek = 0;
		for(int i = 0; i < Width; i++){
			scanf("%c", &C);
			if(C == '>' && Derek == 0){ printf("N"); return 0; }
			if(C == '<' && Derek == 1){ printf("N"); return 0; }
			if(C == 'D') Derek = 1;
		}
	}
	printf("Y");
	return 0;
}