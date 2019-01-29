#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int nx = (n-d+1);
    vector<string> patt;
    map<string, pair<int, int> > arrows;
    for(int i=0;i<nx;i++)
    {
        char temp[1005];
        scanf("%s", temp);
        patt.push_back(string(temp));
    }
    for(int i=0;i<nx;i++)
    {
        string starts = patt[i].substr(0,(d-1));
        string ends = patt[i].substr(1, (d-1));
        arrows[starts].second ++;
        arrows[ends].first++;
    }
    char startc, endc;
    for(map<string, pair<int, int> >::iterator it=arrows.begin(); it!=arrows.end(); ++it)
    {
        if(it->second.first < it->second.second) startc = it->first[0];
        if(it->second.first > it->second.second) endc = it->first[it->first.length()-1];
    }
    printf("%c%c\n", startc, endc);
    return 0;
}
