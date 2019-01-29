#include <bits/stdc++.h>
#include "lightson.h"
using namespace std;
vector< vector<bool> > arr;
int a, b;
void flat(int N, int M){
	a = N;
	b = M;
	for(int i=0;i<N;i++)
	{
	    vector<bool> tst;
	    for(int j=0;j<M;j++)
	    {
	        
	        tst.push_back(0);
	    }
	    
        arr.push_back(tst);
	}
	return;
}

void setFloor(int N, bool S){
	for (int i = 0; i < b; i++) arr[N][i] = S;
	return;
}

void setUnit(int M, bool S){
	for (int i = 0; i < a; i++) arr[i][M] = S;
	return;
}

int countLights(int N){
	int ct = 0;
	for (int i = 0; i < b; i++) ct += arr[N][i];
	return ct;
}