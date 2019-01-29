#include <iostream>
using namespace std;
int main() {
	int a,b;
	char c;
	bool hero=false;
	cin>>a>>b;
	for(int i=0;i<b;i++) {
		cin>>c;
		if(c=='D') hero=true;
		if(!hero&&c=='>') {
			cout<<"N";
			return 0;
		}
		else if(hero&&c=='<') {
			cout<<"N";
			return 0;
		}
	}
	cout<<"Y";
}
