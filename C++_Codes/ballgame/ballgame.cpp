#include <bits/stdc++.h>

using namespace std;

int ballgame(int n, int l, int d, int h[], int c[])
{
    map<int,int> arr;
    vector<int> height;
    vector<int> coord;
    vector<int> ways;
    for(int i=0;i<n;i++)
    {
        arr[h[i]] = c[i];
    }
    cout << endl;
    for(map<int,int>::iterator it=arr.begin(); it!= arr.end(); ++it)
    {
        height.push_back(it->first);
        coord.push_back(it->second);
        ways.push_back(0);
        //cout << it->first << " " << it->second << endl;
    }
    ways[n-1] = 1;
    for(int i=(n-1);i>=0;i--)
    {
        if(ways[i] >= 1)
        {
            for(int j=(i-1); j>=0;j--)
            {
                if(abs(coord[i] - coord[j]) <= d)
                {
                    ways[j] = ways[j]%1000000007 + ways[i]%1000000007 ;
                    //cout << "at " << i << "," << ways[i] << " plus way to " << j << "," << ways[j] << endl;
                }
                //else cout << "at " << i << "," << ways[i] << " but " << j << "," << ways[j] << " is too far" << endl;
            }
        }
    }

    return ways[0]%1000000007;
}
