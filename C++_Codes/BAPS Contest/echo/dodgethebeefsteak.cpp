#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Your Code Here */
    int h,w; cin >> h >> w;
	bool foundStart = false;
	char temp;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> temp;
			if(temp=='>' && foundStart == false){
				cout << 'N';
				return 0;
			}
			if(temp=='D'){
				foundStart = true;
			}
			if(temp == '<' && foundStart == true){
				cout << 'N';
				return 0;
			}
		}
	}
	cout << 'Y';
	return 0;
	/*
	vector<int,int> arr[h+2][w+2];
	char temp;
	pair<int,int> start;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> temp;
			arr[i][j].push_back(mp(temp,0));
			if(temp=='D'){
				start.first = i;
				start.second = j;
			}
		}
	}
	while(true){
		
		if(arr[start.first-1][start.second] == 'V' || arr[start.first][start.second-1] == '>' || arr[start.first][start.second+1] == '<'){
		
		
	}*/
}
