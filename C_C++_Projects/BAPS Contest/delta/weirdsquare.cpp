#include <iostream>
using namespace std;
int arr[2000][2000];
int main() {
	int inp, cur = 1, seqlen = 1;
	bool down = false;
	cin >> inp;
	for (int a=1;a<=inp;++a) {
		if (down) {
			for (int b=1;b<=seqlen;++b) {
				arr[b-1][a-b] = cur++;
			}
		}
		else {
			for (int b=1;b<=seqlen;++b) {
				arr[a-b][b-1] = cur++;
			}
		}
		down = !down;
		seqlen++;
	}
	seqlen = inp - 1;
	for (int a=1;a<inp;++a) {
		if (down) {
			for (int b=1;b<=seqlen;++b) {
				arr[a+b-1][inp-b] = cur++;
			}
		}
		else {
			for (int b=1;b<=seqlen;++b) {
				arr[inp-b][b+a-1] = cur++;
			}
		}
		down = !down;
		seqlen--;
	}
	for (int a=0;a<inp;++a) {
		for (int b=0;b<inp;++b) {
			if (b) cout << " ";
			cout << arr[a][b];
		}
		cout << "\n";
	}
}
