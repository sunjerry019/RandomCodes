#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main() {
    /* Your Code Here */
    int n; cin >> n;
    ll t,a,b,m;
    while(n--){
        cin >> t >> a >> b >> m;
        cout << (a%m + b%m)%m << "\n";
    }
}