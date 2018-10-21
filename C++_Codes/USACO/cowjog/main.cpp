#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("cowjog.in");
    ofstream out("cowjog.out");
    int n;
    //int cowSpeed[1000000000] = {-1};
    vector<int> cowSpeed;
    vector<int> cowPos;
    in >> n;
    for(int i=0;i<n;i++)
    {
        int temp, temp2;
        in >> temp >> temp2;
        cowPos.push_back(temp);
        cowSpeed.push_back(temp2);
    }
    int total = 1;
    for(int i=(cowSpeed.size()-2);i>=0;i--)
    {
        //out << cowPos[i] << " " << cowSpeed[i] << ", " << cowPos[i+1] << " " << cowSpeed[i+1] << " >> ";
        if(cowSpeed[i] > cowSpeed[i+1])
        {
            cowSpeed[i] = cowSpeed[i+1];
            cowPos[i] = cowPos[i+1] - 1;
        }
        else if(cowSpeed[i] <= cowSpeed[i+1]) total ++;
        else if(cowSpeed[i] == cowSpeed[i+1])
        {
            if(cowPos[i+1] != (cowPos[i]+1)) total ++;
        }
        //out << cowPos[i] << " " << cowSpeed[i] << ", " << cowPos[i+1] << " " << cowSpeed[i+1] << endl;
    }
    out << total << endl;
    return 0;
}
