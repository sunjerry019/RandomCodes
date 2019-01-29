#include <bits/stdc++.h>

using namespace std;
int n;
int negonereached = 0;
int negonereachedsec = 0;
vector<int> fuck;

int chainlength(int node, int currLength)
{
    if(fuck[node] == -2) return currLength;
    else if(fuck[node] == -1)
    {
        negonereached = 1;
        fuck[node] = -2;
        return currLength + 1;
    }
    else
    {
        currLength ++;
        int temp = fuck[node];
        fuck[node] = -2;
        return chainlength(temp, currLength);
    }
}

int secondchainlength(int node, int currLength, int visited[])
{
    if(fuck[node] == -2)
    {
        negonereachedsec = negonereached;
        return currLength;
    }
    else if(fuck[node] == -1)
    {
        negonereachedsec = 1;
        return currLength + 1;
    }
    else if(visited[node] == 1 || fuck[node] == 0) return (-3);
    else
    {
        currLength ++;
        visited[node] = 1;
        return secondchainlength(fuck[node], currLength, visited);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d", &temp);
        fuck.push_back(temp);
    }
    int mainChainLength = chainlength(0, 0);
    //cout << mainChainLength << endl << endl;
    int maxlength = 0;
    for(int i=0;i<n;i++)
    {
        if(fuck[i] != -2)
        {
            int v[20005] = {0};
            int length = secondchainlength(i, 0, v);
            //cout << "Now at node " << i << " : " << length << ", Reached -1: " << negonereachedsec << endl;
            //cout << length << endl;
            if(length != -3)
            {
                if(negonereachedsec)
                {
                    maxlength = max(length, maxlength);
                    //cout << i << "th node is now max\n";
                }
            }
            negonereachedsec = 0;
        }
    }
    int total = 0;
    total = (maxlength + mainChainLength);

    printf("\n%d\n", total);
    return 0;
}
