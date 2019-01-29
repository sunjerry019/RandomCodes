#include <bits/stdc++.h>
using namespace std;
string answer[1000005];
vector <int> v;
vector <string> V;
bool palindrome(string a) {
	if (a.size()%2==1) {
		int mid = (a.size()-1)/2;
		for (int i=0; i<mid; i++) {
			if (a[i] == a[a.size()-i-1]) {
				continue;
			}
			else return 0;
		}
	}
	else {
		int mid = (a.size()/2)-1;
		for (int i=0; i<= mid; i++) {
			if (a[i]==a[a.size()-1-i]) {
				continue;
			}
			else return 0;
		}
	}
	return 1;
}
string looknsay(const string &s) {
	ostringstream r;
	for (int i=0; i!= s.length();) {
		int new_i = s.find_first_not_of(s[i], i+1);
		if (new_i == string::npos) {
			new_i = s.length();
		}
		r << new_i - i << s[i];
		i = new_i;
	}
	return r.str();
}

string reverse(string a) {
	string prev;
	for (int i=0;i<a.size();i+=2) {
		for (int j=0; j<a[i]-48; j++) {
			prev.push_back(a[i+1]);
		}
	}
	if (palindrome(prev)) return prev;
	else return reverse(prev);
}

int main() {
	//freopen("input.txt","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,m=0,d,posmax;
	char b;
	string c,base;
	cin >> b;
	if (b=='a') {
		cin >> c >> d;
		while(d--){
			cin>>t;
			v.push_back(t);
			m=max(m,t);
		}
		answer[0]=c;
		for (int i=0; i<m; i++) {
			answer[i+1] = looknsay(answer[i]);
		}
		for(int i=0;i<v.size();i++){
			cout << answer[v[i]] << "\n";
		}
	}
	else if (b=='b') {
		cin >> d;
		for (int i=0; i<d; i++) {
			cin >> c;
			V.push_back(c);
			if (c.size()>(int)m) {
				m = c.size();
				posmax=i;
			}	
		}
		base = reverse(V[posmax]);
		cout << base << "\n";
		answer[0] = base;
		int i=0,k=0;
		while(answer[i]!=V[posmax]) {
			answer[i+1] = looknsay (answer[i]);
			i++;
		}
		for (int j=0; j<d; j++) {
			k=0;
			while(true) {
				if (answer[k]==V[j]) {
					cout << k << endl;
					break;
				}
				k++;
			}
		}
	}
}
