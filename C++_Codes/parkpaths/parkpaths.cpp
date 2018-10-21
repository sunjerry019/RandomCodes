#include "parkpaths.h"
#include <bits/stdc++.h>
using namespace std;

int cost = 0;
map<char, int> letters;
int pairs = 0;
int pairarr[26][26] = {0};


int parkpaths(string s) {
    int length = s.length();

    for(int i=0; i<length; i++)
    {
        if(letters[s[i]]) letters[s[i]] += 1;
        else letters[s[i]] = 1;

        if(i) {
            int a = min(s[i],s[i-1]) - 'A';
            int b = max(s[i],s[i-1]) - 'A';
            if(!pairarr[a][b])
            {
                pairs++;
                pairarr[a][b] = 1;
            }
        }
    }
    cost += pairs;
    cost += letters.size()*2;
    return cost;
}
